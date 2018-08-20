#ifndef _SIMULATOR_
#define	_SIMULATOR_

#include "Common_Header.h"
#include "Floor.h"
#include "Robot.h"
#include "Drawer.h"

class Simulator
{
	uint tickCount;
	uint mode;
	uint robotCount;
	Robot * robots;
	Floor floor;
	Drawer draw;
	double unit;
	errorType_t err;

	void one_sim();
public:
	Simulator(uint rc, uint mod, uint w, uint h, double u);
	~Simulator();

	uint getMode();

	uint simulate();
	uint get_tickCount();
	uint get_robotCount();
	void restart_tickCount();
	void destroy();
	errorType_t get_error();
};

#endif // !_SIMULATOR_