#include "Drawer.h"

Drawer::Drawer(uint w, uint h, uint rc) 	//constructor modo1
{
	Hcount = h;	//cantidad de baldosas en y
	Wcount = w;	//cantidad de baldosas en x
	dispHeight = Hcount * SINGLE_TILE;	//altura del display
	dispWidth = Wcount * SINGLE_TILE;	//ancho del display
	robotCount = rc;
}

Drawer::Drawer(double tickCounters[MAX_SIM], uint max_robots)	//constructor modo2
{
	Wcount = 9;
	
	if (tickCounters[0] > REF)
	{
		dispHeight = normalize2(tickCounters[0]) + EXTRA_SIZE + GRAPH_CONST;
		for (uint i = 1; i <= max_robots; i++)
		{
			if (normalize2(tickCounters[i-1]) > MIN_VALUE2)
			{
				dispWidth = EXTRA_SIZE + 2 * GRAPH_CONST * (i + (i / 3));
			}
		}
	}
	else
	{
		dispHeight = normalize1(tickCounters[0]) + EXTRA_SIZE + GRAPH_CONST;
		for (uint i = 1; i <= max_robots; i++)
		{
			if (normalize1(tickCounters[i-1]) > MIN_VALUE)
			{
				dispWidth = EXTRA_SIZE + 2 * GRAPH_CONST * (i + (i / 3));
			}
		}
	}

	robotCount = max_robots;
	memcpy(tickCounter, tickCounters, sizeof(double)* MAX_SIM);
}

int Drawer::
allegro_init()	//inicializa todas las funciones de allegro
{
	int res = 1;
	if (!(al_init()))
	{
		err.errorNum = AL_INIT_ERROR;
		err.detail = "Error al iniciar Allegro!";
		res = 0;
	}
	if (!al_init_image_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		err.detail = "Error al iniciar el Image Addon de Allegro!";
		res = 0;
	}
	if (!al_init_font_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		err.detail = "Error al iniciar el Font Addon de Allegro!";
		res = 0;
	}
	if (!al_init_ttf_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		err.detail = "Error al iniciar el TTF Addon de Allegro!";
		res = 0;
	}
	if (!al_init_primitives_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		err.detail = "Error al iniciar el Primitives Addon de Allegro!";
		res = 0;
	}

	display = al_create_display(dispWidth, dispHeight);	//se crea el display de un tamaño determinado. El tamaño de las baldosas depende del tamaño del display
	if (display == NULL)
	{
		err.errorNum = AL_DISPLAY_ERROR;
		err.detail = "Error al iniciar el Display!";
		res = 0;
	}
	font = al_load_ttf_font("sources/ARCADE_N.TTF", Wcount+2, 0);
	if (font == NULL)
	{
		err.errorNum = AL_FONT_ERROR;
		err.detail = "Error al iniciar el Font!";
		res = 0;
	}

	robotImage = al_load_bitmap("sources/roomba.png");
	dirtImage = al_load_bitmap("sources/dirt.png");
	if (robotImage == NULL || dirtImage == NULL)
	{
		err.errorNum = AL_IMAGE_ERROR;
		err.detail = "Error al iniciar las imagenes!";
		res = 0;
	}
	return res;
}

void Drawer::
allegro_destroy()	//cierra todas las funciones de allegro
{
	al_destroy_bitmap(dirtImage);
	al_destroy_bitmap(robotImage);
	al_destroy_display(display);
	al_destroy_font(font);

	al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
}

void Drawer::
print_error()
{
	cout << err.detail << endl;
}

