#include "Robot.h"



Robot::Robot()
{
}


Robot::~Robot()
{
}

void Robot::init_robot(uint h, uint w)
{
	pos.x = rand() % (w*PRECISION);
	pos.x /= PRECISION;
	pos.y = rand() % (h*PRECISION);
	pos.y /= PRECISION;
	dir = (rand() % 360)*PI/180;

	hCount = h;
	wCount = w;
}

void Robot::move_robot(double distanceUnit)
{
#if _DEBUG_
	cout << pos.x << endl;
	cout << pos.y << endl;
	cout << dir << endl;
#endif
	pos_t distanceToWall = { wCount * distanceUnit, hCount * distanceUnit };
	double dx = distanceUnit * cos(dir);
	double dy = distanceUnit * sin(dir);
	if ((pos.x + dx) > 0 && (pos.x + dx) < distanceToWall.x && (pos.y + dy) > 0 && (pos.y + dy) < distanceToWall.y)
	{
		pos.x += dx;
		pos.y += dy;
	}
	else
	{
		dir = (rand() % 360)*PI / 180;
	}
#if _DEBUG_
	cout << pos.x << endl;
	cout << pos.y << endl;
	cout << dir << endl;
#endif
}

pos_t Robot::get_robotPos()
{
	return pos;
}
