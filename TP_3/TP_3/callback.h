
#ifndef _CALLBACK_
#define _CALLBACK_

/*****************************************
INCLUDES
*****************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*****************************************
DEFINES
*****************************************/
#define ERR_NO_KEY 256
#define ERR_WRONG_WIDTH 258
#define ERR_WRONG_HEIGHT 259
#define ERR_WRONG_ROBOTS 260
#define ERR_WRONG_MODO 261
#define ERR_UNKNOWN_KEY 263
#define ERR_ALPHA_WIDTH 265
#define ERR_ALPHA_HEIGHT 266
#define ERR_ALPHA_ROBOTS 267
#define ERR_ALPHA_MODO 268
#define ERR_OVERWRITE 271
#define OCTOGON_DISP_WIDTH 800
#define OCTOGON_DISP_HEIGHT 800


/*****************************************
TYPEDEFS
*****************************************/
typedef unsigned int uint;
typedef struct
{
	uint w;
	uint h;
	uint robotCount;
	uint mode;
	int errorType;
}robotSimData_n;

/*****************************************
FUN PROTOTIPES
*****************************************/
int
	cmd_line_interpreter(char *key, char *value, void *data);
int
	str_case_cmp(char *str1, char *str2);					// Max 100 characters per string.
void
	str_to_lwr(char *str);
int
	valid_width(int width);
int
	valid_height(int height);
int
	valid_modo(int modo);
int
	valid_data(robotSimData_n * data);
int
	valid_mode1(robotSimData_n * data);
void
	how_to(int error);
int
	strisalpha(char *str);
int
	valid_mode2(robotSimData_n * data);


#endif // _CALLBACK_

