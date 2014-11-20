#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_ 

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using std::cout;
using std::endl;
using std::cin;


class Personagem
{

	int personagem_x;
	int personagem_y;
	int velocPerson;


public:

	int borda_x;
	int borda_y;

	int vida;

	ALLEGRO_BITMAP *personagem_bm = NULL;

	Personagem();

	void drawPerson();

	void setPersonagemX(int personagem_x){this->personagem_x += personagem_x; };
	int getPersonagemX(){ return personagem_x; };

	void setPersonagemY(int personagem_y){this->personagem_y += personagem_y; };
	int getPersonagemY(){ return personagem_y; };

	void setVelocPerson(int velocPerson){ this->velocPerson = velocPerson; };
	int getVelocPerson(){ return velocPerson; };

	~Personagem();
};

#endif