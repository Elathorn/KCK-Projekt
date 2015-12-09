#include "Grids.h"
#include "IOManager.h"

#define GRID_TO_WINDOW_RATIO 45
#define SHELF_SCALE_RATIO 0.1

Grid::Grid()
{
}


Shelf::Shelf(int locationXAxis, int locationYAxis, MovableObject* topShelf, MovableObject* midShelf, MovableObject* botShelf) 
{
	_locationXAxis = locationXAxis;
	_locationYAxis = locationYAxis;
	_topShelf = topShelf;
	_midShelf = midShelf;
	_botShelf = botShelf;

	//@todo : zmieniæ to ³adnie wszystko
	_sprite = IOManager::loadSpriteFromFile("shelftopdown.png");
	_sprite->scale(SHELF_SCALE_RATIO, SHELF_SCALE_RATIO);
	setSpritePositionOnWindow();
}



MovableObject * Shelf::getTopShelf()
{
	if (_topShelf == nullptr)
		return nullptr;
	else
		return _topShelf;
}

MovableObject * Shelf::getMidShelf()
{
	if (_midShelf == nullptr)
		return nullptr;
	else
		return _midShelf;
}

MovableObject * Shelf::getBotShelf()
{
	if (_botShelf == nullptr)
		return nullptr;
	else
		return _botShelf;
}

MovableObject* Shelf::getShelf(char shelfPos)
{
	switch (shelfPos)
	{
	case (TOP_SHELF) : return getTopShelf();
	case (MID_SHELF) : return getMidShelf();
	case (BOT_SHELF) : return getBotShelf();
	default: return nullptr;
	}
}

void Shelf::setShelf(MovableObject * newObj, char pos)
{
	switch (pos)
	{
	case (TOP_SHELF) : _topShelf = newObj; break; //todo: zabezpieczenie przed nadpisaniem paczki?
	case (MID_SHELF) : _midShelf = newObj; break;
	case (BOT_SHELF) : _botShelf = newObj; break;
	}
}

char Shelf::searchShelves(MovableObject * obj)
{
	if (_topShelf == obj)
		return TOP_SHELF;
	if (_midShelf == obj)
		return MID_SHELF;
	if (_botShelf == obj)
		return BOT_SHELF;
	return NO_SHELF;
}

void Shelf::setSpritePositionOnWindow()
{
	_sprite->setOrigin(30, 15);
	_sprite->setPosition(_locationXAxis * GRID_TO_WINDOW_RATIO //- _sprite->getGlobalBounds().width / 2
		,_locationYAxis * GRID_TO_WINDOW_RATIO);//- _sprite->getGlobalBounds().width/2);

	//ustalenie rotacji
	enum locationGeo { NORTH = 0, EAST, SOUTH, WEST };
	int rotation; 
	//@todo: zrobic to sensownie
	if (_locationYAxis < 1)
		rotation = NORTH;
	else if (_locationYAxis > 8)
		rotation = SOUTH;
	else if (_locationXAxis < 3)
		rotation = WEST;
	else rotation = EAST;

	
	_sprite->setRotation(rotation * 90);
}

