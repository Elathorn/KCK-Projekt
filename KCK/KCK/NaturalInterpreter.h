#pragma once
#include "IOManager.h"

using namespace std;

class NaturalInterpreter //interpretacja j�zyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	int recognizeOrder(string humanInput);
private:

	list<string>* _ordersList; //lista wykrywanych rozkaz�w
	list<string>* _possitiveResponsesList; //lista z pozytywnymi odpowiedziami
	list<string>* _shelvesList; //lista wykrywanych okre�le� na p�k�
	list<string>* _movableObjectsList; //lista wykrywanych okre�le� na obiekt

	map<string, string>* _adjToShelvesMap; //mapa przymiotnik�w do p�ek
	map<string, string>* _adjToMovableObjectsMap; //mapa przymiotnik�w do obiekt�w
};

