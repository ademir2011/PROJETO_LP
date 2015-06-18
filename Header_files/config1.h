#ifndef _CONFIG1_H_
#define _CONFIG1_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

class Config1
{


public:

	char caminho[100];

	//musicas
	ALLEGRO_AUDIO_STREAM *musica_fundo1		= NULL;

	//fonte
	ALLEGRO_FONT *font 						= NULL;

	Config1();
	void carrega_allegro();
	void aloca_imagens(ALLEGRO_BITMAP *map[], int size);
	void aloca_musicas_e_sons();
	void aloca_fontes();
	void eventos_timers_display();
	~Config1();
	
};

#endif 