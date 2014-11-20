#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "personagem.h"

using std::cout;
using std::endl;
using std::cin;

class Inimigo
{

public:

	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;

	Inimigo();
	void InitInimigo(Inimigo inimigo[], int size);
	void DrawInimigo(Inimigo inimigo[], int size);
	void StartInimigo(Inimigo inimigo[], int size);
	void UpdateInimigo(Inimigo inimigo[], int size);
	void CollideComet(Inimigo inimigo[], int cSize, Personagem* &personagem);
	~Inimigo();
	
};

#endif