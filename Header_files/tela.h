#ifndef _TELA_H_
#define _TELA_H_

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "../Header_files/gameObject.h"
#include <string>

using namespace std;

class Tela : public GameObject
{
	public:

		bool live;
 
		Tela();

		void screen(float x1, float y1, float x2, float y2, string caminho);
    	void screen(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color);
		void startPosition(float x1, float y1);
		void finalPosition(float x2, float y2);

		bool clicado();
		bool hover();

		~Tela();
};

#endif 