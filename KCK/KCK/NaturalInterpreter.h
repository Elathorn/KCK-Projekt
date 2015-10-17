#pragma once
#include "IOManager.h"
#include <vector>

using namespace std;

class NaturalInterpreter //interpretacja j�zyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	int recognizeOrder(string humanInput);
	vector<string>* tokenizer(string input, char separator);
private:

	map<string, string>* _ordersMap; //lista wykrywanych rozkaz�w
	map<string, string>* _possitiveResponsesMap; //lista z pozytywnymi odpowiedziami
	map<string, string>* _shelvesMap; //lista wykrywanych okre�le� na p�k�
	map<string, string>* _movableObjectsMap; //lista wykrywanych okre�le� na obiekt
	map<string, string>* _adjToShelvesMap; //mapa przymiotnik�w do p�ek
	map<string, string>* _adjToMovableObjectsMap; //mapa przymiotnik�w do obiekt�w
};

