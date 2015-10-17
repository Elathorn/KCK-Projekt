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

	map<string, string>* _ordersMap; //mapa wykrywanych rozkaz�w
	map<string, string>* _possitiveResponsesMap; //mapa z pozytywnymi odpowiedziami
	map<string, string>* _shelvesMap; //mapa wykrywanych okre�le� na p�k�
	map<string, string>* _movableObjectsMap; //mapa wykrywanych okre�le� na obiekt
	map<string, string>* _adjToShelvesMap; //mapa przymiotnik�w do p�ek
	map<string, string>* _adjToMovableObjectsMap; //mapa przymiotnik�w do obiekt�w
};

