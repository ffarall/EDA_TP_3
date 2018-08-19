#include "Simulator.h"


Simulator::
Simulator(uint rc, string Mod, uint w, uint h) :p(w, h)//,d( , , ...)//dibujator d
{
	//robots = new Robot[rc]; //es el malloc de c++. se destruye con delete robot[](en el metodo destroy)
	robotCount = rc;
	mode = Mod;
	for (uint i = 0; i < rc; i++)
	{
		//robots[i].init_robot(w, h);
	}
	tickCount = 0;
	err.errorNum = NO_ERROR;
}

