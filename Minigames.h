int vida = 3;

int vidaCom(ALLEGRO_BITMAP* image2, ALLEGRO_BITMAP* image3, ALLEGRO_BITMAP* image4) {

	if (vida == 3) {
		al_draw_bitmap(image4, 0, 0, 0);
	}

	if (vida == 2) {
		al_draw_bitmap(image2, 0, 0, 0);
	}

	if (vida == 1) {
		al_draw_bitmap(image3, 0, 0, 0);
	}

	if (vida == 0) {
		exit(0);
	}

	return vida;
}

int minigame1() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("mingame/game1.jpg");
	image2 = al_load_bitmap("sangue/sangue2.png");
	image3 = al_load_bitmap("sangue/sangue3.png");
	image4 = al_load_bitmap("sangue/sangue1.png");

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
				vida--;
				break;
			case ALLEGRO_KEY_V:
				done = true;
				break;
			case ALLEGRO_KEY_M:
				vida--;
				break;
			}
		}
		vidaCom(image2, image3, image4);
		al_draw_bitmap(image, 170, 65, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4);
	al_destroy_event_queue(event_queue);
}

int minigame2() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("mingame/game1.jpg");
	image2 = al_load_bitmap("sangue/sangue2.png");
	image3 = al_load_bitmap("sangue/sangue3.png");
	image4 = al_load_bitmap("sangue/sangue1.png");

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
			case ALLEGRO_KEY_V:
				vida--;
				break;
			case ALLEGRO_KEY_M:
				vida--;
				break;
			}
		}
		vidaCom(image2, image3, image4);
		al_draw_bitmap(image, 170, 65, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4);
	al_destroy_event_queue(event_queue);
}


int minigame3() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("mingame/game1.jpg");
	image2 = al_load_bitmap("sangue/sangue2.png");
	image3 = al_load_bitmap("sangue/sangue3.png");
	image4 = al_load_bitmap("sangue/sangue1.png");

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
				vida--;
				break;
			case ALLEGRO_KEY_V:
				vida--;
				break;
			case ALLEGRO_KEY_M:
				done = true;
				break;
			}
		}
		vidaCom(image2, image3, image4);
		al_draw_bitmap(image, 170, 65, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4);
	al_destroy_event_queue(event_queue);
}


