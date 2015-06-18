#include "../Header_files/personagem.h"

Personagem::Personagem()
{
}

void Personagem::init(string caminho)
{

	if(ld[2] == true)
	{

	velocidade 	= 1;
	vida 		= 0;
	vida_total  = 0;
	vivo 		= true;

	forca 		= 10.0;
	agilidade 	= 10.0;
	vitalidade 	= 10.0;
	energia 	= 10.0;

	jump		= 25.0;

	money		= 0;
	pontuacao 	= 0;

	level 		= 1;
	
	string_char			= caminho.c_str();
	img_pergonagem	 	= al_load_bitmap(string_char);

	dano = 0;

	experiencia_total = 0;
	experiencia_corrente = 0;

		ld[2] = false;
	} 
		

}

void Personagem::setPosition(float x1, float y1)
{
	if (ld[0] == true)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x1 + al_get_bitmap_width(img_pergonagem);
		this->y2 = y1 + al_get_bitmap_height(img_pergonagem);

		w = al_get_bitmap_width(img_pergonagem);
		h = al_get_bitmap_height(img_pergonagem);
		
		ld[0] = false;
	}
}

void Personagem::setAbility(float forca, float agilidade, float vitalidade, float energia, float velocidade)
{
	if (ld[1] == true)
	{
		this->forca 		= forca;
		this->agilidade 	= agilidade;
		this->vitalidade	= vitalidade;
		this->energia 		= energia;
		this->velocidade	= velocidade;
		
		ld[1] = false;
	}
}

void Personagem::view()
{
	al_draw_bitmap(img_pergonagem, x1, y1, 0);
}

void Personagem::moviments(string teclaDown)
{

	vetPosx1[0] = x1;
	vetPosy1[0] = y1;
	vetPosx2[0]	= x2;
	vetPosy2[0] = y2;

/*
	if (teclaDown == "right")
	{
		x1+=velocidade;
		x2+=velocidade;
	}
	else if (teclaDown == "left")
	{
		x1-=velocidade;
		x2-=velocidade;
	}
*/

}

bool Personagem::dentroTela(int LARGURA, int ALTURA)
{
	if (x1 >= 0 && x2 <= LARGURA && y1 >= 0 && y2 <= ALTURA)
		return true;
	else
		return false;
}

Personagem::~Personagem()
{
	al_destroy_bitmap(img_pergonagem);
}
