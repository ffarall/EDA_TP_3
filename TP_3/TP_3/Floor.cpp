#include "Floor.h"



Floor::Floor()
{
}


Floor::~Floor()
{
}


Floor::Floor(uint h, uint w)
{
	Wcount = w;
	Hcount = h;
	baldosas = (bool *)malloc(h * w * sizeof(bool));
	if (baldosas != NULL)
	{
		for (int i = 0; i < w*h; i++)
		{
			baldosas[i] = DIRTY;
		}
		err.errorNum = NO_ERROR;
	}
	else
	{
		err.errorNum = NO_MEM;
		err.detail = "No memory in Piso constructor";
	}
}

void Floor::
cleanTile(uint x, uint y)
{
	if (x < Wcount && y < Hcount)
	{
		baldosas[x + y * Wcount] = CLEAN;
	}
}

void Floor::
cleanTile(pos_t pos)
{
	cleanTile((uint)floor(pos.x), (uint)floor(pos.y));
}
