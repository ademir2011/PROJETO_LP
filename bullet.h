#ifndef _BULLET_H_
#define _BULLET_H_

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "personagem.h"
#include "inimigo.h"

using std::cout;
using std::endl;
using std::cin;

class Bullet
{
public:

	int ID;
	int x;
	int y;
	bool live;
	int speed;

	Bullet();
	
	void InitBullet(Bullet bullet[], int size);
	void DrawBullet(Bullet bullet[], int size, ALLEGRO_DISPLAY* &janela);
	void FireBullet(Bullet bullet[], int size, Personagem* &personagem);
	void UpdateBullet(Bullet bullet[], int size);

	void CollideBullet(Bullet bullet[], int bSize, Inimigo inimigo[], int cSize);


	~Bullet();
	
};

#endif