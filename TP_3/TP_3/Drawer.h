#pragma once
#ifndef _DRAWER_
#define _DRAWER_

#define SINGLE_TILE 50

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include "Common_header.h"
#include "Floor.h"
#include "Robot.h"

class Drawer
{
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP * robotImage;
	ALLEGRO_BITMAP * dirtImage;
	int dispWidth;
	int dispHeight;
	uint Hcount;
	uint Wcount;
	errorType_t err;
	Robot * robots;
	Floor * floor;

public:
	Drawer(uint w, uint h);
	
	void allegro_init();
	void allegro_destroy();
	void draw_init_display();
	void update_display();
};

#endif