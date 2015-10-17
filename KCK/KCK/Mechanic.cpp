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
	//end of tmp


	//tmp objects
	MovableObject* obj;
	obj = new MovableObject(5, 5, "red", "big");
	_movableObjects.push_back(obj);
	//end of tmp
	//tmp shelves
	Grid* shelf;
	shelf = new Shelf(5, 5, obj, NULL, NULL);
	_map[5][5] = shelf;
	_grids.push_back(shelf);
	//end of tmp shelves
}


Mechanic::~Mechanic()
{
}

void Mechanic::moveObject(Shelf* newShelf, MovableObject * movableObject, char shelfLvl)
{
	Shelf* oldShelf = dynamic_cast<Shelf*>(_map[movableObject->getLocationXAxis()][movableObject->getLocationYAxis()]);
	if (oldShelf == NULL) //jeœli wybrany grid jakimœ cudem nie jest pó³k¹
	{
		ErrorHandler::errorMessage(ErrorHandler::GRID_IS_NOT_A_SHELF, "");
		return;
	}
	oldShelf->setShelf(NULL,(oldShelf->searchShelves(movableObject))); //usuniêcie pude³ka z starej lokalizacji
	movableObject->move(newShelf->getLocationX(), newShelf->getLocationY()); //zmieniamy koordytany obiektu (pude³ka)
	newShelf->setShelf(movableObject, shelfLvl); //dodajemy pude³ko na nowej lokalizacji
	return;
}

MovableObject * Mechanic::findMovableObject(string color, string size)
{
	for (auto & it : _movableObjects)
	{ //szuka przedmiotu o takim samym kolorze i rozmiarze
		if ((color == "" || color == it->getColor()) && (size == "" || size == it->getSize()))
			return it;
	}
	return NULL;
}
