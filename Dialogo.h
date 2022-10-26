
int dialogo() {
	bool done = false;
	bool done2 = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue2 = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;


	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("Bitmapsdialogue/dialethan1.jpg");
	image2 = al_load_bitmap("Bitmapsdialogue/dialethan1.1.jpg");

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
		al_draw_bitmap(image, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue2 = al_create_event_queue();
	al_register_event_source(event_queue2, al_get_keyboard_event_source());

	while (!done2)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue2, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_F:
				done2 = true;
				break;
			}
		}
		al_draw_bitmap(image2, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}


	al_destroy_bitmap(image); al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);


	return 0;
}

int dialog2() {
	bool done = false;
	bool done2 = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue2 = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;


	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("Bitmapsdialogue/dialethan2.jpg");
	image2 = al_load_bitmap("Bitmapsdialogue/dialethan2.1.jpg");

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
		al_draw_bitmap(image, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue2 = al_create_event_queue();
	al_register_event_source(event_queue2, al_get_keyboard_event_source());

	while (!done2)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue2, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_F:
				done2 = true;
				break;
			}
		}
		al_draw_bitmap(image2, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}


	al_destroy_bitmap(image); al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);
}

int dialog3() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("Bitmapsdialogue/dialethan3.jpg");

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
		al_draw_bitmap(image, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);

}

int dialog4() {
	bool done = false;
	bool done2 = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue2 = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;


	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("Bitmapsdialogue/dialethan4.jpg");
	image2 = al_load_bitmap("Bitmapsdialogue/dialethan4.1.jpg");

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
		al_draw_bitmap(image, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue2 = al_create_event_queue();
	al_register_event_source(event_queue2, al_get_keyboard_event_source());

	while (!done2)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue2, &ev);


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_F:
				done2 = true;
				break;
			}
		}
		al_draw_bitmap(image2, 27, 300, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}


	al_destroy_bitmap(image); al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);
}

