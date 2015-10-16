#include "NaturalInterpreter.h"

//tmp
#include <iostream>
using namespace std;
//end of tmp

NaturalInterpreter::NaturalInterpreter()
{
	//wczytywanie list
	_ordersList = IOManager::loadListFromFile("orders.txt");
	_possitiveResponsesList = IOManager::loadListFromFile("affirmative.txt");
	_shelvesList = IOManager::loadListFromFile("shelves.txt");
	_movableObjectsList = IOManager::loadListFromFile("_movableObjects");
	//wczytywanie map
	_adjToShelvesMap = IOManager::loadMapFromFile("adjectivesToShelves.txt");
	_adjToMovableObjectsMap = IOManager::loadMapFromFile("adjectivesToMovableObjects.txt");

}


NaturalInterpreter::~NaturalInterpreter()
{
	//usuwanie list
	delete _ordersList;
	delete _possitiveResponsesList;
	delete _shelvesList;
	delete _movableObjectsList;
	//usuwanie map
	delete _adjToShelvesMap;
	delete _adjToMovableObjectsMap;
}

int NaturalInterpreter::recognizeOrder(string humanInput)
{
	string str = "Wez zielona paczke i przenies ja na wschodnia polke";
	string found;
	int position = str.find("Wez");
	cout << str.substr(position);
	getchar();
	return 0;
	//TEST DRUGI
}