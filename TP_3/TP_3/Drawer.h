#pragma once
#ifndef _DRAWER_
#define _DRAWER_

#define DISP_WIDTH 800
#define DISP_HEIGHT 800

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "Common_header.h"
#include "Floor.h"
#include "Robot.h"

class Drawer
{
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP * robotImage;
	uint Hcount;
	uint Wcount;
	errNo_t err;
	Robot * robots;
	Floor * floor;

public:
	Drawer(uint w, uint h);
	
	void allegro_init();
	void allegro_destroy();
	void draw_tile();				//pintar solo las baldosas
	void draw_robot();				//pintar solo los robots
	void draw_display();			//metodo que, utilizando las funciones de arriba, pinta todo el display
};

#endif