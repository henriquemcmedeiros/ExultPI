#include "header.h"
#include "Dialogo.h"

int vidaAtual(int vida, bool boss);
void minigame1(vida* ptrv);
void minigame2(vida* ptrv);
void minigame3(vida* ptrv);
void minigameHub(int minigame, vida* ptrv);

void minigameHub(int minigame, vida* ptrv, audio* ptra) {
	if (minigame == 1) {
		dialogo(4, ptra);
		minigame1(ptrv, ptra);
		al_play_sample_instance(ptra->inst[1]);
	}
	else if (minigame == 2) {
		minigame2(ptrv, ptra);
		al_play_sample_instance(ptra->inst[1]);
	}
	else if (minigame == 3) {
		minigame3(ptrv, ptra);
		al_play_sample_instance(ptra->inst[1]);
	}
}

int vidaAtual(int vidas, bool boss, audio* ptra)
{
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	image2 = al_load_bitmap("sangue/sangue2.png");
	image3 = al_load_bitmap("sangue/sangue3.png");
	image4 = al_load_bitmap("sangue/sangue1.png");

	if (vidas == 3 && !boss) {
		al_draw_bitmap(image4, 0, 0, 0);
	}
	else if (vidas == 2 && !boss) {
		al_draw_bitmap(image2, 0, 0, 0);

	}
	else if (vidas == 1 && !boss) {
		al_draw_bitmap(image3, 0, 0, 0);
	}

	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);

	if (vidas == 0) {
		al_stop_sample_instance(ptra->inst[0]);
		al_stop_sample_instance(ptra->inst[7]);
		al_play_sample_instance(ptra->inst[3]);
		derrotaM();
		exit(0);
	}
}

void minigame1(vida* ptrv, audio* ptra) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	al_set_sample_instance_gain(ptra->inst[0], 0.1);
	al_play_sample_instance(ptra->inst[6]);
	image = al_load_bitmap("mingame/game1.jpg");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!ptrv->done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_S:
				ptrv->vida--;
				al_stop_sample_instance(ptra->inst[5]);
				al_play_sample_instance(ptra->inst[5]);
				break;
			case ALLEGRO_KEY_V:
				ptrv->done = true;
				al_set_sample_instance_gain(ptra->inst[0], 0.4);
				break;
			case ALLEGRO_KEY_M:
				ptrv->vida--;
				al_stop_sample_instance(ptra->inst[5]);
				al_play_sample_instance(ptra->inst[5]);
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida, false, ptra);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void minigame2(vida* ptrv, audio* ptra) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	al_set_sample_instance_gain(ptra->inst[0], 0.1);
	al_play_sample_instance(ptra->inst[6]);
	image = al_load_bitmap("mingame/game2.jpg");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!ptrv->done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_S:
				ptrv->done = true;
				al_set_sample_instance_gain(ptra->inst[0], 0.4);
				break;
			case ALLEGRO_KEY_V:
				ptrv->vida--;
				al_stop_sample_instance(ptra->inst[5]);
				al_play_sample_instance(ptra->inst[5]);
				break;
			case ALLEGRO_KEY_M:
				ptrv->vida--;
				al_stop_sample_instance(ptra->inst[5]);
				al_play_sample_instance(ptra->inst[5]);
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida, false, ptra);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void minigame3(vida* ptrv, audio* ptra) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	al_set_sample_instance_gain(ptra->inst[0], 0.1);
	al_play_sample_instance(ptra->inst[6]);
	image = al_load_bitmap("mingame/game3.jpg");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!ptrv->done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_S:
				ptrv->vida--;
				al_stop_sample_instance(ptra->inst[5]);
				al_play_sample_instance(ptra->inst[5]);
				break;
			case ALLEGRO_KEY_V:
				ptrv->vida--;
				al_stop_sample_instance(ptra->inst[5]);
				al_play_sample_instance(ptra->inst[5]);
				break;
			case ALLEGRO_KEY_M:
				ptrv->done = true;
				al_set_sample_instance_gain(ptra->inst[0], 0.4);
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida, false, ptra);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

int boss(mapa* ptr, vida* ptrv, audio* ptra) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	al_set_sample_instance_gain(ptra->inst[0], 0.1);
	al_play_sample_instance(ptra->inst[7]);
	image = al_load_bitmap("mingame/BOSS.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!ptrv->done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_V:
				ptrv->done = true;
				al_stop_sample_instance(ptra->inst[7]);
				al_set_sample_instance_gain(ptra->inst[0], 0.4);
				break;
			case ALLEGRO_KEY_F:
				ptrv->vida = 0;
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		al_draw_bitmap(image, 0, 0, 0);
		vidaAtual(ptrv->vida, true, ptra);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}