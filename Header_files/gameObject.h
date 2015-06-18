#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "../Header_files/config1.h"

//#include "../Header_files/personagem.h"
//#include "../Header_files/bullet.h"
//#include "../Header_files/obstaculo.h"
//#include "../Header_files/botao.h"
//#include "../Header_files/mapa.h"
//#include "../Header_files/colisao.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using std::string;

class GameObject
{

public:

	bool close, 
		 draw,
		 ld[10],
		 tecla1,
		 tecla2;

	int tela, contador;

	int LARGURA;
	int ALTURA;

	//sizes vector
	int MAXSIZE_IMAGES;

	float x1, y1, x2, y2, x, y, w, h;

	float gravity;

	float mouse_x, mouse_y;

	float mouse_x_down, mouse_y_down;

	float mouse_x_up, mouse_y_up;

	float velocidade;
	float size;
	float vida;

	float FPS;

	string teclaDown;
	string teclaUp;

	string vetorBool[10];

	const char* 		string_char	= NULL;

	//Variaveis do allegro
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_MOUSE_STATE state;	

	ALLEGRO_EVENT event;

	ALLEGRO_DISPLAY 	*janela 		= NULL;
	ALLEGRO_EVENT_QUEUE *event_queue 	= NULL;
	ALLEGRO_TIMER 		*timer 			= NULL;

	//outras variaveis
	ALLEGRO_COLOR		color;

	ALLEGRO_BITMAP 		*fundo 		= NULL;
	ALLEGRO_BITMAP 		*teste 		= NULL;

	//
	ALLEGRO_BITMAP 		*map[100];

	ALLEGRO_FONT 		*fonte 	= NULL;

	//musicas
	ALLEGRO_AUDIO_STREAM *musica		= NULL;


	GameObject();
	
	void start();
	
	void startEvents();

	void text(float x1, float y1, string caminho);

	void musiconoff(bool tf);

	~GameObject();
	
};

#endif