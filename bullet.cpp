#include "bullet.h"

Bullet::Bullet()
{

}

void Bullet::InitBullet(Bullet bullet[], int size)
{
	for(int i = 0; i < size; i++)
	{
		bullet[i].speed = 5;
		bullet[i].live = false;
	}
}
void Bullet::DrawBullet(Bullet bullet[], int size, ALLEGRO_DISPLAY* &janela)
{
	for( int i = 0; i < size; i++)
	{
		if(bullet[i].live)
		{
			al_draw_filled_circle(bullet[i].x, bullet[i].y, 10, al_map_rgb(255, 255, 255));
		}
	}
}
void Bullet::FireBullet(Bullet bullet[], int size, Personagem* &personagem)
{
	for( int i = 0; i < size; i++)
	{
		if(!bullet[i].live)
		{
			bullet[i].x = personagem->getPersonagemX() + 17;
			bullet[i].y = personagem->getPersonagemY();
			bullet[i].live = true;
			break;
		}
	}
}
void Bullet::UpdateBullet(Bullet bullet[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(bullet[i].live)
		{
			bullet[i].x += bullet[i].speed;
			//trocar 800 por size_X
			if(bullet[i].x > 800)
				bullet[i].live = false;
		}
	}
}

void Bullet::CollideBullet(Bullet bullet[], int bSize, Inimigo inimigo[], int cSize)
{
	for(int i = 0; i < bSize; i++)
	{
		if(bullet[i].live)
		{
			for(int j =0; j < cSize; j++)
			{
				if(inimigo[j].live)
				{
					if(bullet[i].x > (inimigo[j].x - inimigo[j].boundx) &&
						bullet[i].x < (inimigo[j].x + inimigo[j].boundx) &&
						bullet[i].y > (inimigo[j].y - inimigo[j].boundy) &&
						bullet[i].y < (inimigo[j].y + inimigo[j].boundy))
					{
						bullet[i].live = false;
						inimigo[j].live = false;
					}
				}
			}
		}
	}
}

Bullet::~Bullet()
{
	
}