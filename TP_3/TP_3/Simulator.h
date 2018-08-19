#ifndef _SIMULATOR_
#define	_SIMULATOR_

#include "Common_Header.h"
#include "Floor.h"
#include "Robot.h"

class Simulator
{
	uint tickCount;
	string mode;
	uint robotCount;
	//Robot * robots;
	Floor p;
	errorType_t err;
public:
	Simulator(uint robotCount, string mode, uint w, uint h);
	~Simulator();

	string getMode();

	uint simulate();
	uint get_tickCount();
	uint get_robotCount();
	void destroy();
	errNo_t get_error();
};

#endif // !_SIMULATOR_