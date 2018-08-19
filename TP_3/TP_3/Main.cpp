#include "Common_header.h"
#include "Simulator.h"
#include "Floor.h"
#include "Robot.h"
#include "Drawer.h"

int
main()
{
	int height = 10, width = 10;

	Drawer(width, height);
	Drawer::allegro_init;
	Drawer::draw_display;
	al_rest(5.0);
	Drawer::allegro_destroy;
	return 0;
}