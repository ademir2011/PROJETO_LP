#include "../Header_files/tela.h"

Tela::Tela()
{
	vetorBool[0] = string_char;
	x1 = -1; 
	y1 = -1;
	x2 = -1;
	y2 = -1;
	tela = false;
}

void Tela::screen(float x1, float y1, float x2, float y2, string caminho)
{
	vetorBool[1] = caminho;

	if(vetorBool[1] != vetorBool[0])
	{
			vetorBool[0] = vetorBool[1];
			
			
			string_char	= caminho.c_str();
			fundo	 	= al_load_bitmap(string_char);

			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x1 + al_get_bitmap_width(fundo);
			this->y2 = y1 + al_get_bitmap_height(fundo);

			w = al_get_bitmap_width(fundo);
			h = al_get_bitmap_height(fundo);

			ld[0] = false;
	}
	else
	{
		al_draw_bitmap(fundo, this->x1, this->y1, 0);
	}

}

void Tela::screen(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color)
{

	if (ld[0] == true)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;

		this->color = color;
		
		ld[0] = false;
	}
	else
	{
		al_draw_filled_rectangle(this->x1, this->y1, this->x2, this->y2, color);
	}

}

void Tela::startPosition(float x1, float y1)
{
	this->x1 = x1;
	this->y1 = y1;
}

void Tela::finalPosition(float x2, float y2)
{
	this->x2 = x2;
	this->y2 = y2;
}

bool Tela::clicado()
{

	al_get_mouse_state(&state);

	if (state.x > x1 && state.x < x2 &&
		state.y > y1 && state.y < y2 && state.buttons & 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Tela::hover()
{
	al_get_mouse_state(&state);

	if (state.x > x1 && state.x < x2 &&
		state.y > y1 && state.y < y2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Tela::~Tela()
{
	al_destroy_bitmap(fundo);
}