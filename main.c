#include "header.h"
#include "mapas.h"

// ------ Variaveis globais ------
ALLEGRO_SAMPLE* trilha_sonora = NULL;
ALLEGRO_SAMPLE* passos = NULL;

ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;				//instanciar evita conflitos e permite functions a mais
ALLEGRO_SAMPLE_INSTANCE* inst_passos = NULL;

enum KEYS {UP, DOWN, LEFT, RIGHT};

void movimentos(mapa* ptr, vida* ptrv, movimento* ptrm, ALLEGRO_EVENT ev);

int main(void)
{
	mapa* ptr = (mapa*)malloc(sizeof(mapa));
	vida* ptrv = (vida*)malloc(sizeof(vida));
	movimento* ptrm = (movimento*)malloc(sizeof(movimento));

	// ------ Declarando variáveis ------
	// Altura e largura da tela
	int width = 640;
	int height = 480;
	
	ptr->done = false;
	ptr->pos_x = 288;
	ptr->pos_y = 224;

	ptr->escolhaMapa = 1;
	ptrm->CountDialogo = 0;

	bool tutorialAssistido = false;

	ptrm->minigameAtual = 0;
	int CountMenus = 0;

	ptrv->vida = 3;

	ptrm->direcao = UP;
	int velocidade = 4;
	const float FPS = 60;

	ptrm->draw = true;

	ptrm->keys[0] = false;
	ptrm->keys[1] = false;
	ptrm->keys[2] = false;
	ptrm->keys[3] = false;

	// ------ Váriáveis do allegro ------
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* bgSheet = NULL;							// Mapa
	ALLEGRO_BITMAP* Player = NULL;							// Player
	ALLEGRO_KEYBOARD_STATE keyState;

	if (!al_init()) {                                       // Teste iniciação allegro
		fprintf(stderr, "Falha ao iniciar o Allegro\n");
		return -1;
	}

	// ------ Inicializacao de ADDONS e INSTALACOES ------
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_reserve_samples(15);									 //"quantos audios vai ter no jogo"

	display = al_create_display(width, height);              //criando display

	if (!display) {											 //teste display
		fprintf(stderr, "Falha ao iniciar o display\n");
		return -1;
	}

	// ------ Configuração do nome do display ------
	al_set_window_title(display, "Exult");

	Player = al_load_bitmap("player.png");
	bgSheet = al_load_bitmap("assets/Full.png");			// Puxando os tiles

	// ------ Criação de filas ------
	event_queue = al_create_event_queue();

	if (!event_queue) {
		fprintf(stderr, "Falha ao criar fila de evento\n");	// Teste fila de eventos
		al_destroy_display(display);
		return -1;
	}

	// ------ Trilha sonora ------
	trilha_sonora = al_load_sample("Audios/Trilha sonora/trilha-sonora.wav"); //carrega qual arquivo vai tocar
	inst_trilha_sonora = al_create_sample_instance(trilha_sonora); //instancia ela
	al_attach_sample_instance_to_mixer(inst_trilha_sonora, al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_playmode(inst_trilha_sonora, ALLEGRO_PLAYMODE_LOOP); //coloca a soundtrack em loop
	al_set_sample_instance_gain(inst_trilha_sonora, 0.25); // VOLUME trilha sonora

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	// Gera mapa1 como padrão
	ptr->map = geraMapas(ptr->escolhaMapa);
	
	while (!ptr->done)
	{
		ALLEGRO_EVENT ev;									//evento das teclas para MOVIMENTAÇÃO

		al_wait_for_event(event_queue, &ev);
		al_play_sample_instance(inst_trilha_sonora);
		al_get_keyboard_state(&keyState);

		int sourcePlayerX = 0;
		int sourcePlayerY = 0;
		
		if (!tutorialAssistido) {
			inicioM();
			tutorialM();
			portasLogicasM();
			tutorialAssistido = true;
		}

		// Movimentação do personagem principal
		movimentos(ptr, ptrv, ptrm, ev);

		if (sourcePlayerX >= al_get_bitmap_width(Player)) {
			sourcePlayerX = 0;
		}

		// Posição e velocidade do personagem
		ptr->pos_y -= ptrm->keys[UP] * velocidade;
		ptr->pos_y += ptrm->keys[DOWN] * velocidade;
		ptr->pos_x -= ptrm->keys[LEFT] * velocidade;
		ptr->pos_x += ptrm->keys[RIGHT] * velocidade;

		// Colisões
		ptrm->minigameAtual = colisao(ptr, ptr->escolhaMapa, ptrm->minigameAtual, ptrv);

		// Troca de mapas
		trocarMapas(ptr);

		// Desenha o mapa
		desenhaMapas(ptr, bgSheet);
		
		if (ptrm->draw) {
			al_draw_bitmap_region(Player, sourcePlayerX, ptrm->direcao * al_get_bitmap_height(Player) / 4, 26, 32, ptr->pos_x, ptr->pos_y, NULL);
			al_flip_display();
		}

		// ------ Diálogos ------
		dialogHub(ptr, ptrv, ptrm, ptrm->CountDialogo);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	// ------ FINALIZACOES e DESTROYS ------
	free(ptrv);
	free(ptr);
	//limparMapas(ptr->map);
	al_destroy_bitmap(bgSheet);
	al_destroy_bitmap(Player);
	al_destroy_sample(trilha_sonora);
	al_destroy_sample_instance(inst_trilha_sonora);
	al_destroy_display(display);

	return 0;
}

void movimentos(mapa* ptr, vida* ptrv, movimento* ptrm, ALLEGRO_EVENT ev) {
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		ptrm->draw = true;
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W:
			ptrm->keys[UP] = true;
			ptrm->direcao = DOWN;
			break;
		case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S:
			ptrm->keys[DOWN] = true;
			ptrm->direcao = UP;
			break;
		case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A:
			ptrm->keys[LEFT] = true;
			ptrm->direcao = LEFT;
			break;
		case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D:
			ptrm->keys[RIGHT] = true;
			ptrm->direcao = RIGHT;
			break;
		case ALLEGRO_KEY_F2:
			ptrm->minigameAtual = 4;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W:
			ptrm->keys[UP] = false;
			break;
		case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S:
			ptrm->keys[DOWN] = false;
			break;
		case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A:
			ptrm->keys[LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D:
			ptrm->keys[RIGHT] = false;
			break;
		case ALLEGRO_KEY_ESCAPE:
			ptr->done = true;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)  //para fechar o display ao apertar o X
	{
		ptr->done = true;
	}
}