#pragma once
#include "Grids.h"
#include <vector>
using namespace std;

class Mechanic
{
public:
	//magic numbers
	static const int MAP_X_SIZE = 10;
	static const int MAP_Y_SIZE = 10;
	//
	
	Mechanic();
	~Mechanic();

	void moveObject(Shelf*, Object*, char); //przenosi obiekt do wybranej lokalizacji

	

	Grid* _map[MAP_X_SIZE][MAP_Y_SIZE];
private:

	vector<Object*> _objects;
	vector<Grid*> _grids;
	Grid* _emptyGrid;



};

