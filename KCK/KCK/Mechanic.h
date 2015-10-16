#pragma once
#include "Grids.h"
class Mechanic
{
public:
	Mechanic();
	~Mechanic();
private:
	//magic numbers
	static const int MAP_X_SIZE = 10;
	static const int MAP_Y_SIZE = 10;

	int _map[MAP_X_SIZE][MAP_Y_SIZE];




};

