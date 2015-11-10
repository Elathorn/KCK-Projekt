#pragma once
#include "IOManager.h"
#include <vector>

using namespace std;

class NaturalInterpreter //interpretacja j�zyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
	vector <string> * recognizeOrder(string humanInput);
	string tokenSearcher(vector <string> * words, map <string, string> * map, string type = "");
	vector<string>* tokenizer(string input, char separator);
private:
	map<string, string>* _ordersMap; //mapa wykrywanych rozkaz�w
	map<string, string>* _possitiveResponsesMap; //mapa z pozytywnymi odpowiedziami
	map<string, string>* _shelvesMap; //mapa wykrywanych okre�le� na p�k�
	map<string, string>* _movableObjectsMap; //mapa wykrywanych okre�le� na obiekt
	map<string, string>* _adjToShelvesMap; //mapa przymiotnik�w do p�ek
	map<string, string>* _colorOfMovableObjectsMap; //mapa kolor�w obiekt�w
	map<string, string>* _sizeOfMovableObjectsMap; //mapa wielko�ci obiekt�w
	map<string, string>* _lvlOfShelves; //mapa p�ek
};

