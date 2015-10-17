#pragma once
#include "Grids.h"
#include <vector>
using namespace std;

class Mechanic
{
public:
	Mechanic();
	~Mechanic();

	void moveObject(Object*, int, int); //przenosi obiekt do wybranej lokalizacji

private:
	//magic numbers
	static const int MAP_X_SIZE = 10;
	static const int MAP_Y_SIZE = 10;

	Grid* _map[MAP_X_SIZE][MAP_Y_SIZE];
	vector<Object*> _objects;
	vector<Grid*> _grids;



};

