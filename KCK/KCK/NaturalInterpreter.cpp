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
	_ordersMap = IOManager::loadMapFromFile("orders.txt");
	_possitiveResponsesMap = IOManager::loadMapFromFile("affirmative.txt");
	_shelvesMap = IOManager::loadMapFromFile("shelves.txt");
	_movableObjectsMap = IOManager::loadMapFromFile("movableObjects.txt");
	_adjToShelvesMap = IOManager::loadMapFromFile("adjectivesToShelves.txt");
	_adjToMovableObjectsMap = IOManager::loadMapFromFile("adjectivesToMovableObjects.txt");

}


NaturalInterpreter::~NaturalInterpreter()
{
	//usuwanie map
	delete _ordersMap;
	delete _possitiveResponsesMap;
	delete _shelvesMap;
	delete _movableObjectsMap;
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
		for (std::map<string, string>::iterator itm = _ordersMap->begin(); itm != _ordersMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				orderFound = true;
				break;
			}
		}
	}
	

	bool movableObjectFound = false;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string,string>::iterator itm = _movableObjectsMap->begin(); itm != _movableObjectsMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				movableObjectFound = true;
				break;
			}
		}
	}

	
	



	
	
	return int(orderFound);
}