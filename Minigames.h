
void minigame1() {
	bool done = false;
	int vida = 3;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("");
	image2 = al_load_bitmap("");
	image3 = al_load_bitmap("");
	image4 = al_load_bitmap("");

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
				//espaço para a função que retira a colisão da cela 2
				done = true;
				break;
			case ALLEGRO_KEY_M:
				vida--;
				break;
			}
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
		al_draw_bitmap(image4, 0, 0, 0);
		al_draw_bitmap(image, 80, 30, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4);
	al_destroy_event_queue(event_queue);
}

void minigame2() {
	bool done = false;
	int vida = 3;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("");
	image2 = al_load_bitmap("");
	image3 = al_load_bitmap("");
	image4 = al_load_bitmap("");

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
				//espaço para a função que retira a colisão da cela 2
				done = true;
				break;
			case ALLEGRO_KEY_M:
				vida--;
				break;
			}
		}
		if (vida == 2) {
			al_draw_bitmap(image2, 0, 0, 0);
		}

		if (vida == 1) {
			al_draw_bitmap(image3, 0, 0, 0);
		}

		if (vida == 0) {
			gameover(0);
		}
		al_draw_bitmap(image4, 0, 0, 0);
		al_draw_bitmap(image, 80, 30, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4);
	al_destroy_event_queue(event_queue);
}


void minigame3() {
	bool done = false;
	int vida = 3;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("");
	image2 = al_load_bitmap("");
	image3 = al_load_bitmap("");
	image4 = al_load_bitmap("");

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
				//espaço para a função que retira a colisão da cela 2
				done = true;
				break;
			case ALLEGRO_KEY_M:
				vida--;
				break;
			}
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
		al_draw_bitmap(image4, 0, 0, 0);
		al_draw_bitmap(image, 80, 30, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4);
	al_destroy_event_queue(event_queue);
}


/*int criarDisplay(void)
{
	int width = 640;
	int height = 480;

	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init())
		return -1;

	display = al_create_display(width, height);

	if (!display)
		return -1;

	minigame1();

	al_destroy_display(display);

	return 0;
}*/