#ifndef _ROBOT_H
#define _ROBOT_H

#include "Common_header.h"

class Robot
{
	pos_t pos;
	double dir;
	uint hCount;
	uint wCount;

public:

	void init_robot(uint Hcount, uint Wcount);
	void move_robot(void);
	pos_t get_robotPos();
};

#endif