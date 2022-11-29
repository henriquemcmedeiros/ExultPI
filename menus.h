#include "header.h"

void inicioM() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("menus/inicio.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			done = true;
		}
		al_draw_bitmap(image, 0, 0, 0);
		al_flip_display();
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void tutorialM() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("menus/tutorial.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_F:
				done = true;
				break;
			}
		}
		al_draw_bitmap(image, 0, 0, 0);
		al_flip_display();
	}
	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void portasLogicasM() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("menus/portasLogicas.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_F:
				done = true;
				break;
			}
		}
		if (!done) {
			al_draw_bitmap(image, 0, 0, 0);
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void vitoriaM(){
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("menus/vitoria.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			done = true;
		}
		if (!done) {
			al_draw_bitmap(image, 0, 0, 0);
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void derrotaM() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	
	image = al_load_bitmap("menus/derrota.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			done = true;
		}
		if (!done) {
			al_draw_bitmap(image, 0, 0, 0);
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void readyM() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("menus/ready.png");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_S:
				done = true;
				break;
			case ALLEGRO_KEY_N:
				portasLogicasM();
				done = true;
				break;
			}
		}
		if (!done) {
			al_draw_bitmap(image, 0, 0, 0);
			al_flip_display();
		}
	}
	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}