//Metodos de modo 1
void Drawer::
draw_init_display(Robot * robots)	//dibuja las baldosas y las inicializa en sucio
{
	al_clear_to_color(al_map_rgb(255, 255, 255));

	for (uint i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		al_draw_line(i, 0, i, dispHeight, al_map_rgb(0, 0, 0), 1.0);
	}

	for (uint i = 0; i < dispHeight; i += SINGLE_TILE)
	{
		al_draw_line(0, i, dispWidth, i, al_map_rgb(0, 0, 0), 1.0);
	}
	for (uint i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		for (uint j = 0; j < dispHeight; j += SINGLE_TILE)
		{
			al_draw_scaled_bitmap(dirtImage, 0, 0, al_get_bitmap_width(dirtImage), al_get_bitmap_height(dirtImage), i, j, SINGLE_TILE, SINGLE_TILE, 0);
			for (uint k = 0; k < robotCount; k++)
			{
				if ((floor(robots[k].get_robotPos().x) == (i/ SINGLE_TILE)) && (floor(robots[k].get_robotPos().y) == (j/ SINGLE_TILE)))			//si hay un robot en (i,j), pintar el robot
				{
					al_draw_scaled_bitmap(robotImage,
						0, 0,
						al_get_bitmap_width(robotImage),
						al_get_bitmap_height(robotImage),
						robots[k].get_robotPos().x * SINGLE_TILE - (SINGLE_TILE / 2.0), robots[k].get_robotPos().y  * SINGLE_TILE - (SINGLE_TILE / 2.0),
						SINGLE_TILE, SINGLE_TILE, 0);
				}
			}
		}
	}
	al_flip_display();
}

void Drawer::
update_display(Robot * robots, Floor& f)	//hace el update del display a medida que se van moviendo los robots
{
	uint ip, jp;
	al_clear_to_color(al_map_rgb(255, 255, 255));

	for (uint i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		al_draw_line(i, 0, i, dispHeight, al_map_rgb(0, 0, 0), 1.0);
	}

	for (uint i = 0; i < dispHeight; i += SINGLE_TILE)
	{
		al_draw_line(0, i, dispWidth, i, al_map_rgb(0, 0, 0), 1.0);
	}
	for (uint i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		for (uint j = 0; j < dispHeight; j += SINGLE_TILE)
		{

			if (f.is_dirty((i / SINGLE_TILE), (j / SINGLE_TILE)) == DIRTY)		//si la baldosa en (i,j) esta sucia, pintar dirt
			{
				al_draw_scaled_bitmap(dirtImage, 0, 0, al_get_bitmap_width(dirtImage), al_get_bitmap_height(dirtImage), i, j, SINGLE_TILE, SINGLE_TILE, 0);
				al_draw_scaled_bitmap(dirtImage, 0, 0, al_get_bitmap_width(dirtImage), al_get_bitmap_height(dirtImage), i, j, SINGLE_TILE, SINGLE_TILE, 0);
			}
			for (uint k = 0; k < robotCount; k++)
			{
				ip = i / SINGLE_TILE;
				jp = j / SINGLE_TILE;
				if ((floor(robots[k].get_robotPos().x) == ip) && (floor(robots[k].get_robotPos().y) == jp))			//si hay un robot en (i,j), pintar el robot
				{
					al_draw_scaled_bitmap(robotImage, 
						0, 0, 
						al_get_bitmap_width(robotImage), 
						al_get_bitmap_height(robotImage), 
						robots[k].get_robotPos().x * SINGLE_TILE - (SINGLE_TILE / 2.0), robots[k].get_robotPos().y  * SINGLE_TILE - (SINGLE_TILE / 2.0),
						SINGLE_TILE, SINGLE_TILE, 0);
				}
			}
		}
	}
	al_flip_display();
}

void Drawer::
show_ticks(uint ticks)	//muestra en pantalla los ticks utilizados
{
	al_draw_filled_rectangle(dispWidth / 6.0, dispHeight / 4.0, 5.0*dispWidth / 6.0, 3.0*dispHeight / 4.0, al_map_rgb(255, 255, 0));
	char text[MAX_OUTPUT];
	snprintf(text, MAX_OUTPUT, "Numero de ticks: %d", ticks);
	al_draw_text(font, al_map_rgb(0, 0, 0), dispWidth / 2.0, dispHeight / 2.0, ALLEGRO_ALIGN_CENTER, text);
	al_flip_display();
}

