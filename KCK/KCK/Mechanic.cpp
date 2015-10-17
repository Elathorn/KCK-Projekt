#include "Mechanic.h"



Mechanic::Mechanic()
{
	_emptyGrid = new Grid();
	for (int x = MAP_X_SIZE-1; x > 0; x--)
	{
		for (int y = 0; y < MAP_Y_SIZE; y++)
			_map[x][y] = _emptyGrid; //wype³nienie ca³ej mapy pustk¹
	}

	//tmp
	_map[5][5] = new Shelf(0, 0, NULL, NULL, NULL);
	//end of tmp
}


Mechanic::~Mechanic()
{
}

void Mechanic::moveObject(Shelf* newShelf, Object * object, char shelfLvl)
{
	//search on shelf
	object->move(newShelf->getLocationX(), newShelf->getLocationY()); //zmieniamy koordytany obiektu (pude³ka)
	newShelf->setShelf(object, shelfLvl);
}
