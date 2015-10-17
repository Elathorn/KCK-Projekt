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
	NaturalInterpreter ni;
	ni.recognizeOrder("Wez czerwona duza paczke i przenies ja na zachodnia polke.");
	for (int x = 9; x > 0; x--)
	{
		for (int y = 0; y < 10; y++)
			cout << mech._map[x][y]->getGridType();
		cout << endl;
	}

	getchar();
	//end of sandbox

	return 0; 
}

