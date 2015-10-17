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

int main()
{


	//sandbox 
	Mechanic mech;
	cout << endl << endl;
	for (int x = Mechanic::MAP_X_SIZE - 1; x >= 0; x--)
	{
		for (int y = 0; y < Mechanic::MAP_Y_SIZE; y++)
			cout << y << x << " ";
		cout << endl;
	}
	Shelf* sh;
	sh = mech.findShelf("east");
	cout << sh->getLocationX() << " " << sh->getLocationY();
	//end of sandbox
	getchar();
	return 0; 
}

