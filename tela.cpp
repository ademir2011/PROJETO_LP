#include "tela.h"

bool flagTiro = false;

Tela::Tela()
{
	SIZE_X = 800;
	SIZE_Y = 600;
	sair = false;

	// Inicializamos a biblioteca
	if(al_init()) { cout<<"Programa iniciado com sucesso"<<endl; }

	// Criamos a nossa janela - dimensões de 640x480 px
	janela = al_create_display(SIZE_X, SIZE_Y);

	al_set_window_title(janela, "BTI DEFENDER - The Best Game of the World");

	// Atribui o cursor padrão do sistema para ser usado
    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

}

void Tela::config()
{
	
	// Inicializa o add-on para utilização de imagens
    al_init_image_addon();

    bool al_init_primitives_addon(void);

    // Torna apto o uso de mouse na aplicação
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    timer = al_create_timer(1.0 / FPS);

    musica = al_load_audio_stream("music1.ogg", 4, 1024);

    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
    al_set_audio_stream_playing(musica, true);

    // Carrega as imagens
    imagem = al_load_bitmap("fundo1.jpg");

    quadrado_teste = al_create_bitmap(50,50);

    fila_eventos = al_create_event_queue();	

    //carregando fonte
    fonte = al_load_ttf_font("Base02.ttf", 32, 0);

    bullets[0].InitBullet(bullets, NUM_BULLETS);
	inimigo[0].InitInimigo(inimigo, NUM_inimigo);    

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
}

void Tela::tela_jogo()
{
	//al_init_timeout(&timeout, 0.05);

	Mapa1 *mapa1 			= new Mapa1(SIZE_X, SIZE_Y);
	Personagem *personagem 	= new Personagem;
	Movimento *movimento 	= new Movimento;

	bool redraw = true;

	bool key[5] = { false, false, false, false, false};

	al_start_timer(timer);

    while (!sair)
    {
    	ALLEGRO_EVENT evento;
    	// Verificamos se há eventos na fila
    	al_wait_for_event(fila_eventos, &evento);

        //movimento->moveMouse(mapa1, sair, SIZE_X, SIZE_Y);

		if(evento.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			if(key[KEY_UP] && personagem->getPersonagemY() >= 4)
		        personagem->setPersonagemY(-personagem->getVelocPerson());

			if(key[KEY_DOWN] && personagem->getPersonagemY() <= SIZE_Y - al_get_bitmap_height(personagem->personagem_bm))
		        personagem->setPersonagemY(personagem->getVelocPerson());

			if(key[KEY_LEFT] && personagem->getPersonagemX() >= 4)
				personagem->setPersonagemX(-personagem->getVelocPerson());

			if(key[KEY_RIGHT] && personagem->getPersonagemX() <= SIZE_X - al_get_bitmap_width(personagem->personagem_bm)) 
				personagem->setPersonagemX(personagem->getVelocPerson());

			bullets[0].UpdateBullet(bullets, NUM_BULLETS);
			inimigo[0].StartInimigo(inimigo, NUM_inimigo);
			inimigo[0].UpdateInimigo(inimigo, NUM_inimigo);
			bullets[0].CollideBullet(bullets, NUM_BULLETS, inimigo, NUM_inimigo);
			inimigo[0].CollideComet(inimigo, NUM_inimigo, personagem);
		}

		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	    {
	    	sair = true;
	    }

	    // Se o evento foi de movimentação do mouse
	    else if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
	    {
	    	mapa1->bouncer_x = evento.mouse.x;
	    	mapa1->bouncer_y = evento.mouse.y;
		    cout<<evento.mouse.x<<" "<<evento.mouse.y<<endl;
	    }

	    else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(evento.keyboard.keycode)
            {
	            case ALLEGRO_KEY_W:
	            	key[KEY_UP] = true;
	                break;
	            case ALLEGRO_KEY_S:
	            	key[KEY_DOWN] = true;
	                break;
	            case ALLEGRO_KEY_A:
	            	key[KEY_LEFT] = true;
	                break;
	            case ALLEGRO_KEY_D:
	            	key[KEY_RIGHT] = true;
	                break;
	            case ALLEGRO_KEY_SPACE:
	            	key[KEY_SPACE] = true;
	            	flagTiro = true;
	            	bullets[0].FireBullet(bullets, NUM_BULLETS, personagem);
	            	break;
            }
        }

		else if(evento.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(evento.keyboard.keycode)
			{
				case ALLEGRO_KEY_W:
				   key[KEY_UP] = false;
				   break;

				case ALLEGRO_KEY_S:
				   key[KEY_DOWN] = false;
				   break;

				case ALLEGRO_KEY_A: 
				   key[KEY_LEFT] = false;
				   break;

				case ALLEGRO_KEY_D:
				   key[KEY_RIGHT] = false;
				   break;

	            case ALLEGRO_KEY_SPACE:
	            	key[KEY_SPACE] = false;
	            	break;
			}
		}

		/*
	    //Botao sair
	    else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	    {
	      	if (evento.mouse.x >= SIZE_X - al_get_bitmap_width(botao_sair) - 10 &&
	            evento.mouse.x <= SIZE_X - 10 && evento.mouse.y <= SIZE_Y - 10 &&
	            evento.mouse.y >= SIZE_Y - al_get_bitmap_height(botao_sair) - 10)
	        {
	            sair = true;
	    	}
	    }*/

	    if(redraw && al_is_event_queue_empty(fila_eventos))
		{
			redraw = false;

			al_draw_bitmap(imagem, 0, 0, 0);

			mapa1->mapa_fase1(janela, quadrado_teste, personagem);	
			
			bullets[0].DrawBullet(bullets, NUM_BULLETS, janela);
			inimigo[0].DrawInimigo(inimigo, NUM_inimigo);	

 			int i = 2;
    		//char *texto = "Uma string qualquer";
    		al_draw_textf(fonte, al_map_rgb(0, 0, 0), SIZE_X - 200, 0, ALLEGRO_ALIGN_CENTRE, "Vida: %d", personagem->vida);
    		al_draw_textf(fonte, al_map_rgb(0, 0, 0), SIZE_X - 200, 0, ALLEGRO_ALIGN_CENTRE, "Vida: %d", personagem->vida);
    		al_draw_textf(fonte, al_map_rgb(0, 0, 0), SIZE_X - 200, 0, ALLEGRO_ALIGN_CENTRE, "Vida: %d", personagem->vida);

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
    }

    delete mapa1;
    delete personagem;
    delete movimento;
} 

Tela::~Tela()
{
	// Desaloca os recursos utilizados na aplicação
	al_destroy_font(fonte);
    al_destroy_bitmap(quadrado_teste);
    al_destroy_display(janela);
    al_destroy_timer(timer);
    al_destroy_event_queue(fila_eventos);
}

