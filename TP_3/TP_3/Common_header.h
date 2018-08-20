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
#define CLEAN false
#define DIRTY true
#define PI 3.14159265359
#define PRECISION 1000
#define MAX_SIM 10000
#define MIN_DIF_SIM 0.1
#define AVERAGE_CONST 1000
#define _DEBUG_ 0

/**********************************
TYPEDEFS AND NAMESPACE
**********************************/
using namespace std;

typedef unsigned int uint;

typedef enum { NO_ERROR, NO_MEM, AL_INIT_ERROR, AL_DISPLAY_ERROR, AL_ADDON_ERROR, AL_IMAGE_ERROR, AL_FONT_ERROR} errNo_t;

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

/*******************************
FUNCTION PORTOTIPES
*******************************/


#endif