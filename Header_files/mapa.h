#ifndef _MAPA_H_
#define _MAPA_H_

#include <fstream>

#include "../Header_files/gameObject.h"
#include "../Header_files/personagem.h"

using namespace std;

class Mapa : public GameObject
{

public:

	bool b;

	int **matriz;

	int linhas;
	int colunas;
	int qtd_tiledHorinzontal;
	int qtd_tiledVertical;

	int aux1;
	int aux2;

	float *vetorx;
	float *vetory;

	ifstream txtFile;
	
	Mapa(string caminho);
	void init(GameObject* &gameObject);
	void colisao(Personagem* &heroi);
	~Mapa();
	
};

#endif