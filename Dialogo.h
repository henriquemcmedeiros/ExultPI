#include "header.h"

void dialogdoor();
void dialogo();
void dialog2();
void dialog3();
void dialog4();
void dialog5();
void dialog6();

void dialogdoor() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("Bitmapsdialogue/dialdoor.jpg");

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
			case ALLEGRO_KEY_X:
				done = true;
				break;
			}
		}
		al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		al_flip_display(); 
	}
	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void dialogo() {
	bool done = false;
	int numDialogos = 2;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;

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
				numDialogos--;
				break;
			case ALLEGRO_KEY_X:
				numDialogos = 0;
				break;
			}
		}
		if (numDialogos == 2) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else {
			done = true;
		}
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);
}

void dialog2() {
	bool done = false;
	int numDialogos = 2;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;

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
				numDialogos--;
				break;
			case ALLEGRO_KEY_X:
				numDialogos = 0;
				break;
			}
		}
		if (numDialogos == 2) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else {
			done = true;
		}
		al_flip_display();
	}

	// ------- Destroys ------
	al_destroy_bitmap(image); 
	al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);
}

void dialog3() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

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
			case ALLEGRO_KEY_X:
				done = true;
				break;
			}
		}
		al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void dialog4() {
	bool done = false;
	int numDialogos = 2;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;

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
				numDialogos--;
				break;
			case ALLEGRO_KEY_X:
				numDialogos = 0;
				break;
			}
		}
		if (numDialogos == 2) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else {
			done = true;
		}
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);
}

