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
#define PI 3.14159265359
#define PRECISION 1000

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
}errorType_t;

typedef struct
{
	double x;
	double y;
}pos_t;

#endif