#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Piso.h"
#include "Robot.h"
#include "Simulation.h"

using namespace std;

typedef unsigned int uint;

typedef enum { NO_ERROR, NO_MEM }errNo;

typedef struct
{
	string detail;
	errNo errorNum;
}errorType;

typedef struct
{
	double x;
	double y;
}pos_t;

#endif