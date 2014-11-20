#include "inimigo.h"

Inimigo::Inimigo()
{

}

void Inimigo::InitInimigo(Inimigo inimigo[], int size)
{
	for(int i = 0; i < size; i++)
	{
		inimigo[i].live = false;
		inimigo[i].speed = 5;
		inimigo[i].boundx = 18;
		inimigo[i].boundy = 18;
	}
}
void Inimigo::DrawInimigo(Inimigo inimigo[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(inimigo[i].live)
		{
			al_draw_filled_circle(inimigo[i].x, inimigo[i].y, 20, al_map_rgb(255, 0, 0));
		}
	}
}
void Inimigo::StartInimigo(Inimigo inimigo[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(!inimigo[i].live)
		{
			if(rand() % 500 == 0)
			{
				inimigo[i].live = true;
				inimigo[i].x = 800;
				inimigo[i].y = 30 + rand() % (600 - 60);

				break;
			}
		}
	}
}
void Inimigo::UpdateInimigo(Inimigo inimigo[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(inimigo[i].live)
		{
			inimigo[i].x -= inimigo[i].speed;

			if(inimigo[i].x < 0)
				inimigo[i].live = false;
		}
	}
}

void Inimigo::CollideComet(Inimigo inimigo[], int cSize, Personagem* &personagem)
{
	for(int i = 0; i < cSize; i++)
	{
		if(inimigo[i].live)
		{
			if(inimigo[i].x - inimigo[i].boundx < personagem->getPersonagemX() + personagem->borda_x &&
				inimigo[i].x + inimigo[i].boundx > personagem->getPersonagemX() - personagem->borda_x &&
				inimigo[i].y - inimigo[i].boundy < personagem->getPersonagemY() + personagem->borda_y &&
				inimigo[i].y + inimigo[i].boundy > personagem->getPersonagemY() - personagem->borda_y)
			{
				personagem->vida--;
				inimigo[i].live = false;
			}
			else if(inimigo[i].x < 0)
			{
				inimigo[i].live = false;
				personagem->vida--;
			}
		}
	}
}
Inimigo::~Inimigo()
{
	//al_destroy_bitmap();
}