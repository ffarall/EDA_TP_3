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
			tiles[i] = true; // Se inicializan las baldozas sucias
		}
		err.errorNum = NO_ERROR;
	}
	else
	{
		err.errorNum = NO_MEM;
		err.detail = "No memory in construction of Floor.\n"
	}
}

Floor::~Floor()
{
}
