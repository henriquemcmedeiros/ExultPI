#include "header.h"
#include "Dialogo.h"

int vidaAtual(int vida);
void minigame1(vida* ptrv);
void minigame2(vida* ptrv);
void minigame3(vida* ptrv);
void minigameHub(int minigame, vida* ptrv);

void minigameHub(int minigame, vida* ptrv) {
	if (minigame == 1) {
		dialog4();
		dialog5();
		minigame1(ptrv);
	}
	else if (minigame == 2) {
		minigame2(ptrv);
	}
	else if (minigame == 3) {
		minigame3(ptrv);
	}
}

int vidaAtual(int vidas)
{
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	image2 = al_load_bitmap("sangue/sangue2.png");
	image3 = al_load_bitmap("sangue/sangue3.png");
	image4 = al_load_bitmap("sangue/sangue1.png");

	if (vidas == 3) {
		al_draw_bitmap(image4, 0, 0, 0);
	}

	if (vidas == 2) {
		al_draw_bitmap(image2, 0, 0, 0);
	}

	if (vidas == 1) {
		al_draw_bitmap(image3, 0, 0, 0);
	}

	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);

	if (vidas == 0) {
		// ADICIONAR MENSAGEM DE DERROTA
		exit(0);
	}
}

void minigame1(vida* ptrv) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

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
				break;
			case ALLEGRO_KEY_V:
				ptrv->done = true;
				break;
			case ALLEGRO_KEY_M:
				ptrv->vida--;
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void minigame2(vida* ptrv) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

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
				break;
			case ALLEGRO_KEY_V:
				ptrv->vida--;
				break;
			case ALLEGRO_KEY_M:
				ptrv->vida--;
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void minigame3(vida* ptrv) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

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
				break;
			case ALLEGRO_KEY_V:
				ptrv->vida--;
				break;
			case ALLEGRO_KEY_M:
				ptrv->done = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}


void boss(vida* ptrv) {
	ptrv->done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("mingame/boss.jpg");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!ptrv->done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{s
			case ALLEGRO_KEY_S:
				ptrv->vida--;
				break;
			case ALLEGRO_KEY_V:
				ptrv->done = true;
				break;
			case ALLEGRO_KEY_M:
				ptrv->vida--;
				break;
			case ALLEGRO_KEY_ESCAPE:
				ptrv->done = true;
				break;
			}
		}
		al_clear_to_color(al_map_rgb(80, 58, 101));
		vidaAtual(ptrv->vida);
		al_draw_bitmap(image, 100, 40, 0);
		al_flip_display();
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}
