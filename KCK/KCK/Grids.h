#pragma once
#include "Object.h"

class Grid
{
public:
	Grid(int, int);
//	~Grid();

	int getLocationXAxis() { return _locationXAxis; }
	int getLocationYAxis() { return _locationYAxis; }

protected:
	int _locationXAxis;
	int _locationYAxis;
};


class Shelf : public Grid
{
public:
	Shelf(int locationXAxis, int locationYAxis, Object* topShelf, Object* midShelf, Object* botShelf);
//	~Shelf();


	Object* getTopShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	Object* getMidShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	Object* getBotShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	void setTopShelf(Object* newShelf) { _topShelf = newShelf; } //zmienia zawartoœæ pó³ki
	void setMidShelf(Object* newShelf) { _midShelf = newShelf; }
	void setBotShelf(Object* newShelf) { _botShelf = newShelf; }

private:
	Object* _topShelf;
	Object* _midShelf;
	Object* _botShelf;
};

