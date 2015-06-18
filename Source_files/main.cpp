
#include <iostream>
#include "../Header_files/gameObject.h"
#include "../Header_files/tela.h"
#include "../Header_files/mapa.h"
#include "../Header_files/personagem.h"
#include "../Header_files/colisao.h"

using namespace std;

#define MAX_COIN 25	

int main()
{

//instancias
	GameObject 	*gameObject 		= new GameObject();

	//tela 1
	Tela 		*telaInicial 		= new Tela();

	Tela 		*btStartgame		= new Tela();
	Tela 		*btStartgameClicked = new Tela();
	Tela 		*btConfig			= new Tela();
	Tela 		*btExit				= new Tela();
	Tela 		*btExitClicked 		= new Tela(); 	
	Tela 		*menuPanel			= new Tela(); 		

	//tela 2
	Mapa		*F1					= new Mapa("Maps/F1.txt");
	Tela 		*backgroundF1		= new Tela();

		//heroi
	Personagem  *heroi				= new Personagem();
			
			//sword
	Tela 		*sword 				= new Tela();
	Tela 		*tela_atk 			= new Tela();

	Colisao 	*colisao 			= new Colisao();

		//barra exp e hp
	Tela 		*xp					= new Tela();
	Tela 		*hp					= new Tela();
		
		//abilities
	Tela 		*painel				= new Tela();
	Tela 		*bt_forca 			= new Tela();
	Tela 		*bt_agilidade		= new Tela();
	Tela 		*bt_vitalidade		= new Tela();
	Tela 		*bt_energia			= new Tela();

		//menu superior
	Tela 		*menu_superior		= new Tela();

	//icons
	Tela 		coin[MAX_COIN];
	Tela 		*potionhp 			= new Tela(); 

		//icon sound
	Tela 		*sound_on			= new Tela();
	Tela 		*sound_off			= new Tela();

		//inimigos
	Personagem  *inimigo1			= new Personagem();
	Personagem  *inimigo2			= new Personagem();
	Personagem  *inimigo3			= new Personagem();
	Personagem  *inimigo4			= new Personagem();
	Personagem  *inimigo5			= new Personagem();
	Personagem  *inimigo6			= new Personagem();
	Personagem  *inimigo7			= new Personagem();
	Personagem  *inimigo8			= new Personagem();

	Tela  *inimigo1_1			= new Tela();
	Tela  *inimigo2_2			= new Tela();
	Tela  *inimigo3_3			= new Tela();
	Tela  *inimigo4_4			= new Tela();
	Tela  *inimigo5_5			= new Tela();
	Tela  *inimigo6_6			= new Tela();
	Tela  *inimigo7_7			= new Tela();
	Tela  *inimigo8_8			= new Tela();


gameObject->start();

//--------------VARIAVEIS----------------

	float bt_x1 					= 0;
	float bt_y1 					= 0;

	bool ativa_som 				= true; 

	float random 				= 0;

	int bt_mais_view 			= 0;

	//heroi
	float dano 					= 0;
	bool formulas 				= true;

	//inimigo
	int inimigo 				= 1;
	bool formulas2 				= true;
	float inimigo_vida_total 	= 500;

	float inimigo_money 		= 1;
	float inimigo_pontuacao 	= 1;
	float inimigo_xp 			= 1;
	float inimigo_dano 			= 1;

	//potion
	float pot_preco				= 100;
	float pot_hp_recovery 		= 100;

		//animation

			//heroi
	bool animation1_heroi 			= false;
	int animation2_heroi 			= 0;
	float frameAnimation_heroi		= 10;

			//inimigo
	bool animation1_inimigo 		= false;
	int animation2_inimigo 			= 0;
	float frameAnimation_inimigo	= 10;

			//pontuacao
	bool animation1_pontuacao 		= false;
	int animation2_pontuacao 		= 0;
	float frameAnimation_pontuacao 	= 100;

			//icon
	bool coin_velocidade 			= true;
	float frameAnimation_coin 		= 300;


//--------------Init---------------------

	while(!gameObject->close)
	{
		gameObject->startEvents();
		
		ALLEGRO_SAMPLE *sample = NULL;
		sample = al_load_sample("Sounds/click.wav");	
		
		if (gameObject->draw && al_is_event_queue_empty(gameObject->event_queue))
		{
			
			gameObject->draw = false;

			switch(gameObject->tela)
			{

//---------------AREA DE EDIÇÂO DO JOGO-----------
			case 1:

	//------------- Tela 1 ----------------

	

		telaInicial->screen(0,0,800,600,"Images/background/background1.png");	

		//Menu


		
		bt_x1 	= (gameObject->LARGURA/2)-(200/2);
		bt_y1	= gameObject->ALTURA-400;		
		
		btStartgame->screen(bt_x1,bt_y1,0,0,"Images/menu/bt_startgame.png");

		if (btStartgame->hover())
		{
			btStartgameClicked->screen(bt_x1,bt_y1,0,0,"Images/menu/bt_startgame_clicked.png");
			
			if (btStartgameClicked->clicado() && gameObject->tecla2==true)
			{
				gameObject->tela = 2;
			}
		}

		btExit->screen(bt_x1,bt_y1+70,0,0,"Images/menu/bt_exit.png");

		if (btExit->hover())
		{
			btExitClicked->screen(bt_x1,bt_y1+70,0,0,"Images/menu/bt_exit_clicked.png");
			
			if (btExitClicked->clicado() && gameObject->tecla2==true)
			{
				exit(0);
			}
		}

					break;

				case 2:


		backgroundF1->screen(0,0,800,600,"Images/background/background1.png");

		F1->init(gameObject);


// ------------------ Heroi ----------------

	heroi->init("Images/player/heroi1.png");
	heroi->setPosition(380,528);
	heroi->view();
	heroi->setAbility(10,10,10,10,5);
	heroi->moviments(gameObject->teclaDown);

	heroi->dano						= heroi->forca+(heroi->energia/2);
	
	if (formulas == true)
	{
		heroi->experiencia_corrente		= 0;
		heroi->experiencia_total		= 100;
		heroi->vida_total			 	= heroi->vitalidade*10;
		heroi->vida		 				= heroi->vitalidade*10;
		formulas		 				= false;
	}

	if (gameObject->tecla2 == true)
	{
		animation1_heroi = true;
	}

	if (animation1_heroi == true)
	{
		if (animation2_heroi < frameAnimation_heroi)
		{
			sword->screen(heroi->x1+15, heroi->y1-70, 0, 0,"Images/player/sword1.png");
			animation2_heroi++;
		}
	}
	
	else if (animation1_heroi == false){}
			
	if (animation2_heroi == frameAnimation_heroi)
	{
		animation1_heroi = false;
		animation2_heroi = 0;
	}

// if(!colisao->bounding_box(heroi, F1)){}
	
//------------ abilidades ------------------

	painel->screen(-5, (gameObject->ALTURA/2)-110, 200, (gameObject->ALTURA/2)-23, al_map_rgba(0,0,0,100));


	ALLEGRO_COLOR color = al_map_rgb(0,0,0);

	al_draw_textf(gameObject->fonte, color, 5, (gameObject->ALTURA/2)-100, ALLEGRO_ALIGN_LEFT,"Forca:           %.0f", heroi->forca);
	al_draw_textf(gameObject->fonte, color, 5, (gameObject->ALTURA/2)-80, ALLEGRO_ALIGN_LEFT, "Agilidade:     %.0f", heroi->agilidade);
	al_draw_textf(gameObject->fonte, color, 5, (gameObject->ALTURA/2)-60, ALLEGRO_ALIGN_LEFT, "Vitalidade:   %.0f", heroi->vitalidade);
	al_draw_textf(gameObject->fonte, color, 5, (gameObject->ALTURA/2)-40, ALLEGRO_ALIGN_LEFT, "Energia:        %.0f", heroi->energia);

	//------------- engine bt mais view-----------

	if (bt_mais_view > 0)
	{
		bt_forca->		screen(painel->x1+165, painel->y1+3, 0, 0, "Images/UI/seta.png");
		bt_agilidade->	screen(painel->x1+165, painel->y1+23, 0, 0, "Images/UI/seta.png");
		bt_vitalidade->	screen(painel->x1+165, painel->y1+43, 0, 0, "Images/UI/seta.png");
		bt_energia->	screen(painel->x1+165, painel->y1+63, 0, 0, "Images/UI/seta.png");

		if (bt_forca->clicado() && gameObject->tecla2 == true){
			bt_mais_view--;
			heroi->forca += 1;
		}
		if (bt_agilidade->clicado() && gameObject->tecla2 == true){
			bt_mais_view--;
			heroi->agilidade += 1;
		}
		if (bt_vitalidade->clicado() && gameObject->tecla2 == true){
			bt_mais_view--;
			heroi->vitalidade += 1;
			heroi->vida_total += 10;
		}
		if (bt_energia->clicado() && gameObject->tecla2 == true){
			bt_mais_view--;
			heroi->energia += 1;
		}
	}

//------------ engine atack ----------------

	if(gameObject->tecla2 == true)
	{
		animation1_pontuacao = true;
		random = rand()%500;
		heroi->vida -= inimigo_dano;
		heroi->experiencia_corrente += inimigo_xp;

		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

	}

	tela_atk->screen(gameObject->LARGURA-550, gameObject->ALTURA-550, gameObject->LARGURA-450, gameObject->ALTURA-530, al_map_rgba(0,0,0,100));

	if (animation1_pontuacao == true)
	{
		if (animation2_pontuacao < frameAnimation_pontuacao)
		{
			al_draw_textf(gameObject->fonte, color, gameObject->LARGURA-525, gameObject->ALTURA-550, ALLEGRO_ALIGN_LEFT, "%.0f", heroi->dano);
			animation2_pontuacao++;
		}
	}

	else if (animation1_pontuacao == false)
		{}

	if (animation2_pontuacao == frameAnimation_pontuacao)
	{
		animation1_pontuacao = false;
		animation2_pontuacao = 0;
	}

// ---------- engine level -----------------

	if (heroi->experiencia_corrente >= heroi->experiencia_total)
	{
		heroi->experiencia_corrente = 0;	
		heroi->experiencia_total+=100;
		heroi->vida_total += 10;
		heroi->level++;
		bt_mais_view++;
	}

//------------ engine coins ----------------

	if (coin_velocidade == true)
	{
			for (int i = 0; i < MAX_COIN; i++)
				coin[i].velocidade = rand()%10+5;
		coin_velocidade = false;
	}


	if(gameObject->tecla2 == true)
	{	
		//fire
		for( int i = 0; i < MAX_COIN; i++)
		{
			if(!coin[i].live)
			{
				coin[i].x1 = rand()%800+1;
				coin[i].y1 = 0;
				coin[i].live = true;
				break;
			}
		}
	}

	//draw
	for( int i = 0; i < MAX_COIN; i++)
		if(coin[i].live)
			coin[i].screen(coin[i].x1, coin[i].y1, 0, 0, "Images/UI/coin.png");

	//update
	for(int i = 0; i < MAX_COIN; i++)
	{
		if(coin[i].live)
		{
			coin[i].y1 += coin[i].velocidade;
			if(coin[i].y1 > gameObject->ALTURA)
				coin[i].live = false;
		}
	}

//------------ inimigos --------------------

				switch(inimigo)
				{
					case 1:

						inimigo1->init("Images/inimigos/inimigo1.png");
						inimigo1->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo1->vida_total 	= inimigo_vida_total;
							inimigo1->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo1->money 		= inimigo_money;
							inimigo1->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo1->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo1_1->screen(370,382,0,0,"Images/inimigos/inimigo1_1.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo1->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						
						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo1->vida, inimigo1->vida_total);
						
						if (inimigo1->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}

						break;
					case 2:

						inimigo2->init("Images/inimigos/inimigo2.png");
						inimigo2->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo2->vida_total 	= inimigo_vida_total;
							inimigo2->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo2->money 		= inimigo_money;
							inimigo2->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo2->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo2_2->screen(370,382,0,0,"Images/inimigos/inimigo2_2.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo2->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo2->vida, inimigo2->vida_total);
						
						
						if (inimigo2->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}

						break;
					case 3:
						inimigo3->init("Images/inimigos/inimigo3.png");
						inimigo3->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo3->vida_total 	= inimigo_vida_total;
							inimigo3->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo3->money 		= inimigo_money;
							inimigo3->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo3->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo3_3->screen(370,382,0,0,"Images/inimigos/inimigo3_3.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo3->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo3->vida, inimigo3->vida_total);
						
						
						if (inimigo3->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}
						break;
					case 4:
						inimigo4->init("Images/inimigos/inimigo4.png");
						inimigo4->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo4->vida_total 	= inimigo_vida_total;
							inimigo4->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo4->money 		= inimigo_money;
							inimigo4->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo4->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo4_4->screen(370,382,0,0,"Images/inimigos/inimigo4_4.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo4->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo4->vida, inimigo4->vida_total);
						
						
						if (inimigo4->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}
						break;
					case 5:
						inimigo5->init("Images/inimigos/inimigo5.png");
						inimigo5->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo5->vida_total 	= inimigo_vida_total;
							inimigo5->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo5->money 		= inimigo_money;
							inimigo5->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo5->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo5_5->screen(370,382,0,0,"Images/inimigos/inimigo5_5.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo5->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo5->vida, inimigo5->vida_total);
						
						
						if (inimigo5->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}

						break;
					case 6:
						inimigo6->init("Images/inimigos/inimigo6.png");
						inimigo6->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo6->vida_total 	= inimigo_vida_total;
							inimigo6->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo6->money 		= inimigo_money;
							inimigo6->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo6->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo6_6->screen(370,382,0,0,"Images/inimigos/inimigo6_6.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo6->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo6->vida, inimigo6->vida_total);
						
						
						if (inimigo6->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}

						break;
					case 7:
						inimigo7->init("Images/inimigos/inimigo7.png");
						inimigo7->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo7->vida_total 	= inimigo_vida_total;
							inimigo7->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo7->money 		= inimigo_money;
							inimigo7->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo7->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo7_7->screen(370,382,0,0,"Images/inimigos/inimigo7_7.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo7->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo7->vida, inimigo7->vida_total);
						
						
						if (inimigo7->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}

						break;
					case 8:
						inimigo8->init("Images/inimigos/inimigo8.png");
						inimigo8->setPosition(370,382);

						if (formulas2 == true)
						{
							inimigo8->vida_total 	= inimigo_vida_total;
							inimigo8->vida 			= inimigo_vida_total;
							formulas2 				= false;
							inimigo8->money 		= inimigo_money;
							inimigo8->pontuacao 	= inimigo_pontuacao;
						}
															
						if (gameObject->tecla2 == true)
						{
							inimigo8->vida 			-= heroi->dano;
							heroi->pontuacao 		+=inimigo_pontuacao;
							heroi->money  			+=inimigo_money;
							animation1_inimigo 		= true;
						}

						if (animation1_inimigo == true)
						{
							if (animation2_inimigo < frameAnimation_inimigo)
							{
								inimigo8_8->screen(370,382,0,0,"Images/inimigos/inimigo8_8.png");
								animation2_inimigo++;
							}
						}

						else if (animation1_inimigo == false)
							inimigo8->view();

						if (animation2_inimigo == frameAnimation_inimigo)
						{
							animation1_inimigo = false;
							animation2_inimigo = 0;
						}
						

						al_draw_textf(gameObject->fonte, color, 350, 382-70, ALLEGRO_ALIGN_LEFT, "%.0f/%.0f", inimigo8->vida, inimigo8->vida_total);
						
						
						if (inimigo8->vida <= 0)
						{
							inimigo_money			+= 3.5;
							inimigo_pontuacao 		+= 5;
							inimigo++;
							formulas2 				= true;
							inimigo_xp 				+=5;
							inimigo_dano 			+=1;
							inimigo_vida_total 		+= (100*2.5);
						}

						break;

				}

//------------ menu superior ---------------

	menu_superior->screen(0, 0, gameObject->LARGURA, 50, al_map_rgba(0,0,0,100));
	
	al_draw_textf(gameObject->fonte, color, gameObject->LARGURA-570, 20, ALLEGRO_ALIGN_LEFT, "Fase: %i", inimigo);
	al_draw_textf(gameObject->fonte, color, gameObject->LARGURA-460, 20, ALLEGRO_ALIGN_LEFT, "Level: %.0f", heroi->level);
	al_draw_textf(gameObject->fonte, color, gameObject->LARGURA-350, 20, ALLEGRO_ALIGN_LEFT, "$: %.2f", heroi->money);
	al_draw_textf(gameObject->fonte, color, gameObject->LARGURA-200, 20, ALLEGRO_ALIGN_LEFT, "Pontuacao: %.0f", heroi->pontuacao);

	if (sound_on->clicado() && gameObject->tecla2==true || sound_off->clicado() && gameObject->tecla2==true)
	{
		if(ativa_som == false)
		{
			ativa_som = true;
			gameObject->musiconoff(true);
		}
		else if(ativa_som == true)
		{
			ativa_som = false;
			gameObject->musiconoff(false);
		}
	}

	if (ativa_som == true)
	{	
		sound_off->screen(gameObject->LARGURA-700, 10, 0, 0, "Images/UI/sound_on.png");
	}
	else if(ativa_som == false)
	{
		sound_on->screen(gameObject->LARGURA-700, 10, 0, 0, "Images/UI/sound_off.png");
	}	
      
//------------ engine potion ---------------

	potionhp->screen(10,400,0,0,"Images/UI/potionhp.png");
	al_draw_textf(gameObject->fonte, color, potionhp->x1+40, potionhp->y1+15, ALLEGRO_ALIGN_LEFT, "+%.0f hp", pot_hp_recovery);
	al_draw_textf(gameObject->fonte, color, potionhp->x1+40, potionhp->y1+35, ALLEGRO_ALIGN_LEFT, "%.2f$", pot_preco);

	if (heroi->money >= pot_preco)
	{
		if (potionhp->clicado() && gameObject->tecla2 == true)
		{
			heroi->money -= pot_preco;
			
			if ((heroi->vida_total-heroi->vida) <= pot_hp_recovery)
			{
				heroi->vida += (heroi->vida_total-heroi->vida);
			}
			else
			{
				heroi->vida += pot_hp_recovery;
			}
		}
	}

//------------ xp e HP----------------------

	xp->screen(gameObject->LARGURA-600, gameObject->ALTURA-70, gameObject->LARGURA-470, gameObject->ALTURA-40, al_map_rgba(0,0,0,100));
	al_draw_textf(gameObject->fonte,  al_map_rgb(0,0,0), gameObject->LARGURA-595, gameObject->ALTURA-60, ALLEGRO_ALIGN_LEFT, "HP: %.0f/%.0f", heroi->vida, heroi->vida_total);
		
	hp->screen(gameObject->LARGURA-300, gameObject->ALTURA-70, gameObject->LARGURA-170, gameObject->ALTURA-40, al_map_rgba(0,0,0,100));
	al_draw_textf(gameObject->fonte,  al_map_rgb(0,0,0), gameObject->LARGURA-295, gameObject->ALTURA-60, ALLEGRO_ALIGN_LEFT, "XP: %.0f/%0.f", heroi->experiencia_corrente, heroi->experiencia_total);

//------------ others engines --------------
	if (heroi->money < 0)
	{
		heroi->money = 0;
	}

//------------ engine game over ------------
 
	if (heroi->vida <= 0)
	{
		bt_x1 					= 0;
		bt_y1 					= 0;

		ativa_som 				= true; 

		random 					= 0;

		bt_mais_view 			= 0;

		//heroi
		dano 					= 0;
		formulas 				= true;

		//inimigo
		inimigo 				= 1;
		formulas2 				= true;
		inimigo_vida_total 		= 100;

		inimigo_money 			= 1;
		inimigo_pontuacao 		= 1;
		inimigo_xp 				= 1;
		inimigo_dano 			= 1;

		//potion
		pot_preco				= 100;
		pot_hp_recovery 		= 100;

			//animation

				//heroi
		animation1_heroi 		= false;
		animation2_heroi 		= 0;
		frameAnimation_heroi	= 10;

				//inimigo
		animation1_inimigo 		= false;
		animation2_inimigo 		= 0;
		frameAnimation_inimigo	= 10;

				//pontuacao
		animation1_pontuacao 	= false;
		animation2_pontuacao 	= 0;
		frameAnimation_pontuacao= 100;

				//icon
		coin_velocidade 		= true;
		frameAnimation_coin 	= 300;

		heroi->level 			= 1;
		heroi->vida 			= 100;
		heroi->vida_total 		= 100;

		formulas2 				= true;

		gameObject->tela 		= 1;
	}

//------------ AREA DE EDIÇÂO DO JOGO-------

				gameObject->tecla2 = false;
				break;

				
		}

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}

//liberação objetos da memoria
	
	delete gameObject;

	//tela 1
		delete telaInicial;
	    delete btStartgame;
	    delete btStartgameClicked;
	    delete btConfig;
	    delete btExit;
	    delete btExitClicked;

	//tela 2
	    delete xp;
	    delete hp;
	    delete painel;
	    delete menu_superior;

	    delete sound_on;
	    delete sound_off;

	    delete backgroundF1;
	    delete heroi;

	    delete bt_forca;
	    delete bt_agilidade;
	    delete bt_vitalidade;
	    delete bt_energia;

	    delete sword;

	    delete tela_atk;

	    delete potionhp;

	    delete inimigo1;
	    delete inimigo2;
	    delete inimigo3;
	    delete inimigo4;
		delete inimigo5;
	    delete inimigo6;
	    delete inimigo7;
	    delete inimigo8;

	    delete inimigo1_1;
	    delete inimigo2_2;
	    delete inimigo3_3;
	    delete inimigo4_4;
	    delete inimigo5_5;
	    delete inimigo6_6;
	    delete inimigo7_7;
	    delete inimigo8_8;


	    delete colisao;

    return 0;

}