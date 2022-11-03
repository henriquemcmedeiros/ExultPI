#include <../../../../../header.h>
#include <../../../../../mapas.h>

// ------ Variaveis globais ------
ALLEGRO_SAMPLE* trilha_sonora = NULL;
ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;  //instanciar evita conflitos e permite functions a mais

enum KEYS {UP, DOWN, LEFT, RIGHT};

bool colisao(int x, int y, int paredeX, int paredeY, int colisaoX, int colisaoY);

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
	int tileSize = 32;
	ptr->escolhaMapa = 1;
	
	// Bordas do display
	int XMAX = 656;
	int XMIN = -16;
	int YMAX = 496;
	int YMIN = -16;

	int direcao;
	int velocidade = 4;

	bool keys[4] = {false, false, false, false};

	// Váriáveis do allegro
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* bgSheet = NULL;

	if (!al_init()) {                                        //Teste iniciação allegro
		fprintf(stderr, "Falha ao iniciar o Allegro\n");
		return -1;
	}
		  
	display = al_create_display(width, height);              //criando display
		 
	if (!display) {											 //teste display
		fprintf(stderr, "Falha ao iniciar o display\n");
		return -1;
	}

	// ------ Inicializacao de ADDONS e INSTALACOES ------
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_reserve_samples(15);									//"quantos audios vai ter no jogo"

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

		// Endereço dos tiles no display
		int linha = 0;
		int coluna = 0;

		// Endereço do tileset
		int sourceY = 0;
		int sourceX = 0;

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
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

		int aux = (ptr->pos_x / 32);
		int auy = (ptr->pos_y / 32);

		int valU = 67;
		int valD = 67;
		int valL = 67;
		int valR = 67;

		if (ptr->pos_y > 32 && ptr->pos_y < height - 32 && auy < 15 && aux < 20) {
			valU = ptr->map[auy][aux];
			valD = ptr->map[auy + 1][aux];
		}
		if (ptr->pos_x > 32 && ptr->pos_x < width - 32 && auy < 15 && aux < 20) {
			valL = ptr->map[auy][aux];
			valR = ptr->map[auy][aux + 1];
		}

		if (valU != 67 && direcao == UP) {
			// UP
			ptr->pos_y += velocidade;
		}
		if (valD != 67 && direcao == DOWN) {
			// DOWN
			ptr->pos_y -= velocidade;
		}
		if (valL != 67 && direcao == LEFT) {
			// LEFT
			ptr->pos_x += velocidade;
		}
		if (valR != 67 && direcao == RIGHT) {
			// RIGHT
			ptr->pos_x -= velocidade;
		}

		// Troca de mapas
		trocarMapas(ptr);

		// Desenha os mapas na tela
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 20; j++) {
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

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	// ------ FINALIZACOES e DESTROYS ------
	limparMapas(ptr->map);
	free(ptr);
	al_destroy_bitmap(bgSheet);
	al_destroy_sample(trilha_sonora);
	al_destroy_sample_instance(inst_trilha_sonora);
	al_destroy_display(display);

	return 0;
}

bool colisao(int x, int y, int paredeX, int paredeY, int colisaoX, int colisaoY) {
	if (x + colisaoX < paredeX || x > colisaoX + paredeX || y + colisaoY < paredeY || y > colisaoY + paredeY) {
		return false;
	}
	else { // UP, DOWN, LEFT, RIGHT
		return true;
	}
}