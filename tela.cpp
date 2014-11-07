#include "tela.h"

Tela::Tela()
{

	SIZE_X = 800;
	SIZE_Y = 600;

	// Inicializamos a biblioteca
	if(al_init()) { cout<<"Programa iniciado com sucesso"<<endl;} ;

	// Criamos a nossa janela - dimensões de 640x480 px
	janela = al_create_display(SIZE_X, SIZE_Y);

	al_set_window_title(janela, "BTI DEFENDER - The Best Game of the World");

	// Atribui o cursor padrão do sistema para ser usado
    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

    //Criação dos objetos
    Mapa1 mapa1(SIZE_X,SIZE_Y);

}

void Tela::config()
{
	// Inicializa o add-on para utilização de imagens
    al_init_image_addon();

    bool al_init_primitives_addon(void);

    // Torna apto o uso de mouse na aplicação
    al_install_mouse();

    // Carrega as imagens
    imagem = al_load_bitmap("fundo1.jpg");

    area_central = al_create_bitmap(SIZE_X / 2, SIZE_Y / 2);

    botao_sair = al_create_bitmap(100,50);

    fila_eventos = al_create_event_queue();	

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
   	//al_draw_bitmap(imagem, 0, 0, 0);

    al_flip_display();

}

void Tela::tela_jogo()
{
	//temporario
    int na_area_central = 0;

	al_init_timeout(&timeout, 0.05);

	int sair = 0;

	while (!sair)
    {
        // Verificamos se há eventos na fila
        while (!al_is_event_queue_empty(fila_eventos))
        {

        	mapa1.mapa_fase1(ALLEGRO_BITMAP &area_central, ALLEGRO_BITMAP &botao_sair);

            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
 			
 			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);

        }
 
        // Atualiza a tela
        al_flip_display();
    }
}

Tela::~Tela()
{
	// Desaloca os recursos utilizados na aplicação
    al_destroy_bitmap(botao_sair);
    al_destroy_bitmap(area_central);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
}

