#ifndef _FLOOR_H
#define _FLOOR_H

#include "Common_header.h"

class Floor
{
	bool *tiles;
	int wCount;
	int hCount;
	errorType_t err;
public:
	Floor(uint h, uint w);

	uint get_height();
	uint get_width();

	bool is_dirty(uint x, uint y);
	bool is_floorClean();
	void clean_tile(uint x, uint y);
	void clean_tile(pos_t pos);
	void destroy();
	errNo_t get_err();
};

#endif

