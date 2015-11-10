#pragma once
#include "MovableObject.h"

class Grid
{
public:
	Grid();
//	~Grid();

//	int getLocationXAxis() { return _locationXAxis; }
//	int getLocationYAxis() { return _locationYAxis; }
	virtual char getGridType() { return GRID_TYPE; }

	//magic words
	static const char GRID_TYPE = 'g';
protected:
	
};


class Shelf : public Grid
{
public:
	Shelf(int locationXAxis, int locationYAxis, MovableObject* topShelf, MovableObject* midShelf, MovableObject* botShelf);
//	~Shelf();


	MovableObject* getTopShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	MovableObject* getMidShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	MovableObject* getBotShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	MovableObject* getShelf(char); //zwraca zawartoœæ wybranej pó³ki

	void setShelf(MovableObject*, char); //zmienia zawartoœæ wybranej pó³ki
	void setTopShelf(MovableObject* newShelf) { _topShelf = newShelf; } //zmienia zawartoœæ danej pó³ki
	void setMidShelf(MovableObject* newShelf) { _midShelf = newShelf; } //zmienia zawartoœæ danej pó³ki
	void setBotShelf(MovableObject* newShelf) { _botShelf = newShelf; } //zmienia zawartoœæ danej pó³ki

	char searchShelves(MovableObject* obj); //szuka obiektu na pó³kach

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
	MovableObject* _topShelf;
	MovableObject* _midShelf;
	MovableObject* _botShelf;
	int _locationXAxis;
	int _locationYAxis;
};

