#pragma once
#include "Grids.h"
#include "ErrorHandler.h"
#include "Logger.h"
#include <vector>
using namespace std;

class Mechanic
{
public:
	//magic numbers
	static const int MAP_X_SIZE = 11;
	static const int MAP_Y_SIZE = 11;

	static const int SHELF_IS_FULL = 1;
	//
	
	Mechanic();
	~Mechanic();

	int moveObject(Shelf*, MovableObject*, char); //przenosi obiekt do wybranej lokalizacji
	MovableObject* findMovableObject(string color, string size); //wyszukuje pierwszy obiekt o danej charakterystyce, "" dla braku danych
	Shelf* findShelf(string locationStr);

	Grid* getGrid(int locX, int locY);
	vector<Shelf*> getShelvesVec() { return _shelvesVec; }

private:
	Grid* _map[MAP_X_SIZE][MAP_Y_SIZE];

	vector<MovableObject*> _movableObjectsVec;
	vector<Shelf*> _shelvesVec;
	Grid* _emptyGrid;

	void _mapCreator();

};

