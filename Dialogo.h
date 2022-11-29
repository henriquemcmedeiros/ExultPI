#include "header.h"

void dialogo(int CountDialogo);

void dialogo(int CountDialogo, audio* ptra) {
	bool done = false;
	int numDialogos = 0;
	int quantDialogos = 1;

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
	ALLEGRO_BITMAP* image18 = NULL;
	ALLEGRO_BITMAP* image19 = NULL;

	if (CountDialogo == 1) {
		// Inicial
		quantDialogos = 2;
		image = al_load_bitmap("Bitmapsdialogue/dialethan1.jpg");
		image2 = al_load_bitmap("Bitmapsdialogue/dialethan1.1.jpg");
	}
	else if (CountDialogo == 2) {
		// Corredor sala 1
		quantDialogos = 2;
		image = al_load_bitmap("Bitmapsdialogue/dialethan2.jpg");
		image2 = al_load_bitmap("Bitmapsdialogue/dialethan2.1.jpg");
	}
	else if (CountDialogo == 3) {
		// Corredor sala 2
		quantDialogos = 1;
		image = al_load_bitmap("Bitmapsdialogue/dialethan3.jpg");
	}
	else if (CountDialogo == 4) {
		// Pré-minigame
		quantDialogos = 19;
		image = al_load_bitmap("Bitmapsdialogue/dialethan4.jpg");
		image2 = al_load_bitmap("Bitmapsdialogue/dialethan4.1.jpg");
		image3 = al_load_bitmap("Bitmapsdialogue/dial4.1.jpg");
		image4 = al_load_bitmap("Bitmapsdialogue/dial4.2.jpg");
		image5 = al_load_bitmap("Bitmapsdialogue/dial4.3.1.jpg");
		image6 = al_load_bitmap("Bitmapsdialogue/dial4.3.2.jpg");
		image7 = al_load_bitmap("Bitmapsdialogue/dial4.4.1.jpg");
		image8 = al_load_bitmap("Bitmapsdialogue/dial4.4.2.jpg");
		image9 = al_load_bitmap("Bitmapsdialogue/dial4.5.1.png");
		image10 = al_load_bitmap("Bitmapsdialogue/dial4.5.2.jpg");
		image11 = al_load_bitmap("Bitmapsdialogue/dial4.6.1.jpg");
		image12 = al_load_bitmap("Bitmapsdialogue/dial4.6.2.jpg");
		image13 = al_load_bitmap("Bitmapsdialogue/dial4.7.1.jpg");
		image14 = al_load_bitmap("Bitmapsdialogue/dial4.7.2.jpg");
		image15 = al_load_bitmap("Bitmapsdialogue/dial4.8.jpg");
		image16 = al_load_bitmap("Bitmapsdialogue/dial4.9.jpg");
		image17 = al_load_bitmap("Bitmapsdialogue/dial4.10.jpg");
		image18 = al_load_bitmap("Bitmapsdialogue/dial4.11.jpg");
		image19 = al_load_bitmap("Bitmapsdialogue/dial4.12.jpg");
	}
	else if (CountDialogo == 5) {
		// Pré-Boss
		quantDialogos =  13;
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
	}
	else if (CountDialogo == 6) {
		// Pós-Boss
		quantDialogos = 1;
		image = al_load_bitmap("Bitmapsdialogue/dialafterboss.jpg"); 
	}
	else if (CountDialogo == 7) {
		// Final
		quantDialogos = 2;
		image = al_load_bitmap("Bitmapsdialogue/dialfinal1.jpg");
		image2 = al_load_bitmap("Bitmapsdialogue/dialfinal2.jpg"); 
	}
	else if (CountDialogo == 8) {
		// Minigames não finalizados
		quantDialogos = 1;
		image = al_load_bitmap("Bitmapsdialogue/dialcheckmapa3.jpg");
	}
	else if (CountDialogo == 9) {
		// Porta fechada
		quantDialogos = 1;
		image = al_load_bitmap("Bitmapsdialogue/dialdoor.jpg");
	}

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_play_sample_instance(ptra->inst[4]);
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_F:
				al_stop_sample_instance(ptra->inst[4]);
				al_play_sample_instance(ptra->inst[4]);
				numDialogos++;
				break;
			case ALLEGRO_KEY_X:
				al_stop_sample_instance(ptra->inst[4]);
				al_play_sample_instance(ptra->inst[4]);
				done = true;
				break;
			}
		}

		if (numDialogos >= quantDialogos) {
			done = true;
			break;
		}

		if (numDialogos == 0) {
			al_draw_bitmap(image, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 1) {
			al_draw_bitmap(image2, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 2) {
			al_draw_bitmap(image3, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 3) {
			al_draw_bitmap(image4, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 4) {
			al_draw_bitmap(image5, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 5) {
			al_draw_bitmap(image6, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 6) {
			al_draw_bitmap(image7, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 7) {
			al_draw_bitmap(image8, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 8) {
			al_draw_bitmap(image9, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 9) {
			al_draw_bitmap(image10, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 10) {
			al_draw_bitmap(image11, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 11) {
			al_draw_bitmap(image12, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 12) {
			al_draw_bitmap(image13, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 13) {
			al_draw_bitmap(image14, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 14) {
			al_draw_bitmap(image15, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 15) {
			al_draw_bitmap(image16, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 16) {
			al_draw_bitmap(image17, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 17) {
			al_draw_bitmap(image18, Xdialogo, Ydialogo, 0);
		}
		else if (numDialogos == 18) {
			al_draw_bitmap(image19, Xdialogo, Ydialogo, 0);
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
	al_destroy_bitmap(image18);
	al_destroy_bitmap(image19);
	al_destroy_event_queue(event_queue);

}

void dialogHub(mapa* ptr, vida* ptrv, movimento* ptrm, mapa* CountDialogo, audio* ptra) {
	// ------ DIALOGOS ------
	if (ptrm->CountDialogo == 0) {
		dialogo(1, ptra);
		ptrm->CountDialogo++;
	}
	else if (ptrm->CountDialogo == 1 && ptr->pos_x == 544) {
		dialogo(2, ptra);
		ptrm->CountDialogo++;
	}
	else if (ptrm->CountDialogo == 2 && ptr->pos_x == 32 && ptr->escolhaMapa == 2) {
		dialogo(3, ptra);
		ptrm->CountDialogo++;
	}
	else if (ptrm->CountDialogo == 3 && ptr->pos_y == 416 && ptr->escolhaMapa == 2 && ptrm->minigameAtual <= 3) {
		ptr->pos_y = min(384, ptr->pos_y);
		dialogo(8, ptra);
	}
	else if (ptrm->minigameAtual >= 3 && ptrm->CountDialogo == 3) {
		ptrm->CountDialogo++;
	}
	else if (ptrm->CountDialogo == 4 && (ptr->pos_x == 416 || ptr->pos_y == 192) && ptr->escolhaMapa == 3) {
		dialogo(5, ptra);
		readyM();
		boss(ptr, ptrv, ptra);
		ptrm->CountDialogo++;
	}
	else if (ptrm->CountDialogo == 5 && ptr->pos_x == 64 && ptr->escolhaMapa == 3) {
		dialogo(6, ptra);
		ptrm->CountDialogo++;
	}
	else if (ptrm->CountDialogo == 6 && ptr->pos_x == 576 && ptr->escolhaMapa == 4) {
		dialogo(7, ptra);
		ptrm->CountDialogo++;
	}
}