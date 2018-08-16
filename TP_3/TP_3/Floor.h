#pragma once
#ifndef _FLOOR_H
#define _FLOOR_H

#define CLEAN true
#define DIRTY false

#include "Link.h"

class Floor
{
	bool * baldosas;
	uint Hcount;
	uint Wcount;
	errorType err;

	//bool isClean; //opcional

public:

	Floor(uint h, uint w);

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

