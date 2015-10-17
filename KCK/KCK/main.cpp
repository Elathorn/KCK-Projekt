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
	for (int x = 9; x > 0; x--)
	{
		for (int y = 0; y < 10; y++)
			cout << mech._map[x][y]->getGridType();
		cout << endl;
		mech 
	}
	getchar();
	//end of sandbox

	return 0; 
}

