#include "MovableObject.h"




MovableObject::MovableObject(int LocationXAxis, int LocationYAxis, string color, string size)
{
	_locationXAxis = LocationXAxis;
	_locationYAxis = LocationYAxis;
	_color = color;
	_size = size;
}

MovableObject::~MovableObject()
{
}

int MovableObject::move(int newX, int newY)
{
	if (newX != -1)
		_locationXAxis = newX;
	if (newY != -1)
		_locationYAxis = newY;
	return 0;
}

