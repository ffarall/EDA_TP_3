#pragma once
class Robot
{
	pos_t pos;
	double dir;
	uint hCount;
	uint wCount;

public:

	void initRobot(uint Hcount, uint Wcount);
	void moveRobot(void);
	pos_t getRobotPos();
};
//cosas que agregue
#pragma once
#ifndef _ROBOT_H
#define _ROBOT_H

#include "Header.h"

class Robot
{
	pos_t pos;
	double dir;
	uint Hcount;
	uint Wcount;

public:

	void initRobot(uint Hcount, uint Wcount);
	void moveRobot(void);
	pos_t getRobotPos();
};

#endif