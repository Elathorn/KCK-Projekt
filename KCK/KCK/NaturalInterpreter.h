#pragma once
#include "IOManager.h"
#include <vector>
class ScriptInterpreter;
class GraphicManager;

using namespace std;

class NaturalInterpreter //interpretacja jêzyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	vector <string> * recognizeOrder(string humanInput);
	string tokenSearcher(vector <string> * words, map <string, string> * map);
	vector<string>* tokenizer(string input, char separator);
	string searchForToken(int enumKeyWordType);
private:
	map<string, string>* _ordersMap; //mapa wykrywanych rozkazów
	map<string, string>* _possitiveResponsesMap; //mapa z pozytywnymi odpowiedziami
	map<string, string>* _shelvesMap; //mapa wykrywanych okreœleñ na pó³kê 
	map<string, string>* _movableObjectsMap; //mapa wykrywanych okreœleñ na obiekt
	map<string, string>* _adjToShelvesMap; //mapa przymiotników do pó³ek 
	map<string, string>* _colorOfMovableObjectsMap; //mapa kolorów obiektów
	map<string, string>* _sizeOfMovableObjectsMap; //mapa wielkoœci obiektów
	map<string, string>* _lvlOfShelves; //mapa pó³ek

	const char _separator = ' ';
};

