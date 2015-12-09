#include "NaturalInterpreter.h"
#include "IOManager.h"
#include <algorithm>
#include "ErrorHandler.h"
#include "Mechanic.h"
#include <vector>
#include <iostream>
#include "ScriptInterpreter.h"
#include "GraphicManager.h"
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

string NaturalInterpreter::searchForToken(int enumKeyWordType)
{
	string token;
	vector<string> * tokens;
	token = GraphicManager::getStringFromUser(); //wczytujemy do tokena user input
	tokens = tokenizer(token, _separator); //tokenizujemy user input
	switch (enumKeyWordType)
	{
	case (ScriptInterpreter::shelfNotFound) :
		token = tokenSearcher(tokens, _adjToShelvesMap); break;
	case (ScriptInterpreter::movableObjNotFound) :
		token = tokenSearcher(tokens, _movableObjectsMap); break;
	case (ScriptInterpreter::rackNotFound) :
		token = tokenSearcher(tokens, _lvlOfShelves); break;
	case (ScriptInterpreter::commandNotUnderstanded) :
		token = tokenSearcher(tokens, _ordersMap); break;
	}
	return token;
}

string NaturalInterpreter::tokenSearcher(vector <string> * words, map <string, string> * map) //tu by³ string type
{
	string type = "";
	for (std::vector<string>::iterator itv = words->begin(); itv != words->end(); ++itv)
	{
		for (std::map<string, string>::iterator itm = map->begin(); itm != map->end(); ++itm)
		{
			if (itv->find(itm->first) != string::npos)
			{
				type = itm->second;
				itv->erase();
				break;
			}
		}
	}
	return type;
}

vector <string> * NaturalInterpreter::recognizeOrder(string humanInput)
//Wyszukuje s³owa kluczowe i rozpoznaje dane: rozkaz, miejsce szafki, pó³ka szafki, kolor paczki, rozmiar paczki
{
	vector <string> * words = tokenizer(humanInput, _separator); 

	vector <string> * interpretation = new vector <string>();
	interpretation->push_back(tokenSearcher(words, _ordersMap));
	interpretation->push_back(tokenSearcher(words, _adjToShelvesMap));
	interpretation->push_back(tokenSearcher(words, _lvlOfShelves));
	interpretation->push_back(tokenSearcher(words, _colorOfMovableObjectsMap));
	interpretation->push_back(tokenSearcher(words, _sizeOfMovableObjectsMap));
	delete words;
	return interpretation;
}