#include "NaturalInterpreter.h"
#include "IOManager.h"
#include <algorithm>
#include "Object.h"
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



vector < string > * NaturalInterpreter::tokenizer(string str, char separator)\
//Z zadanego stringa tworzy vector stworzony z ka¿dego s³owa ze stringa
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
//Wyszukuje s³owa kluczowe i rozpoznaje dane
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
				itv->erase();
				break;
			}
		}
	}

	string movableObject;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string,string>::iterator itm = _movableObjectsMap->begin(); itm != _movableObjectsMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				movableObject = itm->second;
				itv->clear();
				break;
			}
		}
	}

	string adjToMovableObject;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _adjToMovableObjectsMap->begin(); itm != _adjToMovableObjectsMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				adjToMovableObject = itm->second;
				itv->clear();
				break;
			}
		}
	}
	string shelves;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _shelvesMap->begin(); itm != _shelvesMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				shelves = itm->second;
				itv->clear();
				break;
			}
		}
	}

	string adjToShelves;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _adjToShelvesMap->begin(); itm != _adjToShelvesMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				adjToShelves = itm->second;
				itv->clear();
				break;
			}
		}
	}
	


	return int(orderFound);
}