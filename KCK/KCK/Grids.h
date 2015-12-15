#pragma once
#include "MovableObject.h"
#include <SFML/Graphics.hpp>


class Grid 
{
public:
	Grid();
//	~Grid();

//	int getLocationXAxis() { return _locationXAxis; }
//	int getLocationYAxis() { return _locationYAxis; }
	virtual char getGridType() { return GRID_TYPE; }
	virtual sf::Sprite* getSprite() { return NULL; }
	//magic words
	static const char GRID_TYPE = 'g';
private:
	
};


class Shelf : public Grid 
{
public:
	Shelf(int locationXAxis, int locationYAxis, MovableObject* topShelf, MovableObject* midShelf, MovableObject* botShelf);
//	~Shelf();


	MovableObject* getTopShelf(); //zwraca zawarto�� danej p�ki, w wypadku jej braku zwraca nullpointera
	MovableObject* getMidShelf(); //zwraca zawarto�� danej p�ki, w wypadku jej braku zwraca nullpointera
	MovableObject* getBotShelf(); //zwraca zawarto�� danej p�ki, w wypadku jej braku zwraca nullpointera
	MovableObject* getShelf(char); //zwraca zawarto�� wybranej p�ki
	void setSprite(sf::Sprite * newSprite) { _sprite = newSprite; }
	sf::Sprite* getSprite() { return _sprite; }

	void setShelf(MovableObject*, char); //zmienia zawarto�� wybranej p�ki
	void setTopShelf(MovableObject* newShelf) { _topShelf = newShelf; } //zmienia zawarto�� danej p�ki
	void setMidShelf(MovableObject* newShelf) { _midShelf = newShelf; } //zmienia zawarto�� danej p�ki
	void setBotShelf(MovableObject* newShelf) { _botShelf = newShelf; } //zmienia zawarto�� danej p�ki

	char searchShelves(MovableObject* obj); //szuka obiektu na p�kach

	int getLocationX() { return _locationXAxis; }
	int getLocationY() { return _locationYAxis; }

	char getGridType() { return SHELF_TYPE; } //zwraca typ pola

	//magic words
	static const char SHELF_TYPE = 's';

	static const char TOP_SHELF = 't';
	static const char MID_SHELF = 'm';
	static const char BOT_SHELF = 'b';
	static const char NO_SHELF = 'n';
private:
	sf::Sprite * _sprite = NULL;
	MovableObject* _topShelf;
	MovableObject* _midShelf;
	MovableObject* _botShelf;
	int _locationXAxis;
	int _locationYAxis;

	void setSpritePositionOnWindow(); //ustawia pozycje na ekranie glownym ze wzgledu na pozycje geograficzna
};

