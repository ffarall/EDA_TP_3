#include "Robot.h"
#include "Floor.h"
#include "Simulator.h"
#include "Drawer.h"
extern "C"
{
#include "parse_cmd_line.h"
#include "callback.h"
}

int
main(int argc, char **argv)
{

	robotSimData_n argsData = { 0, 0, 0, 0, 0 }; // Se inicializa con valores que los datos no pueden tomar para luego hacer su comparación y validación
	if (parseCmdLine(argc, argv, cmd_line_interpreter, &argsData) == ERROR)
	{
		how_to(argsData.errorType);

		getchar();
		return -1;
	}
	else
	{
		if (!valid_data(&argsData))
		{

			getchar();
			return -1;
		}
	}

	double unit = 1;
	srand(time(NULL));

	if (argsData.mode == 1)
	{
		Simulator sim(argsData.robotCount, argsData.mode, argsData.w, argsData.h, unit);
		uint tickCount = sim.simulate();
		cout << tickCount << endl;
		sim.destroy();
	}
	else if (argsData.mode == 2)
	{
		double tickCounters[MAX_SIM] = { 0 };
		bool start = true;
		int j;
		cout << "Loading..." << endl;
		for (j = 1; (start || abs(tickCounters[j - 2] - tickCounters[j - 3]) > MIN_DIF_SIM) && j < MAX_SIM; j++)
		{
			if (j > 1)
			{
				start = 0;
			}
			for (int i = 0; i < AVERAGE_CONST; i++)
			{
				Simulator sim(j, argsData.mode, argsData.w, argsData.h, unit);
				tickCounters[j - 1] += sim.simulate();
				sim.destroy();
			}
			
			tickCounters[j - 1] /= AVERAGE_CONST; //promedio de ticks para #j robots
		}
		cout << "Apriete cualquier boton para salir." << endl;
		Drawer draw(tickCounters, j);
		draw.allegro_init();
		draw.draw_graph();
		getchar();
		draw.allegro_destroy();

	}

	getchar();

	return 0;
}