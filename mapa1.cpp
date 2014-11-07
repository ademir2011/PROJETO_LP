#include "mapa1.h"

Mapa1::Mapa1(int SIZE_X, int SIZE_Y)
{
	x = SIZE_X;
	y = SIZE_Y;
}

void Mapa1::mapa_fase1(ALLEGRO_BITMAP *area_central, ALLEGRO_BITMAP *botao_sair)
{
	   	// Limpamos a tela
        al_clear_to_color(al_map_rgb(0, 0, 0));
 
        // Colorimos o bitmap correspondente ao retângulo central,
        // com a cor condicionada ao conteúdo da flag na_area_central
        al_set_target_bitmap(area_central);
        
        if (!na_area_central) al_clear_to_color(al_map_rgb(255, 255, 255));
        else al_clear_to_color(al_map_rgb(0, 255, 0));
 
        // Colorimos o bitmap do botão de sair
        al_set_target_bitmap(botao_sair);
        al_clear_to_color(al_map_rgb(25, 13, 22));
 
        // Desenhamos os retângulos na tela
        al_set_target_bitmap(al_get_backbuffer(janela));
        al_draw_bitmap(area_central, x / 2 - al_get_bitmap_width(area_central) / 2,
                       y / 2 - al_get_bitmap_height(area_central) / 2, 0);
        al_draw_bitmap(botao_sair, x - al_get_bitmap_width(botao_sair) - 10,
                       y - al_get_bitmap_height(botao_sair) - 10, 0);

}

Mapa1::~Mapa1()
{
	
}