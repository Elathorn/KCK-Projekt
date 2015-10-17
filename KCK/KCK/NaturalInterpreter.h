#pragma once
#include "IOManager.h"
#include <vector>

using namespace std;

class NaturalInterpreter //interpretacja jêzyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	vector <string> * recognizeOrder(string humanInput);
private:
	vector<string>* tokenizer(string input, char separator);
	map<string, string>* _ordersMap; //mapa wykrywanych rozkazów
	map<string, string>* _possitiveResponsesMap; //mapa z pozytywnymi odpowiedziami
	map<string, string>* _shelvesMap; //mapa wykrywanych okreœleñ na pó³kê
	map<string, string>* _movableObjectsMap; //mapa wykrywanych okreœleñ na obiekt
	map<string, string>* _adjToShelvesMap; //mapa przymiotników do pó³ek
	map<string, string>* _colorOfMovableObjectsMap; //mapa kolorów obiektów
	map<string, string>* _sizeOfMovableObjectsMap; //mapa wielkoœci obiektów
	map<string, string>* _lvlOfShelves; //mapa pó³ek
};

