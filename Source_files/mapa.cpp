#include "../Header_files/mapa.h"

Mapa::Mapa(string caminho)
{

	//>>>> 40 x 40 <<<<//

	string_char 	= caminho.c_str();
	txtFile.open(string_char);

	txtFile >> linhas >> colunas;

	qtd_tiledHorinzontal 	= 800/colunas;
	qtd_tiledVertical	 	= 600/linhas;

	matriz = new int*[linhas];

	//aloca matriz
	if (matriz != NULL)
	{
		for (int i = 0; i < linhas; i++)
		{
			matriz[i] = new int[colunas];
			if (matriz[i] == NULL)
			{
				cout<<"memoria insuficiente"<<endl;
				break;
			}
		}
	}

	//armazena valores do arquivo txt na matriz
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			txtFile >> matriz[i][j];
		}
	}
	
	b = true;

	vetorx = new float[400];
	vetory = new float[400];

	contador = 0;

	for (int i = 0; i < colunas; i++)
	{
		for (int j = 0; j < linhas; j++)
		{
			aux1 = (i+1)*qtd_tiledVertical;
			aux2 = (j+1)*qtd_tiledHorinzontal;
			
			x1 = aux1-qtd_tiledHorinzontal;
			y1 = aux2-qtd_tiledVertical;
			w = 40;
			h = 40;

			vetorx[contador] = x1;
			vetory[contador] = y1;

			contador+=1;
		}
	}
}

void Mapa::init(GameObject* &gameObject)
{

	contador = 0;
 	
	for (int i = 0; i < colunas; i++)
	{
		for (int j = 0; j < linhas; j++)
		{

			if(matriz[j][i] == 0)
			{
				//al_draw_filled_rectangle(aux1-qtd_tiledHorinzontal, aux2-qtd_tiledVertical, aux1, aux2, al_map_rgb(0,0,0));
			}
			else if(matriz[j][i] == 1)
			{
				al_draw_bitmap(gameObject->map[1], vetorx[contador], vetory[contador], 0);
			}
			else if(matriz[j][i] == 2)
			{
				al_draw_bitmap(gameObject->map[2], vetorx[contador], vetory[contador], 0);
			}
			else if(matriz[j][i] == 3)
			{
				al_draw_bitmap(gameObject->map[3], vetorx[contador], vetory[contador], 0);
			}
			else if(matriz[j][i] == 4)
			{
				al_draw_bitmap(gameObject->map[4], vetorx[contador], vetory[contador], 0);
			}
			else if(matriz[j][i] == 5)
			{
				al_draw_bitmap(gameObject->map[5], vetorx[contador], vetory[contador], 0);
			}
			
			contador+=1;
		}
	}
}

void Mapa::colisao(Personagem* &heroi)
{
	for (int i = 0; i < colunas; i++)
	{
		for (int j = 0; j < linhas; j++)
		{
			aux1 = (i+1)*qtd_tiledVertical;
			aux2 = (j+1)*qtd_tiledHorinzontal;
		}
	}
}

Mapa::~Mapa()
{
	//libera matriz da memoria
	if (matriz != NULL)
	{
		for (int i = 0; i < linhas; i++)
			delete matriz[i];
		delete matriz;

	}

}