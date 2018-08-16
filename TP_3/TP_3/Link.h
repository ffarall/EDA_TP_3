#pragma once
#pragma once
#ifndef _LINK_H
#define _LINK_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Floor.h"
#include "Robot.h"
#include "Simulator.h"

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