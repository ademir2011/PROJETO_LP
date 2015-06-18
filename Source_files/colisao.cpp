#include "../Header_files/colisao.h"

Colisao::Colisao()
{
}

bool Colisao::bounding_box(Personagem* &obj1, Mapa* &obj2)
{
	contador = 0;

	for (int i = 0; i < obj2->colunas; i++)
	{
		for (int j = 0; j < obj2->linhas ; j++)
		{
			switch(obj2->matriz[j][i])
			{
				case 2:
					if (!(obj1->x1 > (obj2->vetorx[contador] + obj2->w) ||
						  obj1->y1 > (obj2->vetory[contador] + obj2->h) ||
						 (obj1->x1 + obj1->w) < obj2->vetorx[contador] ||
						 (obj1->y1 + obj1->h) < obj2->vetory[contador]))
					{
						return true;
					}

				break;
			}

			contador+=1;
		}
	}

	return false;

}

Colisao::~Colisao()
{

}
