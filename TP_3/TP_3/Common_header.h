#ifndef _HEADER_H
#define _HEADER_H
/**********************************
INCLUDES
**********************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>

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

typedef enum { NO_ERROR, NO_MEM, AL_INIT_ERROR, AL_DISPLAY_ERROR, AL_ADDON_ERROR, AL_IMAGE_ERROR } errNo_t;

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