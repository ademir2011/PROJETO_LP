#ifndef _COLISAO_H_
#define _COLISAO_H_

#include <iostream>	

#include "../Header_files/gameObject.h"
#include "../Header_files/mapa.h"
#include "../Header_files/personagem.h"

class Colisao : public GameObject
{

public:

	Colisao();

	bool bounding_box(Personagem* &obj1, Mapa* &obj2);

	~Colisao();
	
};

#endif