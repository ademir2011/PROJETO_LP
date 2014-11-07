#ifndef _TELA_H_
#define _TELA_H_ 

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "mapa1.h"

using std::cout;
using std::endl;
using std::cin;

class Tela
{
	int SIZE_X;
	int SIZE_Y;

	// Variável representando a janela principal
	ALLEGRO_DISPLAY *janela = NULL;

	// Variável representando a imagem
    ALLEGRO_BITMAP *imagem = NULL;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    ALLEGRO_BITMAP *botao_sair = NULL, *area_central = NULL;

    ALLEGRO_EVENT evento;

	ALLEGRO_TIMEOUT timeout;

public:
	Tela();
	void config();
	void tela_jogo();
	~Tela();	
};

#endif