int dialog5() {
	bool done = false, done2 = false, done3 = false, done4 = false, done5 = false, done6 = false, done7 = false, done8 = false, done9 = false, done10 = false, done11 = false, done12 = false, done13 = false, done14 = false, done15 = false, done16 = false, done17 = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL; ALLEGRO_EVENT_QUEUE* event_queue2 = NULL; ALLEGRO_EVENT_QUEUE* event_queue3 = NULL; ALLEGRO_EVENT_QUEUE* event_queue4 = NULL; ALLEGRO_EVENT_QUEUE* event_queue5 = NULL; ALLEGRO_EVENT_QUEUE* event_queue6 = NULL; ALLEGRO_EVENT_QUEUE* event_queue7 = NULL; ALLEGRO_EVENT_QUEUE* event_queue8 = NULL; ALLEGRO_EVENT_QUEUE* event_queue9 = NULL; ALLEGRO_EVENT_QUEUE* event_queue10 = NULL; ALLEGRO_EVENT_QUEUE* event_queue11 = NULL; ALLEGRO_EVENT_QUEUE* event_queue12 = NULL; ALLEGRO_EVENT_QUEUE* event_queue13 = NULL; ALLEGRO_EVENT_QUEUE* event_queue14 = NULL; ALLEGRO_EVENT_QUEUE* event_queue15 = NULL; ALLEGRO_EVENT_QUEUE* event_queue16 = NULL; ALLEGRO_EVENT_QUEUE* event_queue17 = NULL;
	ALLEGRO_BITMAP* image = NULL; ALLEGRO_BITMAP* image2 = NULL; ALLEGRO_BITMAP* image3 = NULL; ALLEGRO_BITMAP* image4 = NULL; ALLEGRO_BITMAP* image5 = NULL; ALLEGRO_BITMAP* image6 = NULL; ALLEGRO_BITMAP* image7 = NULL; ALLEGRO_BITMAP* image8 = NULL; ALLEGRO_BITMAP* image9 = NULL; ALLEGRO_BITMAP* image10 = NULL; ALLEGRO_BITMAP* image11 = NULL; ALLEGRO_BITMAP* image12 = NULL; ALLEGRO_BITMAP* image13 = NULL; ALLEGRO_BITMAP* image14 = NULL; ALLEGRO_BITMAP* image15 = NULL; ALLEGRO_BITMAP* image16 = NULL; ALLEGRO_BITMAP* image17 = NULL;


	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("Bitmapsdialogue/dial4.1.jpg"); image2 = al_load_bitmap("Bitmapsdialogue/dial4.2.jpg"); image3 = al_load_bitmap("Bitmapsdialogue/dial4.3.1.jpg"); image4 = al_load_bitmap("Bitmapsdialogue/dial4.3.2.jpg"); image5 = al_load_bitmap("Bitmapsdialogue/dial4.4.1.jpg"); image6 = al_load_bitmap("Bitmapsdialogue/dial4.4.2.jpg"); image7 = al_load_bitmap("Bitmapsdialogue/dial4.5.1.jpg"); image8 = al_load_bitmap("Bitmapsdialogue/dial4.5.2.jpg"); image9 = al_load_bitmap("Bitmapsdialogue/dial4.6.1.jpg"); image10 = al_load_bitmap("Bitmapsdialogue/dial4.6.2.jpg"); image11 = al_load_bitmap("Bitmapsdialogue/dial4.7.1.jpg"); image12 = al_load_bitmap("Bitmapsdialogue/dial4.7.2.jpg"); image13 = al_load_bitmap("Bitmapsdialogue/dial4.8.jpg"); image14 = al_load_bitmap("Bitmapsdialogue/dial4.9.jpg"); image15 = al_load_bitmap("Bitmapsdialogue/dial4.10.jpg"); image16 = al_load_bitmap("Bitmapsdialogue/dial4.11.jpg"); image17 = al_load_bitmap("Bitmapsdialogue/dial4.12.jpg");

	event_queue = al_create_event_queue(); al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done = true; break; } }
																							  al_draw_bitmap(image, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue2 = al_create_event_queue(); al_register_event_source(event_queue2, al_get_keyboard_event_source());

	while (!done2)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue2, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done2 = true; break; } }
																							  al_draw_bitmap(image2, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue3 = al_create_event_queue(); al_register_event_source(event_queue3, al_get_keyboard_event_source());

	while (!done3)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue3, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done3 = true; break; } }
																							  al_draw_bitmap(image3, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue4 = al_create_event_queue(); al_register_event_source(event_queue4, al_get_keyboard_event_source());

	while (!done4)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue4, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done4 = true; break; } }
																							  al_draw_bitmap(image4, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue5 = al_create_event_queue(); al_register_event_source(event_queue5, al_get_keyboard_event_source());

	while (!done5)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue5, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done5 = true; break; } }
																							  al_draw_bitmap(image5, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue6 = al_create_event_queue(); al_register_event_source(event_queue6, al_get_keyboard_event_source());

	while (!done6)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue6, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done6 = true; break; } }
																							  al_draw_bitmap(image6, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue7 = al_create_event_queue(); al_register_event_source(event_queue7, al_get_keyboard_event_source());

	while (!done7)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue7, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done7 = true; break; } }
																							  al_draw_bitmap(image7, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue8 = al_create_event_queue(); al_register_event_source(event_queue8, al_get_keyboard_event_source());

	while (!done8)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue8, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done8 = true; break; } }
																							  al_draw_bitmap(image8, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue9 = al_create_event_queue(); al_register_event_source(event_queue9, al_get_keyboard_event_source());

	while (!done9)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue9, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done9 = true; break; } }
																							  al_draw_bitmap(image9, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue10 = al_create_event_queue(); al_register_event_source(event_queue10, al_get_keyboard_event_source());

	while (!done10)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue10, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done10 = true; break; } }
																							  al_draw_bitmap(image10, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue11 = al_create_event_queue(); al_register_event_source(event_queue11, al_get_keyboard_event_source());

	while (!done11)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue11, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done11 = true; break; } }
																							  al_draw_bitmap(image11, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue12 = al_create_event_queue(); al_register_event_source(event_queue12, al_get_keyboard_event_source());

	while (!done12)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue12, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done12 = true; break; } }
																							  al_draw_bitmap(image12, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue13 = al_create_event_queue(); al_register_event_source(event_queue13, al_get_keyboard_event_source());

	while (!done13)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue13, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done13 = true; break; } }
																							  al_draw_bitmap(image13, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue14 = al_create_event_queue(); al_register_event_source(event_queue14, al_get_keyboard_event_source());

	while (!done14)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue14, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done14 = true; break; } }
																							  al_draw_bitmap(image14, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue15 = al_create_event_queue(); al_register_event_source(event_queue15, al_get_keyboard_event_source());

	while (!done15)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue15, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done15 = true; break; } }
																							  al_draw_bitmap(image15, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue16 = al_create_event_queue(); al_register_event_source(event_queue16, al_get_keyboard_event_source());

	while (!done16)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue16, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done16 = true; break; } }
																							  al_draw_bitmap(image16, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue17 = al_create_event_queue(); al_register_event_source(event_queue17, al_get_keyboard_event_source());

	while (!done17)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue17, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done17 = true; break; } }
																							  al_draw_bitmap(image17, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}




	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4); al_destroy_bitmap(image5); al_destroy_bitmap(image6); al_destroy_bitmap(image7); al_destroy_bitmap(image8); al_destroy_bitmap(image9); al_destroy_bitmap(image10); al_destroy_bitmap(image11); al_destroy_bitmap(image12); al_destroy_bitmap(image13); al_destroy_bitmap(image14); al_destroy_bitmap(image15); al_destroy_bitmap(image16); al_destroy_bitmap(image17);
	al_destroy_event_queue(event_queue); al_destroy_event_queue(event_queue2); al_destroy_event_queue(event_queue3); al_destroy_event_queue(event_queue4); al_destroy_event_queue(event_queue5); al_destroy_event_queue(event_queue6); al_destroy_event_queue(event_queue7); al_destroy_event_queue(event_queue8); al_destroy_event_queue(event_queue9); al_destroy_event_queue(event_queue10); al_destroy_event_queue(event_queue11); al_destroy_event_queue(event_queue12); al_destroy_event_queue(event_queue13); al_destroy_event_queue(event_queue14); al_destroy_event_queue(event_queue15); al_destroy_event_queue(event_queue16); al_destroy_event_queue(event_queue17);
}

