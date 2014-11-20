#include "mapa1.h"

Mapa1::Mapa1(int SIZE_X, int SIZE_Y)
{
	x = SIZE_X;
	y = SIZE_Y;
	bouncer_x = SIZE_X / 2.0 - 50 / 2.0;
	bouncer_y = SIZE_Y / 2.0 - 50 / 2.0;
}

void Mapa1::mapa_fase1(ALLEGRO_DISPLAY *janela, ALLEGRO_BITMAP *quadrado_teste, Personagem* &personagem)
{

	//Quadrado mouse
	al_set_target_bitmap(quadrado_teste);
	al_clear_to_color(al_map_rgb(25, 130, 250));


	// Desenhamos os retângulos na tela
	al_set_target_bitmap(al_get_backbuffer(janela));

	//base
	al_draw_rectangle(x / 2 - 400/ 2, y / 2 - 300 / 2, 600, 450, al_map_rgb(255, 210, 0), 10);

	//ui1
	al_draw_filled_rectangle(x-300, 0, x-100, 75, al_map_rgb(253, 102, 23));

	al_draw_bitmap(quadrado_teste, bouncer_x, bouncer_y, 0);

	personagem->drawPerson();

}

Mapa1::~Mapa1()
{
	
}