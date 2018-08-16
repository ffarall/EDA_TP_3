#pragma once
#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "Link.h"

class Simulation
{
	uint tickCount;
	string mode;
	uint robotCount;
	Robot * robots;
	Floor p;
	errorType err;
	//graphics d; //graphics class que se encarga de dibujar(metodos para graficar, cosas de allegro por ejemplo)
	//void step(); //entonces step es solo de simulation


public:

	Simulation(uint robotCount, string Mode, uint w, uint h);

	//void step(); //si no esta el dibujator

	string getMode();

	uint simulate();
	uint getTickCount();
	uint getRobotCount();
	void destroy();
	errorType getError();
};

#endif
