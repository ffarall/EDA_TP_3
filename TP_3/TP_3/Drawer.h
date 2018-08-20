#pragma once
#ifndef _DRAWER_
#define _DRAWER_

#define SINGLE_TILE 50
#define MAX_OUTPUT 40
#define EXTRA_SIZE 100
#define GRAPH_CONST SINGLE_TILE / 2
#define SCALE 10.0
#define SCALE2 100.0
#define REF 200.0
#define MIN_VALUE SCALE / 4.0
#define MIN_VALUE2 SCALE2 / 4.0
#define TEXT 3

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
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
	ALLEGRO_FONT * font;
	uint dispWidth;
	uint dispHeight;
	uint Hcount;
	uint Wcount;
	uint robotCount;
	double tickCounter[MAX_SIM];
	errorType_t err;

public:
	Drawer(uint w, uint h, uint rc);					//constructor modo 1
	Drawer(double tickCounters[MAX_SIM], uint rc);				//constructor modo 2
	int allegro_init();
	void allegro_destroy();
	void print_error();
	//modo 1
	void draw_init_display(Robot * robots);
	void update_display(Robot * robots, Floor& f);
	void show_ticks(uint ticks);
	
	//modo 2
	void draw_graph();
	double normalize1(double num);
	double normalize2(double num);
};

#endif