#include "Grids.h"


Grid::Grid(int locationXAxis, int locationYAxis)
{
	_locationXAxis = locationXAxis;
	_locationYAxis = locationYAxis;
}


Shelf::Shelf(int locationXAxis, int locationYAxis, Object* topShelf, Object* midShelf, Object* botShelf) 
	: Grid(locationXAxis, locationYAxis)
{
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
