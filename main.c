#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>				//incluindo bibliotecas
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

//__________________________________________
//Variaveis globais

ALLEGRO_SAMPLE* trilha_sonora = NULL;
ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;  //instanciar evita conflitos e permite functions a mais
enum KEYS { DOWN, UP, RIGHT, LEFT };




int main(void)
{


	int direcao = UP;
	int width = 600;
	int height = 480;
	int sourceX = 0, sourceY = 0;
	bool done = false, draw = true, active = false;


	float x = width / 2;
	float y = height / 2;





	//declarando variáveis

	bool keys[4] = { false, false, false, false };

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	const float FPS = 50.0;

	if (!al_init())                                          //iniciando allegro
		return -1;

	display = al_create_display(width, height);              //criando display

	if (!display)                                            //teste display
		return -1;

	//-------------------------------------
			//inicializacao de ADDONS e INSTALACOES

	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon(); // iniciando imagem
	al_reserve_samples(15);  //"quantos audios vai ter no jogo"

	ALLEGRO_BITMAP* Player = al_load_bitmap("player.PNG"); /// alocando memoria e inserindo dados 

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);

	ALLEGRO_KEYBOARD_STATE keyState;

	//-------------------------------------
			//criacao de filas

	event_queue = al_create_event_queue();

	trilha_sonora = al_load_sample("trilha-sonora.wav"); //carrega qual arquivo vai tocar
	inst_trilha_sonora = al_create_sample_instance(trilha_sonora); //instancia ela
	al_attach_sample_instance_to_mixer(inst_trilha_sonora, al_get_default_mixer()); //faz com que ela fique num padrao ja definido poupando trabalho
	al_set_sample_instance_playmode(inst_trilha_sonora, ALLEGRO_PLAYMODE_LOOP); //coloca a soundtrack em loop
	al_set_sample_instance_gain(inst_trilha_sonora, 2); // VOLUME
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);

	while (!done)
	{


		ALLEGRO_EVENT ev;									//evento das teclas para MOVIMENTAÇÃO
		al_wait_for_event(event_queue, &ev);
		al_play_sample_instance(inst_trilha_sonora);
		al_get_keyboard_state(&keyState);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)  //para fechar o display ao apertar o X
		{
			done = true;
		}


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			active = true;
			draw = true;
			switch (ev.keyboard.keycode)
			{
<<<<<<< Updated upstream
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_W:
					keys[UP] = true;
					al_stop_sample_instance(inst_passos);
					al_play_sample_instance(inst_passos);
				break;

				case ALLEGRO_KEY_S:
					keys[DOWN] = true;
					al_stop_sample_instance(inst_passos);
					al_play_sample_instance(inst_passos);
					break;

				case ALLEGRO_KEY_A:
					keys[LEFT] = true;
					al_stop_sample_instance(inst_passos);
					al_play_sample_instance(inst_passos);
					break;

				case ALLEGRO_KEY_D:
					keys[RIGHT] = true;
					al_stop_sample_instance(inst_passos);
					al_play_sample_instance(inst_passos);
					break;
					
				}
=======
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				direcao = DOWN;

				break;

			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				direcao = UP;

				break;

			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				direcao = RIGHT;

				break;

			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				direcao = LEFT;

				break;
			default:
				active = false;
				draw = false;
>>>>>>> Stashed changes
			}


			if (active)
			{
<<<<<<< Updated upstream
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_W:
					keys[UP] = false;
					break;

				case ALLEGRO_KEY_S:
					keys[DOWN] = false;
					break;

				case ALLEGRO_KEY_A:
					keys[LEFT] = false;
					break;

				case ALLEGRO_KEY_D:
					keys[RIGHT] = false;
					break;
=======
				sourceX += al_get_bitmap_width(Player) / 3;
			}
			else
				sourceX = 0;


			if (sourceX >= al_get_bitmap_width(Player))
				sourceX = 0;
		}

>>>>>>> Stashed changes


		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{


			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;

			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;

			}


		}



		if (draw) {


			// al_draw_bitmap(Player, x, y, NULL);
			al_draw_bitmap_region(Player, sourceX, direcao * al_get_bitmap_height(Player) / 4, 180, 279, x, y, NULL);
			al_flip_display();
			al_clear_to_color(al_map_rgb(192, 192, 192));
		}

		y -= keys[UP] * 10;
		y += keys[DOWN] * 10;
		x -= keys[LEFT] * 10;
		x += keys[RIGHT] * 10;

	}

	// desenhar sprite 
	//al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(200, 0, 055));  //desenho do SQUARE, posição e cor
	//----------------------------------------
	//FINALIZACOES e DESTROYS

	al_destroy_sample(trilha_sonora);
	al_destroy_sample_instance(inst_trilha_sonora);
	al_destroy_display(display);
	al_destroy_bitmap(Player); // fecha bitmap 

	return 0;
}