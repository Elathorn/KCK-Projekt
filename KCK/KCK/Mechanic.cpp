#include "Mechanic.h"



Mechanic::Mechanic()
{
	for (int x = 0; x < MAP_X_SIZE; x++)
	{
		for (int y = 0; y < MAP_Y_SIZE; y++)
			_map[x][y] = nullptr;
	}
}


Mechanic::~Mechanic()
{
}