//metodos de modo 2
double Drawer::
normalize1(double num)
{
	double res;
	res = (num * SINGLE_TILE) / SCALE;
	return res;
}
double Drawer::
normalize2(double num)
{
	double res;
	res = (num * SINGLE_TILE) / SCALE2;
	return res;
}

void Drawer::
draw_graph()
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	
	for (uint i = 1; i <= robotCount; i++ )
	{
		if (tickCounter[0] > REF)
		{
			if (normalize2(tickCounter[i - 1]) > MIN_VALUE2)
			{
				char text[TEXT];
				snprintf(text,TEXT, "%d", i);
				al_draw_filled_rectangle((i) *((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)), dispHeight - (EXTRA_SIZE / 2.0), (i) * ((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)) + SINGLE_TILE, dispHeight - (EXTRA_SIZE / 2.0) - normalize2(tickCounter[i - 1]), al_map_rgb(0, 0, 255));
				double midpoint = ((i) *((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)) + (i) * ((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)) + SINGLE_TILE) / 2.0;
				al_draw_text(font, al_map_rgb(0, 0, 0), midpoint, (dispHeight - EXTRA_SIZE / 2.0)+3, ALLEGRO_ALIGN_CENTER, text);
			}
		}
		else
		{
			if (normalize1(tickCounter[i - 1]) > MIN_VALUE)
			{
				char text[TEXT];
				snprintf(text, TEXT, "%d", i);
				al_draw_filled_rectangle((i) *((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)), dispHeight - (EXTRA_SIZE / 2.0), (i) * ((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)) + SINGLE_TILE, dispHeight - (EXTRA_SIZE / 2.0) - normalize1(tickCounter[i - 1]), al_map_rgb(0, 0, 255));
				double midpoint = ((i) *((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)) + (i) * ((GRAPH_CONST / 2.0) + (EXTRA_SIZE / 2.0)) + SINGLE_TILE) / 2.0;
				al_draw_text(font,al_map_rgb(0,0,0),midpoint, (dispHeight - EXTRA_SIZE / 2.0)+3,ALLEGRO_ALIGN_CENTER, text);
			}
		}
	}


	al_draw_line(EXTRA_SIZE / 2.0, dispHeight - (EXTRA_SIZE / 2.0), EXTRA_SIZE / 2.0, EXTRA_SIZE / 2.0, al_map_rgb(0, 0, 0), 1.0);	//eje y
	al_draw_line(EXTRA_SIZE / 2.0, dispHeight - (EXTRA_SIZE / 2.0), (dispWidth - EXTRA_SIZE / 2.0), dispHeight - (EXTRA_SIZE / 2.0), al_map_rgb(0, 0, 0), 1.0);	//eje x
	
	
	int j = 0;
	for (int i = dispHeight - (EXTRA_SIZE / 2); i >= EXTRA_SIZE / 2; i-= SINGLE_TILE)
	{
		char text[TEXT];
		snprintf(text, TEXT, "%d", j);
		al_draw_line(EXTRA_SIZE / 2.0 - 5, i, EXTRA_SIZE / 2.0 + 5, i, al_map_rgb(0, 0, 0), 1.0);
		al_draw_text(font, al_map_rgb(0, 0, 0), EXTRA_SIZE / 2.0 - 15, i, ALLEGRO_ALIGN_CENTER, text);
		j++;
	}

	if (tickCounter[0] > REF)
	{
		char text[MAX_OUTPUT];
		snprintf(text, MAX_OUTPUT, "TICKS - ESCALA 1:%.1f", SCALE2);
		al_draw_text(font, al_map_rgb(0, 0, 0), EXTRA_SIZE / 2.0,(EXTRA_SIZE / 2.0) - 15, ALLEGRO_ALIGN_LEFT, text);
	}
	else
	{
		char text[MAX_OUTPUT];
		snprintf(text, MAX_OUTPUT, "TICKS - ESCALA 1:%.1f", SCALE);
		al_draw_text(font, al_map_rgb(0, 0, 0), EXTRA_SIZE / 2.0, (EXTRA_SIZE / 2.0) - 15, ALLEGRO_ALIGN_LEFT, text);
	}
	
	al_flip_display();
}