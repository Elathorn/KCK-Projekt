#include "NaturalInterpreter.h"
#include "IOManager.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

NaturalInterpreter::NaturalInterpreter()
{
	//wczytywanie list
	//wczytywanie map
	_ordersList = IOManager::loadMapFromFile("orders.txt");
	_possitiveResponsesList = IOManager::loadMapFromFile("affirmative.txt");
	_shelvesList = IOManager::loadMapFromFile("shelves.txt");
	_movableObjectsList = IOManager::loadMapFromFile("movableObjects.txt");
	_adjToShelvesMap = IOManager::loadMapFromFile("adjectivesToShelves.txt");
	_adjToMovableObjectsMap = IOManager::loadMapFromFile("adjectivesToMovableObjects.txt");

}


NaturalInterpreter::~NaturalInterpreter()
{
	//usuwanie list
	//usuwanie map
	delete _ordersList;
	delete _possitiveResponsesList;
	delete _shelvesList;
	delete _movableObjectsList;
	delete _adjToShelvesMap;
	delete _adjToMovableObjectsMap;
}



vector < string > * NaturalInterpreter::tokenizer(string str, char separator)
{
	vector < string > * temp = new vector <string> ();
	int lastStringPos = 0;
	for (int i = 0; i < str.length()+1; i++)
	{
		char actual = str[i];
		if (actual == separator) 
		{
			temp->push_back(str.substr(lastStringPos, i-lastStringPos));
			lastStringPos = i+1;
		}
	}
	temp->push_back(str.substr(lastStringPos, str.length()));
	for (std::vector<string>::iterator itv = temp->begin(); itv != temp->end(); ++itv)
	{
		transform(itv->begin(), itv->end(), itv->begin(), ::tolower);
	}
	return temp;
}

int NaturalInterpreter::recognizeOrder(string humanInput)
{
	vector <string> * words = tokenizer(humanInput, ' ');
	bool orderFound = false;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv) 
	{
		for (std::list<string>::iterator itl = _ordersList->begin(); itl != _ordersList->end(); ++itl)
		{
			if (itv->find(*itl) != string::npos)
			{
				orderFound = true;
				break;
			}
		}
	}
	bool movableObjectFound = false;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::list<string>::iterator itl = _movableObjectsList->begin(); itl != _movableObjectsList->end(); ++itl)
		{
			if (itv->find(*itl) != string::npos)
			{
				movableObjectFound = true;
				break;
			}
		}
	}

	
	



	
	
	return int(orderFound);
}