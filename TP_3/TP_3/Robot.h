#ifndef _ROBOT_H
#define _ROBOT_H

#include "Common_header.h"
#include <time.h>

class Robot
{
	pos_t pos;
	double dir;
	uint hCount;
	uint wCount;

public:
	Robot();
	~Robot();

	void init_robot(uint h, uint w);
	void move_robot(double unit);
	pos_t get_robotPos();
};

#endif