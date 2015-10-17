//////////////////
//Projekt KCK
//G�azik Micha�
//Hliwa Kamil
//
//W�zek wid�owy
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
	cout << sh->getLocationX() << " " << sh->getLocationY() << endl << endl << endl;
	NaturalInterpreter ni;
	ni.recognizeOrder("Wez czerwona duza paczke i przenies ja na zachodnia dolna polke.");
	//end of sandbox
	getchar();
	return 0; 
}

