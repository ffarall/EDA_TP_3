
#include "callback.h"
int
cmd_line_interpreter(char *key, char *value, void *data)
{
	int ret = 1;
	robotSimData_n *simData = data;
	if (key != NULL)
	{
		if (!str_case_cmp(key, "width"))
		{
			if (strisalpha(value))
			{
				simData->errorType = ERR_ALPHA_WIDTH;
				ret = 0;
			}
			else
			{
				int width = atoi(value, NULL);
				if (valid_width(width))
				{
					if (simData->w == 0)
					{
						simData->w = width;
					}
					else
					{
						simData->errorType = ERR_OVERWRITE;
						ret = 0;
					}
				}
				else
				{
					simData->errorType = ERR_WRONG_WIDTH;
					ret = 0;
				}
			}
		}
		else if (!str_case_cmp(key, "height"))
		{
			if (strisalpha(value))
			{
				simData->errorType = ERR_ALPHA_HEIGHT;
				ret = 0;
			}
			else
			{
				int height = atoi(value, NULL);
				if (valid_height(height))
				{
					if (valid_width(height))
					{
						if (simData->h == 0)
						{
							simData->h = height;
						}
						else
						{
							simData->errorType = ERR_OVERWRITE;
							ret = 0;
						}
					}
				}
				else
				{
					simData->errorType = ERR_WRONG_HEIGHT;
					ret = 0;
				}
			}
		}
		else if (!str_case_cmp(key, "robots"))
		{
			if (strisalpha(value))
			{
				simData->errorType = ERR_ALPHA_ROBOTS;
				ret = 0;
			}
			else
			{
				int robots = atoi(value, NULL);
				if (valid_robots(robots))
				{
					if (simData->robotCount == 0)
					{
						simData->robotCount = robots;
					}
					else
					{
						simData->errorType = ERR_OVERWRITE;
						ret = 0;
					}
				}
				else
				{
					simData->errorType = ERR_WRONG_ROBOTS;
					ret = 0;
				}
			}
		}

		else if (!str_case_cmp(key, "modo"))
		{
			if (strisalpha(value))
			{
				simData->errorType = ERR_ALPHA_MODO;
				ret = 0;
			}
			else
			{
				int modo = atoi(value, NULL);
				if (valid_modo(modo))
				{
					if (simData->mode == 0)
					{
						simData->mode = modo;
					}
					else
					{
						simData->errorType = ERR_OVERWRITE;
						ret = 0;
					}
				}
				else
				{
					simData->errorType = ERR_WRONG_MODO;
					ret = 0;
				}
			}
		}
		else
		{
			simData->errorType = ERR_UNKNOWN_KEY;
			ret = 0;
		}
	}
	else
	{
		simData->errorType = ERR_NO_KEY;
		ret = 0;
	}

	return ret;
}

int str_case_cmp(char * str1, char * str2)
{
	char auxStr1[100];
	char auxStr2[100];
	strcpy_s(auxStr1, 100, str1);
	str_to_lwr(auxStr1);
	strcpy_s(auxStr2, 100, str2);	// Uso strcpy_s porque usando strcpy Visual me hacia saltar un error.
	str_to_lwr(auxStr2);

	return strcmp(auxStr1, auxStr2);
}

void str_to_lwr(char * str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (isupper(*(str + i)))
		{
			*(str + i) = tolower(*(str + i));
		}
		i++;
	}
}

int valid_width(int width)
{
	return (width > 0 && width <= 70);
}

int valid_height(int height)
{
	return (height > 0 && height < 100);
}

int valid_robots(int robots)
{
	return (robots > 0);
}

int valid_modo(int modo)
{
	return (modo == 1 || modo == 2);
}

int valid_data(robotSimData_n * data)
{
	int ret = 1;
	if (data->mode == 1)
	{
		if (!valid_mode1(data))
		{
			fprintf(stderr, "Los parametros ingresados son incorrectos.\n El modo 1 recibe width, height y robots.\n");
			ret = 0;
		}
	}
	else if (data->mode == 2)
	{
		if (!valid_mode2(data))
		{
			fprintf(stderr, "Los parametros ingresados son incorrectos.\n El modo 2 recibe width y height.\n");
			ret = 0;
		}
	}
	else
	{
		fprintf(stderr, "Se ingreso un modo no esperado.\n Se espera recibir modo 1 o 2.\n");
		ret = 0;
	}
	
	return ret;
}

void how_to(int error)
{
	switch (error)
	{
	case ERR_NO_KEY: fprintf(stderr, "Se recibio un argumento sin un key.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_WRONG_WIDTH: fprintf(stderr, "Parametro width fuera de rango.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_WRONG_HEIGHT: fprintf(stderr, "Parametro height fuera de rango.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_WRONG_ROBOTS: fprintf(stderr, "Parametro robots fuera de rango.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_WRONG_MODO: fprintf(stderr, "Parametro modo fuera de rango.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_UNKNOWN_KEY: fprintf(stderr, "Se ingreso una key no reconocida.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_ALPHA_WIDTH: fprintf(stderr, "Se ingresaron caracteres invalidos en width.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_ALPHA_HEIGHT: fprintf(stderr, "Se ingresaron caracteres invalidos en height.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_ALPHA_ROBOTS: fprintf(stderr, "Se ingresaron caracteres invalidos en robots.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_ALPHA_MODO: fprintf(stderr, "Se ingresaron caracteres invalidos en modo.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	case ERR_OVERWRITE: fprintf(stderr, "Se ingresaron parametros por duplicado.\nEl programa recibe por línea de comandos, el tamaño del piso (Width y Heigh), la cantidad de robots (Robots) y el modo de la simulación (Modo), con width entre 1 y 70, y height entre 1 y 100.\n"); break;
	}
}

int strisalpha(char * str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (isalpha(*(str + i)))
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int valid_mode1(robotSimData_n * data)
{
	int areArgsValid = (!isnan(data->w) && !isnan(data->h) && !isnan(data->robotCount));
	return (areArgsValid);
}

int valid_mode2(robotSimData_n * data)
{
	int areArgsValid = (!isnan(data->w) && !isnan(data->h));
	return (areArgsValid);
}
