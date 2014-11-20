#include "personagem.h"

Personagem::Personagem()
{
	personagem_x = 400 - 25;
	personagem_y = 300 - 25;
	velocPerson = 10;
	personagem_bm = al_load_bitmap("person.png");
	borda_x = 10;
	borda_y = 10;
	vida = 10;
}

void Personagem::drawPerson()
{
	al_draw_bitmap(personagem_bm, personagem_x, personagem_y, 0);
}

Personagem::~Personagem()
{
 	al_destroy_bitmap(personagem_bm);
}