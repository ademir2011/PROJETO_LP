#include "../Header_files/config1.h"

Config1::Config1()
{

}

void Config1::carrega_allegro()
{
	// Inicializamos a biblioteca e addons
    if (!al_init())
    	cout<<"Error ao inicializar o allegro5"<<endl;

    if (!al_init_primitives_addon())
        cout<<"Error ao inicializar o primitives addon"<<endl;
  
    if (!al_init_image_addon())
        cout<<"Error ao inicializar o image addon"<<endl;

   	if (!al_install_keyboard())
   		cout<<"Error ao inicializar o keyboard"<<endl;

   	if (!al_install_mouse())
   		cout<<"Error ao inicializar o mouse"<<endl;

   	if (!al_install_audio())
   		cout<<"Error ao inicializar o audio"<<endl;

   	if (!al_init_acodec_addon())
   		cout<<"Error ao inicializar o acodec"<<endl;

   	if (!al_reserve_samples(1))
    	cout<<"Error ao inicializar o sample"<<endl;

    al_init_font_addon();

    if (!al_init_ttf_addon())
    	cout<<"Error ao inicializar o ttf"<<endl;
}

void Config1::aloca_imagens(ALLEGRO_BITMAP *map[], int size)
{
	

	for (int i = 1; i <= 5; i++)
	{
		sprintf(caminho, "Images/mapa/mapa_%i.png", i);	
		map[i] 			= al_load_bitmap(caminho);
		if (!map[i])
			cout<<"error image bg_"<<i<<endl;
	}


}

void Config1::aloca_musicas_e_sons()
{

	//musicas e sons
	musica_fundo1 = al_load_audio_stream("Music/theme.ogg", 4, 1024);

	if (!musica_fundo1)
		cout<<"deu pau"<<endl;

	al_attach_audio_stream_to_mixer(musica_fundo1, al_get_default_mixer());

}


void Config1::aloca_fontes()
{
  font = al_load_font("Font/font.ttf", 20, 0);
  if (!font)
    cout<<"Error FONT"<<endl; 
}

void Config1::eventos_timers_display()
{

}

Config1::~Config1()
{
    al_destroy_audio_stream(musica_fundo1);  

    al_destroy_font(font);
}