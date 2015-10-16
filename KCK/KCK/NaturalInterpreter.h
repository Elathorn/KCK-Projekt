#pragma once
#include "IOManager.h"

using namespace std;

class NaturalInterpreter //interpretacja jêzyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	int recognizeOrder(string humanInput);
private:

	list<string>* _ordersList; //lista wykrywanych rozkazów
	list<string>* _possitiveResponsesList; //lista z pozytywnymi odpowiedziami
	list<string>* _shelvesList; //lista wykrywanych okreœleñ na pó³kê
	list<string>* _movableObjectsList; //lista wykrywanych okreœleñ na obiekt

	map<string, string>* _adjToShelvesMap; //mapa przymiotników do pó³ek
	map<string, string>* _adjToMovableObjectsMap; //mapa przymiotników do obiektów
};

