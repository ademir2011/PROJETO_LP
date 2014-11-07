#include <iostream>
#include "tela.h"
#include "mapa1.h"

int main(int argc, char const *argv[])
{
	bool close = false;

	Tela tela;
	tela.config();
	tela.tela_jogo();

	return 0;
}	