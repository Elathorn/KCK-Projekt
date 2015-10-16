#pragma once
#include "string"
using namespace std;

class Object
{
public:
	Object(int, int, string, string);
	~Object();

	string getSize() { return _size; }
	string getColor() { return _color; }
	int getLocationXAxis() { return _locationXAxis; }
	int getLocationYAxis() { return _locationYAxis; }

	int move(int, int); //zmienia pozycje pude³ka. Dla -1 zachowuje dan¹ pozycje bez zmiany

private:
	string _size;
	string _color;
	int _locationXAxis;
	int _locationYAxis;
};

