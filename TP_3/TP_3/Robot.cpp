#include "Robot.h"



Robot::Robot()
{
}


Robot::~Robot()
{
}

void Robot::init_robot(uint hCount, uint wCount)
{
	srand(NULL);
	pos.x = (rand() % (wCount*PRECISION)) / PRECISION;
	pos.y = (rand() % (hCount*PRECISION)) / PRECISION;
	dir = (rand() % 360)*PI/180;
}

void Robot::move_robot(double distanceUnit)
{
	pos_t distanceToWall = { wCount * distanceUnit - pos.x, hCount * distanceUnit - pos.y };
	double dx = distanceUnit * cos(dir);
	double dy = distanceUnit * sin(dir);
	if (pos.x + dx > 0 && pos.x < distanceToWall.x && pos.y > 0 && pos.y < distanceToWall.y)
	{
		pos.x += dx;
		pos.y += dy;
	}
	srand(NULL);
	dir = (rand() % 360)*PI / 180;
}
