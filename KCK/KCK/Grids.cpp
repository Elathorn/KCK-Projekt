#include "Grids.h"


Grid::Grid()
{
}


Shelf::Shelf(int locationXAxis, int locationYAxis, Object* topShelf, Object* midShelf, Object* botShelf) 
{
	_locationXAxis = locationXAxis;
	_locationYAxis = locationYAxis;
	_topShelf = topShelf;
	_midShelf = midShelf;
	_botShelf = botShelf;
}



Object * Shelf::getTopShelf()
{
	if (_topShelf != nullptr)
		return nullptr;
	else
		return _topShelf;
}

Object * Shelf::getMidShelf()
{
	if (_midShelf != nullptr)
		return nullptr;
	else
		return _midShelf;
}

Object * Shelf::getBotShelf()
{
	if (_botShelf != nullptr)
		return nullptr;
	else
		return _botShelf;
}

Object* Shelf::getShelf(char shelfPos)
{
	switch (shelfPos)
	{
	case (TOP_SHELF) : return _topShelf;
	case (MID_SHELF) : return _midShelf;
	case (BOT_SHELF) : return _botShelf;
	default: return nullptr;
	}
}

void Shelf::setShelf(Object * newObj, char pos)
{
	switch (pos)
	{
	case (TOP_SHELF) : _topShelf = newObj; break;
	case (MID_SHELF) : _midShelf = newObj; break;
	case (BOT_SHELF) : _botShelf = newObj; break;
	}
}

char Shelf::searchShelves(Object * obj)
{
	if (_topShelf == obj)
		return TOP_SHELF;
	if (_midShelf == obj)
		return MID_SHELF;
	if (_botShelf == obj)
		return BOT_SHELF;
	return NO_SHELF;
}

