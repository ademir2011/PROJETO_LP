#ifndef _TELA_H_
#define _TELA_H_ 

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

#include "mapa1.h"
#include "personagem.h"
#include "movimento.h"
#include "inimigo.h"
#include "bullet.h"

using std::cout;
using std::endl;
using std::cin;

const float FPS = 60;
const int NUM_BULLETS = 5;
const int NUM_inimigo = 5;


enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE,
};

class Tela
{
	int SIZE_X;
	int SIZE_Y;
	
	bool sair;

	// Variável representando a janela principal
	ALLEGRO_DISPLAY *janela = NULL;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    ALLEGRO_BITMAP 	*imagem = NULL,
    				*quadrado_teste = NULL;

    // O nosso arquivo de fonte
    ALLEGRO_FONT *fonte = NULL;

	ALLEGRO_TIMEOUT timeout;

	ALLEGRO_TIMER *timer = NULL;

	ALLEGRO_AUDIO_STREAM *musica = NULL;

public:

	Bullet bullets[5];
	Inimigo inimigo[5];

	Tela();
	void config();
	void tela_jogo();
	~Tela();	
};

#endif