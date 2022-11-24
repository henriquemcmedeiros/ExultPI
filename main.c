#include "header.h"
#include "mapas.h"

// ------ Variaveis globais ------
ALLEGRO_SAMPLE* trilha_sonora = NULL;
ALLEGRO_SAMPLE* passos = NULL;

ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;				//instanciar evita conflitos e permite functions a mais
ALLEGRO_SAMPLE_INSTANCE* inst_passos = NULL;

enum KEYS {UP, DOWN, LEFT, RIGHT};

int main(void)
{
	mapa *ptr = (mapa*)malloc(sizeof(mapa));

	// Declarando variáveis
	// Altura e largura da tela
	int width = 640;
	int height = 480;
	
	ptr->done = false;
	ptr->pos_x = 288;
	ptr->pos_y = 224;

	// Mapa
	int mapColumns = 20;
	int mapRows = 15;
	int tileSize = 32;
	ptr->escolhaMapa = 1;

	int minigameAtual = 0;
	int contadorMenus = 0;
	int CountDialogo = 0;
	
	vida* ptrv = (vida*)malloc(sizeof(vida));

	ptrv->vida = 3;

	int direcao;
	int velocidade = 4;

	bool keys[4] = {false, false, false, false};

	// Váriáveis do allegro
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* bgSheet = NULL;							 //Mapa
	// ------ Menus ------
	ALLEGRO_BITMAP* inicio = NULL;
	ALLEGRO_BITMAP* tutorial = NULL;
	ALLEGRO_BITMAP* portasLogicas = NULL;
	ALLEGRO_BITMAP* vitoria = NULL;
	ALLEGRO_BITMAP* derrota = NULL;

	if (!al_init()) {                                        //Teste iniciação allegro
		fprintf(stderr, "Falha ao iniciar o Allegro\n");
		return -1;
	}

	// ------ Inicializacao de ADDONS e INSTALACOES ------
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_reserve_samples(15);									//"quantos audios vai ter no jogo"

	display = al_create_display(width, height);              //criando display

	if (!display) {											 //teste display
		fprintf(stderr, "Falha ao iniciar o display\n");
		return -1;
	}

	// ------ Configuração do nome do display ------
	al_set_window_title(display, "Exult");
	
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
	al_set_sample_instance_gain(inst_trilha_sonora, 0); // VOLUME trilha sonora

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	// Gera mapa1 como padrão
	ptr->map = geraMapas(ptr->escolhaMapa);
	
	while (!ptr->done)
	{
		ALLEGRO_EVENT ev;									//evento das teclas para MOVIMENTAÇÃO

		al_wait_for_event(event_queue, &ev);
		al_play_sample_instance(inst_trilha_sonora);

		// Endereço dos tiles no display
		int linha = 0;
		int coluna = 0;

		// Endereço do tileset
		int sourceY = 0;
		int sourceX = 0;

		if (contadorMenus == 0) {
			inicioM();
			contadorMenus++;
		}
		if (contadorMenus == 1) {
			tutorialM();
			contadorMenus++;
		}
		if (contadorMenus == 2)
		{
			portasLogicasM();
			contadorMenus++;
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W:
				keys[UP] = true;
				direcao = UP;
				break;
			case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S:
				keys[DOWN] = true;
				direcao = DOWN;
				break;
			case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A:
				keys[LEFT] = true;
				direcao = LEFT;
				break;
			case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D:
				keys[RIGHT] = true;
				direcao = RIGHT;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D:
				keys[RIGHT] = false;
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

		// Posição e velocidade do personagem
		ptr->pos_y -= keys[UP] * velocidade;
		ptr->pos_y += keys[DOWN] * velocidade;
		ptr->pos_x -= keys[LEFT] * velocidade;
		ptr->pos_x += keys[RIGHT] * velocidade;	

		// Colisões
		minigameAtual = colisao(ptr, ptr->escolhaMapa, minigameAtual, ptrv);

		// Troca de mapas
		trocarMapas(ptr);

		// Desenha os mapas na tela
		for (int i = 0; i < mapRows; i++) {
			for (int j = 0; j < mapColumns; j++) {
				int val = ptr->map[i][j];
				sourceX = val / 10;
				sourceY = val % 10;
				al_draw_bitmap_region(bgSheet, tileSize * sourceX, tileSize * sourceY, tileSize, tileSize, coluna, linha, 0);
				coluna += 32;
			}
			linha += 32;
			coluna = 0;
		}
		al_draw_filled_rectangle(ptr->pos_x, ptr->pos_y, ptr->pos_x + 32, ptr->pos_y + 32, al_map_rgb(200, 0, 055));  //desenho do SQUARE, posição e cor


		// ------ DIALOGOS GAMBIARRA ------
		if (CountDialogo == 0) {
			dialogo();
			CountDialogo++;
		}
		else if (CountDialogo == 1 && ptr->pos_x == 544) {
			dialog2();
			CountDialogo++;
		}
		else if (CountDialogo == 2 && ptr->pos_x == 32 && ptr->escolhaMapa == 2) {
			dialog3();
			CountDialogo++;
		}
		else if (CountDialogo == 3 && ptr->pos_y == 416 && ptr->escolhaMapa == 2) {
			ptr->pos_y = min(384, ptr->pos_y);
			dialogCheck();
		}
		else if (minigameAtual == 3 && CountDialogo == 3) {
			CountDialogo++;
		}
		else if (CountDialogo == 4 && (ptr->pos_x == 416 || ptr->pos_y == 192) && ptr->escolhaMapa == 3) {
			dialog6();
			CountDialogo++;
		}
		else if (CountDialogo == 5 && ptr->pos_x == 576 && ptr->escolhaMapa == 4) {
			dialogFinal();
			CountDialogo++;
		}
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	// ------ FINALIZACOES e DESTROYS ------
	limparMapas(ptr->map);
	free(ptr);
	al_destroy_bitmap(bgSheet);
	al_destroy_bitmap(inicio);
	al_destroy_bitmap(tutorial);
	al_destroy_bitmap(portasLogicas);
	al_destroy_bitmap(vitoria);
	al_destroy_bitmap(derrota);
	al_destroy_sample(trilha_sonora);
	al_destroy_sample_instance(inst_trilha_sonora);
	al_destroy_display(display);

	return 0;
}