#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>				//incluindo bibliotecas
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>

typedef struct maps{
	int escolhaMapa;
	int** map;
	int pos_x;
	int pos_y;
	bool done;
} mapa;

typedef struct vidas {
	int vida;
	bool done;
} vida;

int Xdialogo = 27;
int Ydialogo = 300;

#endif