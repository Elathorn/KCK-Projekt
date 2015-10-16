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

	map<string, string>* _ordersList; //lista wykrywanych rozkaz�w
	map<string, string>* _possitiveResponsesList; //lista z pozytywnymi odpowiedziami
	map<string, string>* _shelvesList; //lista wykrywanych okre�le� na p�k�
	map<string, string>* _movableObjectsList; //lista wykrywanych okre�le� na obiekt

	map<string, string>* _adjToShelvesMap; //mapa przymiotnik�w do p�ek
	map<string, string>* _adjToMovableObjectsMap; //mapa przymiotnik�w do obiekt�w
};

