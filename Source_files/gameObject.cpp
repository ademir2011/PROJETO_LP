#include "../Header_files/gameObject.h"

GameObject::GameObject()
{
	close = false;
	draw = true;

	for (int i = 0; i < 10; i++)
		ld[i] = true;

	tela = 1;

    LARGURA   = 800;
    ALTURA    = 600;

    FPS     = 60.0;

    x = -1;
	y = -1;
	x1 = -1;
	y1 = -1;
	x2 = -1;
	y2 = -1;

	gravity = 2;

	mouse_x = -1;
	mouse_y = -1;

	mouse_x_down = -1;
	mouse_y_down = -1;

	mouse_x_up = -1;
	mouse_y_up = -1;

	tecla1 = true;
	tecla2 = true;

	string_char = "";

}

void GameObject::start()
{

	Config1 *config1 		= new Config1();

	//configurações iniciais do allegro
	config1->carrega_allegro();

	//imagens
	config1->aloca_imagens(map,100);    

	//musicas e sons
	config1->aloca_musicas_e_sons();
	musica = config1->musica_fundo1;

	//fontes
	config1->aloca_fontes();
	fonte = config1->font;

	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);

	janela = al_create_display(LARGURA, ALTURA);

	al_set_window_position(janela, 300, 50);
	al_set_window_title(janela, "Honor Quest");

	timer = al_create_timer(1.0/FPS);

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(janela));
	al_register_event_source(event_queue, al_get_mouse_event_source());


	al_start_timer(timer);
}

void GameObject::startEvents()
{

	al_wait_for_event(event_queue, &event);

	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		close = true;

	if (event.type == ALLEGRO_EVENT_TIMER)
	{

		al_get_keyboard_state(&keyState);
			
		teclaDown = "NULL";

		if (al_key_down(&keyState, ALLEGRO_KEY_A))
			teclaDown = "a";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_B))
			teclaDown = "b";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_C))
			teclaDown = "c";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			teclaDown = "right";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			teclaDown = "left";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_UP))
			teclaDown = "up";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
			teclaDown = "down";
			
		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE))
			teclaDown = "space";

		draw = true;
	}

	if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		mouse_x = event.mouse.x;
		mouse_y = event.mouse.y;
	} 

	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		mouse_x_down = event.mouse.x;
		mouse_y_down = event.mouse.y;

		if (tecla1 == true)
		{
			tecla2 = true;
			tecla1 = false;
		}
	}

	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
		mouse_x_up = event.mouse.x;
		mouse_y_up = event.mouse.y;

		tecla1 = true;
	}

}

void GameObject::text(float x1, float y1, string caminho)
{
	
	string_char 	= caminho.c_str();

	al_draw_text(fonte, al_map_rgb(255,255,255), 10, 10, ALLEGRO_ALIGN_LEFT, "asd");
	
}

void GameObject::musiconoff(bool tf)
{
	if (tf == true)
	{
		 al_set_audio_stream_playing(musica, true);
	}
	else if (tf == false)
	{
		 al_set_audio_stream_playing(musica, false);
	}
}

GameObject::~GameObject()
{
    al_destroy_timer(timer);
    al_destroy_display(janela);

    al_destroy_bitmap(fundo);
    al_destroy_bitmap(teste);

	al_destroy_font(fonte);

}
