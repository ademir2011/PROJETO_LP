#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "../Header_files/gameObject.h"

class Personagem : public GameObject
{

	public:


		float forca;
		float agilidade;
		float vitalidade;
		float energia;

		float money;
		float pontuacao;

		float jump;

		float vetPosx1[3];
		float vetPosy1[3];
		float vetPosx2[3];
		float vetPosy2[3];

		float 	tamanho;
		float 	velocidade;
		float 	vida;
		float 	vida_total;
		float 	dano;
		float 	level;
		float 	experiencia_total;
		float 	experiencia_corrente;
		bool 	vivo;

		ALLEGRO_MOUSE_STATE state1;
		ALLEGRO_MOUSE_STATE state2;

		ALLEGRO_BITMAP *img_pergonagem = NULL;

		Personagem();
		void init(string caminho);
		void setPosition(float x1, float y1);
		void setAbility(float forca, float agilidade, float vitalidade, float energia, float velocidade);
		void view();
		void moviments(string teclaDown);
		bool dentroTela(int LARGURA, int ALTURA);
		~Personagem();

};

#endif