#pragma once
#include "Object.h"

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
	Shelf(int locationXAxis, int locationYAxis, Object* topShelf, Object* midShelf, Object* botShelf);
//	~Shelf();


	Object* getTopShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	Object* getMidShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	Object* getBotShelf(); //zwraca zawartoœæ danej pó³ki, w wypadku jej braku zwraca nullpointera
	Object* getShelf(char); //zwraca zawartoœæ wybranej pó³ki

	void setShelf(Object*, char); //zmienia zawartoœæ wybranej pó³ki
	void setTopShelf(Object* newShelf) { _topShelf = newShelf; } //zmienia zawartoœæ danej pó³ki
	void setMidShelf(Object* newShelf) { _midShelf = newShelf; } //zmienia zawartoœæ danej pó³ki
	void setBotShelf(Object* newShelf) { _botShelf = newShelf; } //zmienia zawartoœæ danej pó³ki

	char searchShelves(Object* obj); //szuka obiektu na pó³kach

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
	Object* _topShelf;
	Object* _midShelf;
	Object* _botShelf;
	int _locationXAxis;
	int _locationYAxis;
};

