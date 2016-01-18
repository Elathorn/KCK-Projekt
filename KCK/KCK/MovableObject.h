#pragma once
#include "string"
#include "TextureManager.h"
#include <SFML\Graphics.hpp>
using namespace std;

class MovableObject 
{
public:
	MovableObject(TextureManager *TM, int posX, int posY, string color, string size);
	~MovableObject();
	void setSprite(sf::Sprite * newSprite) { _sprite = newSprite; }
	sf::Sprite* getSprite() { return _sprite; }
	string getSize() { return _size; }
	string getColor() { return _color; }
    string getColorPL();

	int getLocationXAxis() { return _locationXAxis; }
	int getLocationYAxis() { return _locationYAxis; }

	int move(int, int); //zmienia pozycje pude³ka. Dla -1 zachowuje dan¹ pozycje bez zmiany

private:
	sf::Sprite* _sprite = NULL;
	string _size;
	string _color;
	int _locationXAxis;
	int _locationYAxis;

	sf::Color _convertStringToColor(string colorStr);
};

