#include "Common_header.h"
//#include "Simulator.h"
//#include "Floor.h"
//#include "Robot.h"
#include "Drawer.h"

int
main()
{
	int height = 10, width = 10;

	Drawer draw(width, height);
	draw.allegro_init();
	draw.draw_init_display();
	al_rest(15.0);
	draw.allegro_destroy();
	return 0;
}