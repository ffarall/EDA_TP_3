#include "Drawer.h"

Drawer::Drawer(uint w, uint h)
{
	Hcount = h;
	Wcount = w;
	DISP_HEIGHT = Hcount * SINGLE_TILE;
	DISP_WIDTH = Wcount * SINGLE_TILE;

}

void Drawer::
allegro_init()
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

	display = al_create_display(DISP_WIDTH, DISP_HEIGHT);	//se crea el display de un tamaño determinado. El tamaño de las baldosas depende del tamaño del display
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
allegro_destroy()
{
	al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_destroy_display(display);
}

void Drawer::
draw_init_display()
{
	al_clear_to_color(al_map_rgb(255,255,255));
	
	for (int i = 0; i < DISP_WIDTH; i += SINGLE_TILE)
	{
		al_draw_line(i, 0, i, DISP_HEIGHT, al_map_rgb(0, 0, 0), 1.0);
	}
	
	for (int i = 0; i < DISP_HEIGHT; i += SINGLE_TILE)
	{
		al_draw_line(0, i, DISP_WIDTH, i, al_map_rgb(0, 0, 0), 1.0);
	}
	for (int i = 0; i < DISP_WIDTH; i+= SINGLE_TILE)
	{
		for (int j = 0; j < DISP_HEIGHT; j += SINGLE_TILE)
		{
			al_draw_scaled_bitmap(dirtImage, 0, 0, al_get_bitmap_width(dirtImage), al_get_bitmap_height(dirtImage), i, j, i + SINGLE_TILE, j + SINGLE_TILE, 0);
		}
	}
	al_flip_display();
}
