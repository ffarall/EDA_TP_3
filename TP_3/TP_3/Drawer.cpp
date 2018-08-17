#include "Drawer.h"



Drawer::Drawer(uint w, uint h)
{
	Hcount = h;
	Wcount = w;
	al_init();
	al_init_image_addon();
	al_init_font_addon();
}

void Drawer::
allegro_init()
{
	display = al_create_display(DISP_WIDTH, DISP_HEIGHT);	//se crea el display de un tamaño determinado. El tamaño de las baldosas depende del tamaño del display
	robotImage = al_load_bitmap("images/robot.png");
	
}

void Drawer::
allegro_destroy()
{
	al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_destroy_display(display);
}
