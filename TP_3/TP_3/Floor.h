class Floor
{
	bool *tiles;
	int wCount;
	int hCount;
public:
	Floor(uint h, uint w);
	~Floor();

	uint get_height();
	uint get_width();

	bool is_dirty(uint x, uint y);
	bool is_floorClean();
	void clean_tile(uint x, uint y);
	void clean_tile(pos_t pos);
	void destroy();
	errorType get_err();
};

//cosas que tenia
#pragma once
#ifndef _FLOOR_H
#define _FLOOR_H

#define CLEAN true
#define DIRTY false

#include "Header.h"

class Piso
{
	bool * baldosas;
	uint Hcount;
	uint Wcount;
	errorType err;

	//bool isClean; //opcional

public:

	Piso(uint h, uint w);

	uint getHeight();
	uint getWidth();

	bool isDirty(uint x, uint y);
	bool isFloorClean();
	void cleanTile(uint x, uint y);
	void cleanTile(pos_t pos);
	void destroy();
	errorType getErr();
};

#endif

