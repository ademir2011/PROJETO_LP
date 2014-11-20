#ifndef _MOVIMENTO_H_
#define _MOVIMENTO_H_

#include "mapa1.h"

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using std::cout;
using std::endl;
using std::cin;

class Movimento
{
public:
	Movimento();

	void moveMouse(Mapa1* &mapa1, 
					bool &sair, 
					int width, 
					int heith );

	~Movimento();
	
};

#endif