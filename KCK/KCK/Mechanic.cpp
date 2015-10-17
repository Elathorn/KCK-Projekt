#include "Mechanic.h"



Mechanic::Mechanic()
{
	_emptyGrid = new Grid();
	for (int x = MAP_X_SIZE-1; x >= 0; x--)
	{
		for (int y = 0; y < MAP_Y_SIZE; y++)
			_map[x][y] = _emptyGrid; //wype³nienie ca³ej mapy pustk¹
	}

	//tmp
	//end of tmp


	//tmp objects
	MovableObject* obj;
	obj = new MovableObject(MAP_X_SIZE-1, MAP_Y_SIZE /2, "red", "big");
	_movableObjectsVec.push_back(obj);
	//end of tmp
	//tmp shelves
	Grid* shelf;
	shelf = new Shelf(MAP_X_SIZE-1, MAP_Y_SIZE /2, obj, NULL, NULL);
	_map[MAP_X_SIZE-1][MAP_Y_SIZE/2] = shelf;
	Shelf* shelf2 = dynamic_cast<Shelf*>(shelf);
	_shelvesVec.push_back(shelf2);


	obj = new MovableObject(0, MAP_Y_SIZE / 2, "green", "small");
	_movableObjectsVec.push_back(obj);
	shelf = new Shelf(0, MAP_Y_SIZE / 2, obj, NULL, NULL);
	_map[0][MAP_Y_SIZE / 2] = shelf;
	shelf2 = dynamic_cast<Shelf*>(shelf);
	_shelvesVec.push_back(shelf2);
	//end of tmp shelves
}


Mechanic::~Mechanic()
{

}

int Mechanic::moveObject(Shelf* newShelf, MovableObject * movableObject, char shelfLvl)
{
	Shelf* oldShelf = dynamic_cast<Shelf*>(_map[movableObject->getLocationXAxis()][movableObject->getLocationYAxis()]);
	if (oldShelf == NULL) //jeœli wybrany grid jakimœ cudem nie jest pó³k¹
	{
		ErrorHandler::errorMessage(ErrorHandler::GRID_IS_NOT_A_SHELF, "");
		return 0;
	}
	if (newShelf->getShelf(shelfLvl) != NULL)//sprawdzenie, czy nowy pó³ka nie jest pe³na
		return SHELF_IS_FULL;
	oldShelf->setShelf(NULL,(oldShelf->searchShelves(movableObject))); //usuniêcie pude³ka z starej lokalizacji
	movableObject->move(newShelf->getLocationX(), newShelf->getLocationY()); //zmieniamy koordytany obiektu (pude³ka)
	newShelf->setShelf(movableObject, shelfLvl); //dodajemy pude³ko na nowej lokalizacji
	return 0;
}

MovableObject * Mechanic::findMovableObject(string color, string size)
{
	for (auto & it : _movableObjectsVec)
	{ //szuka przedmiotu o takim samym kolorze i rozmiarze
		if ((color == "" || color == it->getColor()) && (size == "" || size == it->getSize()))
			return it;
	}
	return NULL;
}

Shelf * Mechanic::findShelf(string locationStr)
{
	int locationX, locationY;
	if (locationStr == "north")
	{
		locationY = MAP_Y_SIZE-1;
		locationX = MAP_X_SIZE / 2;
	}
	if (locationStr == "south")
	{
		locationY = 0;
		locationX = MAP_X_SIZE / 2;
	}
	if (locationStr == "east")
	{
		locationY = MAP_Y_SIZE / 2;
		locationX = MAP_X_SIZE-1;
	}
	if (locationStr == "west")
	{
		locationY = MAP_Y_SIZE / 2;
		locationX = 0;
	}
	for (auto & it : _shelvesVec)
	{
		if (it->getLocationX() == locationX && it->getLocationY() == locationY)
			return it;
	}
	return NULL;
}