int dialog6() {
	bool done = false, done2 = false, done3 = false, done4 = false, done5 = false, done6 = false, done7 = false, done8 = false, done9 = false, done10 = false, done11 = false, done12 = false, done13 = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL; ALLEGRO_EVENT_QUEUE* event_queue2 = NULL; ALLEGRO_EVENT_QUEUE* event_queue3 = NULL; ALLEGRO_EVENT_QUEUE* event_queue4 = NULL; ALLEGRO_EVENT_QUEUE* event_queue5 = NULL; ALLEGRO_EVENT_QUEUE* event_queue6 = NULL; ALLEGRO_EVENT_QUEUE* event_queue7 = NULL; ALLEGRO_EVENT_QUEUE* event_queue8 = NULL; ALLEGRO_EVENT_QUEUE* event_queue9 = NULL; ALLEGRO_EVENT_QUEUE* event_queue10 = NULL; ALLEGRO_EVENT_QUEUE* event_queue11 = NULL; ALLEGRO_EVENT_QUEUE* event_queue12 = NULL; ALLEGRO_EVENT_QUEUE* event_queue13 = NULL;
	ALLEGRO_BITMAP* image = NULL; ALLEGRO_BITMAP* image2 = NULL; ALLEGRO_BITMAP* image3 = NULL; ALLEGRO_BITMAP* image4 = NULL; ALLEGRO_BITMAP* image5 = NULL; ALLEGRO_BITMAP* image6 = NULL; ALLEGRO_BITMAP* image7 = NULL; ALLEGRO_BITMAP* image8 = NULL; ALLEGRO_BITMAP* image9 = NULL; ALLEGRO_BITMAP* image10 = NULL; ALLEGRO_BITMAP* image11 = NULL; ALLEGRO_BITMAP* image12 = NULL; ALLEGRO_BITMAP* image13 = NULL;

	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("Bitmapsdialogue/dial5.1.1.jpg"); image2 = al_load_bitmap("Bitmapsdialogue/dial5.1.2.jpg"); image3 = al_load_bitmap("Bitmapsdialogue/dial5.2.1.jpg"); image4 = al_load_bitmap("Bitmapsdialogue/dial5.2.2.jpg"); image5 = al_load_bitmap("Bitmapsdialogue/dial5.3.1.jpg"); image6 = al_load_bitmap("Bitmapsdialogue/dial5.3.2.jpg"); image7 = al_load_bitmap("Bitmapsdialogue/dial5.4.jpg"); image8 = al_load_bitmap("Bitmapsdialogue/dial5.5.1.jpg"); image9 = al_load_bitmap("Bitmapsdialogue/dial5.5.2.jpg"); image10 = al_load_bitmap("Bitmapsdialogue/dial5.6.jpg"); image11 = al_load_bitmap("Bitmapsdialogue/dial5.7.jpg"); image12 = al_load_bitmap("Bitmapsdialogue/dial5.8.jpg"); image13 = al_load_bitmap("Bitmapsdialogue/dial5.9.jpg");

	event_queue = al_create_event_queue(); al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done = true; break; } }
																							  al_draw_bitmap(image, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue2 = al_create_event_queue(); al_register_event_source(event_queue2, al_get_keyboard_event_source());

	while (!done2)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue2, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done2 = true; break; } }
																							  al_draw_bitmap(image2, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue3 = al_create_event_queue(); al_register_event_source(event_queue3, al_get_keyboard_event_source());

	while (!done3)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue3, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done3 = true; break; } }
																							  al_draw_bitmap(image3, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue4 = al_create_event_queue(); al_register_event_source(event_queue4, al_get_keyboard_event_source());

	while (!done4)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue4, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done4 = true; break; } }
																							  al_draw_bitmap(image4, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue5 = al_create_event_queue(); al_register_event_source(event_queue5, al_get_keyboard_event_source());

	while (!done5)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue5, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done5 = true; break; } }
																							  al_draw_bitmap(image5, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue6 = al_create_event_queue(); al_register_event_source(event_queue6, al_get_keyboard_event_source());

	while (!done6)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue6, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done6 = true; break; } }
																							  al_draw_bitmap(image6, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue7 = al_create_event_queue(); al_register_event_source(event_queue7, al_get_keyboard_event_source());

	while (!done7)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue7, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done7 = true; break; } }
																							  al_draw_bitmap(image7, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue8 = al_create_event_queue(); al_register_event_source(event_queue8, al_get_keyboard_event_source());

	while (!done8)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue8, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done8 = true; break; } }
																							  al_draw_bitmap(image8, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue9 = al_create_event_queue(); al_register_event_source(event_queue9, al_get_keyboard_event_source());

	while (!done9)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue9, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done9 = true; break; } }
																							  al_draw_bitmap(image9, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue10 = al_create_event_queue(); al_register_event_source(event_queue10, al_get_keyboard_event_source());

	while (!done10)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue10, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done10 = true; break; } }
																							  al_draw_bitmap(image10, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue11 = al_create_event_queue(); al_register_event_source(event_queue11, al_get_keyboard_event_source());

	while (!done11)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue11, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done11 = true; break; } }
																							  al_draw_bitmap(image11, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue12 = al_create_event_queue(); al_register_event_source(event_queue12, al_get_keyboard_event_source());

	while (!done12)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue12, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done12 = true; break; } }
																							  al_draw_bitmap(image12, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	event_queue13 = al_create_event_queue(); al_register_event_source(event_queue13, al_get_keyboard_event_source());

	while (!done13)
	{
		ALLEGRO_EVENT ev; al_wait_for_event(event_queue13, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { switch (ev.keyboard.keycode) { case ALLEGRO_KEY_F:done13 = true; break; } }
																							  al_draw_bitmap(image13, 27, 300, 0); al_flip_display(); al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(image); al_destroy_bitmap(image2); al_destroy_bitmap(image3); al_destroy_bitmap(image4); al_destroy_bitmap(image5); al_destroy_bitmap(image6); al_destroy_bitmap(image7); al_destroy_bitmap(image8); al_destroy_bitmap(image9); al_destroy_bitmap(image10); al_destroy_bitmap(image11); al_destroy_bitmap(image12); al_destroy_bitmap(image13);
	al_destroy_event_queue(event_queue); al_destroy_event_queue(event_queue2); al_destroy_event_queue(event_queue3); al_destroy_event_queue(event_queue4); al_destroy_event_queue(event_queue5); al_destroy_event_queue(event_queue6); al_destroy_event_queue(event_queue7); al_destroy_event_queue(event_queue8); al_destroy_event_queue(event_queue9); al_destroy_event_queue(event_queue10); al_destroy_event_queue(event_queue11); al_destroy_event_queue(event_queue12); al_destroy_event_queue(event_queue13);
}



