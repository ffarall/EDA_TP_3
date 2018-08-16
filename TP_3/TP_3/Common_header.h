#ifndef _HEADER_H
#define _HEADER_H
/**********************************
INCLUDES
**********************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

/**********************************
DEFINES
**********************************/
#define CLEAN true
#define DIRTY false

/**********************************
TYPEDEFS AND NAMESPACE
**********************************/
using namespace std;

typedef unsigned int uint;

typedef enum { NO_ERROR, NO_MEM } errNo_t;

typedef struct
{
	string detail;
	errNo_t errorNum;
}errorType;

typedef struct
{
	double x;
	double y;
}pos_t;

#endif