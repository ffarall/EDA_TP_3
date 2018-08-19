#include "Drawer.h"

Drawer::Drawer(uint w, uint h)	//constructor
{
	Hcount = h;	//cantidad de baldosas en y
	Wcount = w;	//cantidad de baldosas en x
	dispHeight = Hcount * SINGLE_TILE;	//altura del display
	dispWidth = Wcount * SINGLE_TILE;	//ancho del display

}

void Drawer::
allegro_init()	//inicializa todas las funciones de allegro
{
	if (!(al_init()))
	{
		err.errorNum = AL_INIT_ERROR;
	}
	if (!al_init_image_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		allegro_destroy();
	}
	if (!al_init_font_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		allegro_destroy();
	}
	if (!al_init_primitives_addon())
	{
		err.errorNum = AL_ADDON_ERROR;
		allegro_destroy();
	}

	display = al_create_display(dispWidth, dispHeight);	//se crea el display de un tamaño determinado. El tamaño de las baldosas depende del tamaño del display
	if (display == NULL)
	{
		err.errorNum = AL_DISPLAY_ERROR;
		allegro_destroy();
	}
	
	robotImage = al_load_bitmap("images/robot.png");
	dirtImage = al_load_bitmap("images/dirt.png");
	if (robotImage == NULL || dirtImage == NULL)
	{
		err.errorNum = AL_IMAGE_ERROR;
	}
	
}

void Drawer::
allegro_destroy()	//cierra todas las funciones de allegro
{
	al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_destroy_bitmap(dirtImage);
	al_destroy_bitmap(robotImage);
	al_destroy_display(display);
}

void Drawer::
draw_init_display()	//dibuja las baldosas y las inicializa en sucio
{
	al_clear_to_color(al_map_rgb(255,255,255));
	
	for (int i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		al_draw_line(i, 0, i, dispHeight, al_map_rgb(0, 0, 0), 1.0);
	}
	
	for (int i = 0; i < dispHeight; i += SINGLE_TILE)
	{
		al_draw_line(0, i, dispWidth, i, al_map_rgb(0, 0, 0), 1.0);
	}
	for (int i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		for (int j = 0; j < dispHeight; j += SINGLE_TILE)
		{
			al_draw_scaled_bitmap(dirtImage, 0, 0, al_get_bitmap_width(dirtImage), al_get_bitmap_height(dirtImage), i, j, SINGLE_TILE, SINGLE_TILE, 0);
		}
	}
	al_flip_display();
}
/*
void Drawer::
update_display(Floor * floor, Robot * robots)	//hace el update del display a medida que se van moviendo los robots
{
	al_clear_to_color(al_map_rgb(255, 255, 255));

	for (int i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		al_draw_line(i, 0, i, dispHeight, al_map_rgb(0, 0, 0), 1.0);
	}

	for (int i = 0; i < dispHeight; i += SINGLE_TILE)
	{
		al_draw_line(0, i, dispWidth, i, al_map_rgb(0, 0, 0), 1.0);
	}
	for (int i = 0; i < dispWidth; i += SINGLE_TILE)
	{
		for (int j = 0; j < dispHeight; j += SINGLE_TILE)
		{
			for(int k = 0; k < rc; k++)
			{
				if(floor->is_dirty(i,j))		//si la baldosa en (i,j) esta sucia, pintar dirt
				{
					al_draw_scaled_bitmap(dirtImage, 0, 0, al_get_bitmap_width(dirtImage), al_get_bitmap_height(dirtImage), i, j, SINGLE_TILE, SINGLE_TILE, 0);
				}
				if(Robot[k]->get_pos().x == i && Robot[k]->get_pos().x == j)			//si hay un robot en (i,j), pintar el robot
				{
					al_draw_scaled_bitmap(robotImage, 0, 0, al_get_bitmap_width(robotImage), al_get_bitmap_height(robotImage), i, j, SINGLE_TILE, SINGLE_TILE, 0);
				}
			}
		}
	}
	al_flip_display();
}*/


