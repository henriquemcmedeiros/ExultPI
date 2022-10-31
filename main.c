#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>				//incluindo bibliotecas
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <../../../../../mapas.h>

// ------ Variaveis globais ------
ALLEGRO_SAMPLE* trilha_sonora = NULL;
ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;  //instanciar evita conflitos e permite functions a mais

enum KEYS {UP, DOWN, LEFT, RIGHT};

int main(void)
{
	// Declarando vari�veis
	// Altura e largura da tela
	int width = 640;
	int height = 480;
	
	bool done = false;	
	int pos_x = width / 2;
	int pos_y = height / 2;

	// Mapa
	int mapColumns = 20;
	int tileSize = 32;
	int escolhaMapa = 1;

	bool keys[4] = {false, false, false, false};

	// V�ri�veis do allegro
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* bgSheet = NULL;

	if (!al_init()) {                                        //Teste inicia��o allegro
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


	// ------ Configura��o do nome do display ------
	al_set_window_title(display, "Exult");

	bgSheet = al_load_bitmap("assets/Full.png");			// Puxando os tiles

	// ------ Cria��o de filas ------
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

	
	while (!done)			
	{
		ALLEGRO_EVENT ev;									//evento das teclas para MOVIMENTA��O
		al_wait_for_event(event_queue, &ev);
		al_play_sample_instance(inst_trilha_sonora);

		// Endere�o dos tiles no display
		int linha = 0;
		int coluna = 0;

		// Endere�o do tileset
		int sourceY = 0;
		int sourceX = 0;

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W:
				keys[UP] = true;
			break;

			case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S:
				keys[DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A:
				keys[LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D:
				keys[RIGHT] = true;
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
				done = true;
				break;

			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)  //para fechar o display ao apertar o X
		{
			done = true;                            
		}

		pos_y -= keys[UP] * 16;
		pos_y += keys[DOWN] * 16;
		pos_x -= keys[LEFT] * 16;
		pos_x += keys[RIGHT] * 16;

		int XMAX = 656;
		int XMIN = -16;
		int YMAX = 496;
		int YMIN = -16;

		if (escolhaMapa == 1 && pos_x >= XMAX) {
			escolhaMapa = 2;
			pos_x = 16;
			pos_y = 336;
		}
		if (escolhaMapa == 2 && pos_x <= XMIN) {
			escolhaMapa = 1;
			pos_x = 624;
			pos_y = 336;
		}
		else if (escolhaMapa == 2 && pos_y >= YMAX) {
			escolhaMapa = 3;
			pos_x = 496;
			pos_y = 16;
		}
		if (escolhaMapa == 3 && pos_y <= YMIN) {
			escolhaMapa = 2;
			pos_x = 496;
			pos_y = 464;
		}
		else if (escolhaMapa == 3 && pos_x <= XMIN) {
			escolhaMapa = 4;
			pos_x = 624;
			pos_y = 368;
		}
		if (escolhaMapa == 4 && pos_x >= XMAX) {
			escolhaMapa = 3;
			pos_x = 16;
			pos_y = 368;
		}

		if (escolhaMapa == 4 && pos_y == 336 && pos_x == 240) {
			done = true;
		}

		// Gera mapa1 como padr�o
		int** map = geraMapas(escolhaMapa);

		// Desenha os mapas na tela
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 20; j++) {
				int val = map[i][j];
				sourceX = val / 10;
				sourceY = val % 10;
				al_draw_bitmap_region(bgSheet, tileSize * sourceX, tileSize * sourceY, tileSize, tileSize, coluna, linha, 0);
				coluna += 32;
			}
			linha += 32;
			coluna = 0;
		}

		al_draw_filled_rectangle(pos_x - 16, pos_y - 16, pos_x + 16, pos_y + 16, al_map_rgb(200, 0, 055));  //desenho do SQUARE, posi��o e cor

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		limparMapas(map);
	}

	// ------ FINALIZACOES e DESTROYS ------
	al_destroy_bitmap(bgSheet);
	al_destroy_sample(trilha_sonora);
	al_destroy_sample_instance(inst_trilha_sonora);
	al_destroy_display(display);

	return 0;
}