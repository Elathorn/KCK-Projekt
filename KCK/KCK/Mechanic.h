#pragma once
#include "Grids.h"
#include "ErrorHandler.h"
#include "Logger.h"
#include <vector>
#include "TextureManager.h"
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
	MovableObject* findMovableObject(string color); //wyszukuje pierwszy obiekt o danym kolorze
	MovableObject* findMovableObject(string color, string size) //override dla starej wersji wyszukiwania
	{
		return findMovableObject(color);
	}
	Shelf* findShelf(string locationStr);

	Grid* getGrid(int locX, int locY);
	vector<Shelf*> getShelvesVec() { return _shelvesVec; }
	void mapCreator(TextureManager* TM);

private:
	Grid* _map[MAP_X_SIZE][MAP_Y_SIZE];

	vector<MovableObject*> _movableObjectsVec;
	vector<Shelf*> _shelvesVec;
	Grid* _emptyGrid;

	

};

