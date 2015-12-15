#pragma once
#include "string"
#include <SFML\Graphics.hpp>
using namespace std;

class MovableObject 
{
public:
	MovableObject(int posX, int posY, string color, string size);
	~MovableObject();
	void setSprite(sf::Sprite * newSprite) { _sprite = newSprite; }
	sf::Sprite* getSprite() { return _sprite; }
	string getSize() { return _size; }
	string getColor() { return _color; }
	int getLocationXAxis() { return _locationXAxis; }
	int getLocationYAxis() { return _locationYAxis; }

	int move(int, int); //zmienia pozycje pude³ka. Dla -1 zachowuje dan¹ pozycje bez zmiany

private:
	sf::Sprite* _sprite = NULL;
	string _size;
	string _color;
	int _locationXAxis;
	int _locationYAxis;
};

