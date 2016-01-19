#include "MovableObject.h"
using namespace sf;



MovableObject::MovableObject(TextureManager* TM, int LocationXAxis, int LocationYAxis, string color, string size)
{
	_locationXAxis = LocationXAxis;
	_locationYAxis = LocationYAxis;
	_color = color;
	_size = size;
	_sprite = new Sprite(*TM->getTexture("box"));
	_sprite->setScale(0.1, 0.1);
	_sprite->setColor(_convertStringToColor(color));
}

MovableObject::~MovableObject()
{
}

string MovableObject::getColorPL()
{
    string colorStr = this->getColor();
    if (colorStr == "red")
        return "czerwona";
    else if (colorStr == "blue")
        return "niebieska";
    else if (colorStr == "yellow")
        return "zolta";
    else if (colorStr == "black")
        return "czarna";
    else if (colorStr == "white")
        return "biala";
    else if (colorStr == "green")
        return "zielona";
    return "niemozliwe, getColorPL error"; //nie powinno sie nigdy zdarzyc
}

int MovableObject::move(int newX, int newY)
{
	if (newX != -1)
		_locationXAxis = newX;
	if (newY != -1)
		_locationYAxis = newY;
	return 0;
}

Color MovableObject::_convertStringToColor(string colorStr)
{
	if (colorStr == "red")
		return Color::Red;
	else if (colorStr == "blue")
		return Color::Blue;
	else if (colorStr == "yellow")
		return Color::Yellow;
	else if (colorStr == "black")
		return Color::Black;
	else if (colorStr == "white")
		return Color::White;
	else if (colorStr == "green")
		return Color::Green;
	return Color::Transparent;
}



