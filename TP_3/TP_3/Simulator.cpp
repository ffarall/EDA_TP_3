#include "Simulator.h"


Simulator::
Simulator(uint rc, uint mod, uint w, uint h, double u) :floor(w, h)//,d( , , ...)//dibujator d
{
	robots = new Robot[rc]; //es el malloc de c++. se destruye con delete robot[](en el metodo destroy)
	robotCount = rc;
	mode = mod;
	unit = u;
	for (int i = 0; i < rc; i++)
	{
		robots[i].init_robot(w, h);
	}
	tickCount = 0;
	err.errorNum = NO_ERROR;
}


Simulator::~Simulator()
{
}

uint Simulator::getMode()
{
	return mode;
}

uint Simulator::simulate()
{
	if (mode == 1)
	{
		while (!(floor.is_floorClean()))
		{
			one_sim();
			tickCount++;

			cout << "Tick simulation" << endl;	// CAMBIAR POR DIBUJAR EL PISO
			getchar();							// CAMBIAR POR ESPERA EN SEGUNDOS
		}
		cout << "Simulation finished" << endl;

		return tickCount;
	}
	else if (mode == 2)
	{
		while (!(floor.is_floorClean()))
		{
			one_sim();
			tickCount++;
		}

		return tickCount;
	}
}

void Simulator::one_sim()
{
	for (int i = 0; i < robotCount; i++)
	{
#if _DEBUG_
		cout << "Robot " << i << endl;
#endif // _DEBUG_

		pos_t robotPos = robots[i].get_robotPos();
		if (floor.is_dirty(floor.get_width(robotPos.x), floor.get_height(robotPos.y)))	// Se limpia la baldoza donde está el robot.
		{
			floor.clean_tile(robotPos);
		}

		robots[i].move_robot(unit);	// Se mueve al robot.
	}
}

uint Simulator::get_tickCount()
{
	return tickCount;
}

uint Simulator::get_robotCount()
{
	return robotCount;
}

void Simulator::restart_tickCount()
{
	tickCount = 0;
}

void Simulator::destroy()
{
	delete[] robots;
	floor.destroy();
}

errorType_t Simulator::get_error()
{
	return err;
}
