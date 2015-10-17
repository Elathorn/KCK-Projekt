//////////////////
//Projekt KCK
//G³azik Micha³
//Hliwa Kamil
//
//Wózek wid³owy
//////////////////

#include "IOManager.h"
#include "NaturalInterpreter.h"
#include "Mechanic.h"

#include <iostream>
using namespace std;

void mechanic_test_move(Mechanic& mech)
{
	Shelf* shW;
	Shelf* shE;
	shW = mech.findShelf("west");
	shE = mech.findShelf("east");
	MovableObject* objG;
	MovableObject* objR;
	objG = mech.findMovableObject("green", "");
	objR = mech.findMovableObject("red", "");
	cout << "Zawartosc west: ";
	if (shW->getTopShelf() != NULL)
		cout << shW->getTopShelf()->getColor();
	else
		cout << "pusto.";
	cout << endl << "Zawartosc east: ";
	if (shE->getTopShelf() != NULL)
		cout << shE->getTopShelf()->getColor();
	else
		cout << "pusto.";
	cout << endl;
	cout << "Pude³ko r: " << objR->getLocationXAxis() << " " << objR->getLocationYAxis() << endl;
	cout << "Pude³ko g: " << objG->getLocationXAxis() << " " << objG->getLocationYAxis() << endl;
	cout << endl << "!!!MOVE!!!" << endl << endl;
	mech.moveObject(shW, objR, 't');
	cout << "Zawartosc west: ";
	if (shW->getTopShelf() != NULL)
		cout << shW->getTopShelf()->getColor();
	else
		cout << "pusto.";
	cout << endl << "Zawartosc east: ";
	if (shE->getTopShelf() != NULL)
		cout << shE->getTopShelf()->getColor();
	else
		cout << "pusto.";
	cout << endl;
	cout << "Pude³ko r: " << objR->getLocationXAxis() << " " << objR->getLocationYAxis() << endl;
	cout << "Pude³ko g: " << objG->getLocationXAxis() << " " << objG->getLocationYAxis() << endl;
}

int main()
{


	//sandbox 
	Mechanic mech;
	NaturalInterpreter nat;

	for (int x = Mechanic::MAP_X_SIZE - 1; x >= 0; x--)
	{
		for (int y = 0; y < Mechanic::MAP_Y_SIZE; y++)
			cout << mech._map[y][x]->getGridType();
		cout << endl;
	}

	cout << endl << endl << "Numeracja:" << endl;
	for (int x = Mechanic::MAP_X_SIZE - 1; x >= 0; x--)
	{
		for (int y = 0; y < Mechanic::MAP_Y_SIZE; y++)
			cout << y << x << " ";
		cout << endl;
	}
	//TEST MECHANIKI
	mechanic_test_move(mech);
	//end of sandbox
	getchar();
	return 0; 
}

