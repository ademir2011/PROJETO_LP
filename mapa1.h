#ifndef _MAPA1_H_
#define _MAPA1_H_

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "personagem.h"

using std::cout;
using std::endl;
using std::cin;

class Mapa1
{

public:

//LEMBRAR DE  FAZER OS METODOS GET's E SET's
//LEMBRAR DE  FAZER OS METODOS GET's E SET's
//LEMBRAR DE  FAZER OS METODOS GET's E SET's
//LEMBRAR DE  FAZER OS METODOS GET's E SET's


	int x;
	int y;

	float bouncer_x;
   	float bouncer_y;

	Mapa1(int SIZE_X, int SIZE_Y);
	void mapa_fase1( 
					ALLEGRO_DISPLAY *janela,
					ALLEGRO_BITMAP *quadrado_teste,
					Personagem* &personagem
					);
	~Mapa1();
	
};

#endif