#include "NaturalInterpreter.h"
#include "IOManager.h"
#include <algorithm>
#include "ErrorHandler.h"
#include "MovableObject.h"
#include "Mechanic.h"
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
	_colorOfMovableObjectsMap = IOManager::loadMapFromFile("colorsOfMovableObjects.txt");
	_sizeOfMovableObjectsMap = IOManager::loadMapFromFile("sizesOfMovableObjects.txt");
	_lvlOfShelves = IOManager::loadMapFromFile("levelsOfShelves.txt");
}

NaturalInterpreter::~NaturalInterpreter()
{
	//usuwanie map
	delete _ordersMap;
	delete _possitiveResponsesMap;
	delete _shelvesMap;
	delete _movableObjectsMap;
	delete _adjToShelvesMap;
	delete _sizeOfMovableObjectsMap;
	delete _colorOfMovableObjectsMap;
}

vector < string > * NaturalInterpreter::tokenizer(string str, char separator)
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

	string sizeOfMovableObject;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _sizeOfMovableObjectsMap->begin(); itm != _sizeOfMovableObjectsMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				sizeOfMovableObject = itm->second;
				itv->clear();
				break;
			}
		}
	}

	string colorOfMovableObject;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _colorOfMovableObjectsMap->begin(); itm != _colorOfMovableObjectsMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				colorOfMovableObject = itm->second;
				itv->clear();
				break;
			}
		}
	}

	string shelf;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _shelvesMap->begin(); itm != _shelvesMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				shelf = itm->second;
				itv->clear();
				break;
			}
		}
	}

	string adjToShelf;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _adjToShelvesMap->begin(); itm != _adjToShelvesMap->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				adjToShelf = itm->second;
				itv->clear();
				break;
			}
		}
	}

	string lvlOfShelf;
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = _lvlOfShelves->begin(); itm != _lvlOfShelves->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				lvlOfShelf = itm->second;
				itv->clear();
				break;
			}
		}
	}
	//temp
	Mechanic mechani;
	cout << mechani.findMovableObject(colorOfMovableObject, sizeOfMovableObject)->getLocationXAxis() << " " << mechani.findMovableObject(colorOfMovableObject, sizeOfMovableObject)->getLocationYAxis() << endl;
	
	mechani.moveObject(mechani.findShelf(adjToShelf), mechani.findMovableObject(colorOfMovableObject, sizeOfMovableObject), lvlOfShelf[0]);
	cout << mechani.findMovableObject(colorOfMovableObject, sizeOfMovableObject)->getLocationXAxis() << " " << mechani.findMovableObject(colorOfMovableObject, sizeOfMovableObject)->getLocationYAxis() << endl;
	//temp
	
	return int(orderFound);
}