void dialog5() {
	bool done = false;
	int numDialogos = 17;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;
	ALLEGRO_BITMAP* image5 = NULL;
	ALLEGRO_BITMAP* image6 = NULL; 
	ALLEGRO_BITMAP* image7 = NULL; 
	ALLEGRO_BITMAP* image8 = NULL; 
	ALLEGRO_BITMAP* image9 = NULL; 
	ALLEGRO_BITMAP* image10 = NULL; 
	ALLEGRO_BITMAP* image11 = NULL; 
	ALLEGRO_BITMAP* image12 = NULL; 
	ALLEGRO_BITMAP* image13 = NULL; 
	ALLEGRO_BITMAP* image14 = NULL;
	ALLEGRO_BITMAP* image15 = NULL; 
	ALLEGRO_BITMAP* image16 = NULL; 
	ALLEGRO_BITMAP* image17 = NULL;

	image = al_load_bitmap("Bitmapsdialogue/dial4.1.jpg");
	image2 = al_load_bitmap("Bitmapsdialogue/dial4.2.jpg");
	image3 = al_load_bitmap("Bitmapsdialogue/dial4.3.1.jpg");
	image4 = al_load_bitmap("Bitmapsdialogue/dial4.3.2.jpg");
	image5 = al_load_bitmap("Bitmapsdialogue/dial4.4.1.jpg");
	image6 = al_load_bitmap("Bitmapsdialogue/dial4.4.2.jpg"); 
	image7 = al_load_bitmap("Bitmapsdialogue/dial4.5.1.jpg");
	image8 = al_load_bitmap("Bitmapsdialogue/dial4.5.2.jpg");
	image9 = al_load_bitmap("Bitmapsdialogue/dial4.6.1.jpg");
	image10 = al_load_bitmap("Bitmapsdialogue/dial4.6.2.jpg");
	image11 = al_load_bitmap("Bitmapsdialogue/dial4.7.1.jpg");
	image12 = al_load_bitmap("Bitmapsdialogue/dial4.7.2.jpg");
	image13 = al_load_bitmap("Bitmapsdialogue/dial4.8.jpg");
	image14 = al_load_bitmap("Bitmapsdialogue/dial4.9.jpg");
	image15 = al_load_bitmap("Bitmapsdialogue/dial4.10.jpg");
	image16 = al_load_bitmap("Bitmapsdialogue/dial4.11.jpg");
	image17 = al_load_bitmap("Bitmapsdialogue/dial4.12.jpg");

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { 
			switch (ev.keyboard.keycode) { 
				case ALLEGRO_KEY_F:
					numDialogos--;
					break; 
				case ALLEGRO_KEY_X:
					numDialogos = 0;
					break;
			}
		}
		
		if (numDialogos == 17) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 16) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 15) {
			al_draw_bitmap(image3, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 14) {
			al_draw_bitmap(image4, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 13) {
			al_draw_bitmap(image5, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 12) {
			al_draw_bitmap(image6, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 11) {
			al_draw_bitmap(image7, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 10) {
			al_draw_bitmap(image8, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 9) {
			al_draw_bitmap(image9, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 8) {
			al_draw_bitmap(image10, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 7) {
			al_draw_bitmap(image11, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 6) {
			al_draw_bitmap(image12, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 5) {
			al_draw_bitmap(image13, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 4) {
			al_draw_bitmap(image14, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 3) {
			al_draw_bitmap(image15, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 2) {
			al_draw_bitmap(image16, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image17, Xdialogo, Ydialogo, 0);
		}
		else {
			done = true;
		}	
		al_flip_display();  
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);
	al_destroy_bitmap(image5); 
	al_destroy_bitmap(image6);
	al_destroy_bitmap(image7);
	al_destroy_bitmap(image8);
	al_destroy_bitmap(image9);
	al_destroy_bitmap(image10);
	al_destroy_bitmap(image11);
	al_destroy_bitmap(image12);
	al_destroy_bitmap(image13);
	al_destroy_bitmap(image14);
	al_destroy_bitmap(image15);
	al_destroy_bitmap(image16);
	al_destroy_bitmap(image17);
	al_destroy_event_queue(event_queue);
}

void dialog6() {
	bool done = false;
	int numDialogos = 13;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;
	ALLEGRO_BITMAP* image3 = NULL;
	ALLEGRO_BITMAP* image4 = NULL;
	ALLEGRO_BITMAP* image5 = NULL;
	ALLEGRO_BITMAP* image6 = NULL;
	ALLEGRO_BITMAP* image7 = NULL;
	ALLEGRO_BITMAP* image8 = NULL;
	ALLEGRO_BITMAP* image9 = NULL;
	ALLEGRO_BITMAP* image10 = NULL;
	ALLEGRO_BITMAP* image11 = NULL;
	ALLEGRO_BITMAP* image12 = NULL;
	ALLEGRO_BITMAP* image13 = NULL;

	image = al_load_bitmap("Bitmapsdialogue/dial5.1.1.jpg");
	image2 = al_load_bitmap("Bitmapsdialogue/dial5.1.2.jpg");
	image3 = al_load_bitmap("Bitmapsdialogue/dial5.2.1.jpg");
	image4 = al_load_bitmap("Bitmapsdialogue/dial5.2.2.jpg");
	image5 = al_load_bitmap("Bitmapsdialogue/dial5.3.1.jpg");
	image6 = al_load_bitmap("Bitmapsdialogue/dial5.3.2.jpg");
	image7 = al_load_bitmap("Bitmapsdialogue/dial5.4.jpg");
	image8 = al_load_bitmap("Bitmapsdialogue/dial5.5.1.jpg");
	image9 = al_load_bitmap("Bitmapsdialogue/dial5.5.2.jpg");
	image10 = al_load_bitmap("Bitmapsdialogue/dial5.6.jpg");
	image11 = al_load_bitmap("Bitmapsdialogue/dial5.7.jpg");
	image12 = al_load_bitmap("Bitmapsdialogue/dial5.8.jpg");
	image13 = al_load_bitmap("Bitmapsdialogue/dial5.9.jpg");

	event_queue = al_create_event_queue(); 
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_F:
				numDialogos--;
				break;
			case ALLEGRO_KEY_X:
				numDialogos = 0;
				break;
			}
		}

		if (numDialogos == 13) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 12) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 11) {
			al_draw_bitmap(image3, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 10) {
			al_draw_bitmap(image4, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 9) {
			al_draw_bitmap(image5, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 8) {
			al_draw_bitmap(image6, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 7) {
			al_draw_bitmap(image7, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 6) {
			al_draw_bitmap(image8, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 5) {
			al_draw_bitmap(image9, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 4) {
			al_draw_bitmap(image10, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 3) {
			al_draw_bitmap(image11, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 2) {
			al_draw_bitmap(image12, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image13, Xdialogo, Ydialogo, 0);
		}
		else {
			done = true;
		}
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);
	al_destroy_bitmap(image5);
	al_destroy_bitmap(image6);
	al_destroy_bitmap(image7);
	al_destroy_bitmap(image8);
	al_destroy_bitmap(image9);
	al_destroy_bitmap(image10);
	al_destroy_bitmap(image11);
	al_destroy_bitmap(image12);
	al_destroy_bitmap(image13);
	al_destroy_event_queue(event_queue);
}

void dialogFinal() {
	bool done = false;
	int numDialogos = 2;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;
	ALLEGRO_BITMAP* image2 = NULL;

	image = al_load_bitmap("Bitmapsdialogue/dialfinal1.jpg");
	image2 = al_load_bitmap("Bitmapsdialogue/dialfinal2.jpg");

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
				numDialogos--;
				break;
			case ALLEGRO_KEY_X:
				numDialogos = 0;
				break;
			}
		}
		if (numDialogos == 2) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else {
			done = true;
		}
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
	al_destroy_event_queue(event_queue);
}

void dialogCheck() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("Bitmapsdialogue/dialcheckmapa3.jpg");

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
			case ALLEGRO_KEY_X:
				done = true;
				break;
			}
		}
		al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}

void dialogAfterBoss() {
	bool done = false;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* image = NULL;

	image = al_load_bitmap("Bitmapsdialogue/dialafterboss.jpg");

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
			case ALLEGRO_KEY_X:
				done = true;
				break;
			}
		}
		al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		al_flip_display();
	}

	// ------ Destroys ------
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
}