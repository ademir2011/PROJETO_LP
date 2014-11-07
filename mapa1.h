#ifndef _MAPA1_H_
#define _MAPA1_H_

#include <iostream>
#include <allegro5/allegro.h>

using std::cout;
using std::endl;
using std::cin;

class Mapa1
{

	int x;
	int y;

public:
	Mapa1(int SIZE_X, int SIZE_Y);
	void mapa_fase1(ALLEGRO_BITMAP *area_central, 
					ALLEGRO_BITMAP *botao_sair);
	~Mapa1();
	
};

#endif