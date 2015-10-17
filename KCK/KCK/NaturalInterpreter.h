#pragma once
#include "IOManager.h"
#include <vector>

using namespace std;

class NaturalInterpreter //interpretacja jêzyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	int recognizeOrder(string humanInput);
	vector<string>* tokenizer(string input, char separator);
private:

	map<string, string>* _ordersMap; //mapa wykrywanych rozkazów
	map<string, string>* _possitiveResponsesMap; //mapa z pozytywnymi odpowiedziami
	map<string, string>* _shelvesMap; //mapa wykrywanych okreœleñ na pó³kê
	map<string, string>* _movableObjectsMap; //mapa wykrywanych okreœleñ na obiekt
	map<string, string>* _adjToShelvesMap; //mapa przymiotników do pó³ek
	map<string, string>* _adjToMovableObjectsMap; //mapa przymiotników do obiektów
};

