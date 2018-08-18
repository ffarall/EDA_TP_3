#include "Floor.h"



Floor::Floor()
{
}


Floor::Floor(uint h, uint w)
{
	tiles = (bool *)malloc(h * w * sizeof(bool));
	if (tiles != NULL)
	{
		for (int i = 0; i < h*w; i++)
		{
			tiles[i] = true; // Se inicializan las baldozas sucias.
		}
		err.errorNum = NO_ERROR;
	}
	else
	{
		err.errorNum = NO_MEM;
		err.detail = "No memory in construction of Floor.\n";
	}
}

Floor::~Floor()
{
}

uint Floor::get_height()
{
	return hCount;
}

uint Floor::get_height(double y)
{
	return (uint)floor(y);
}

uint Floor::get_width()
{
	return wCount;
}

uint Floor::get_width(double x)
{
	return (uint)floor(x);
}

bool Floor::is_dirty(uint x, uint y)
{
	return *(tiles + y * wCount + x);
}

bool Floor::is_floorClean()
{
	bool ret = false;
	int i = 0;
	while (!ret && i < hCount*wCount)
	{
		ret = tiles[i];
		i++;
	}
	return ret;
}

void Floor::clean_tile(uint x, uint y)
{
	*(tiles + y * wCount + x) = false;
}

void Floor::clean_tile(pos_t pos)
{
	*(tiles + get_height(pos.y) * wCount + get_width(pos.x)) = false;
}

void Floor::destroy()
{
	free(tiles);
}

errorType_t Floor::get_err()
{

	return err;
}
