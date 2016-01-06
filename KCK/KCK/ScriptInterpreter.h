#pragma once
#include "Mechanic.h"
#include "NaturalInterpreter.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

extern NaturalInterpreter * NI;
extern Mechanic * mechanic;



class GraphicManager;

class ScriptInterpreter
{
public:
	ScriptInterpreter();
	~ScriptInterpreter();

	string interpretUserInput(string humanInput);
	Mechanic* getMechanic() { return mechanic; }

	void run(); //sluzy do uruchomienia interpretacji jako watek

	enum _typeOfAnswerChoice { shelfNotFound, movableObjNotFound, shelfIsFull, goOrderDone, commandNotUnderstanded, rackNotFound, objectIsActuallyHere };
private:
	vector<string>* _script;
	vector<string>* _shelfNotFoundTxt;
	vector<string>* _movableObjNotFoundTxt;
	vector<string>* _shelfIsFullTxt;
	vector<string>* _commandNotUnderstandedTxt;
	vector<string>* _goOrderDoneTxt;
	vector<string>* _rackNotFoundTxt;
	vector<string>* _objectIsActuallyHereTxt;


	enum scriptPart { order, adjToShelf, lvlOfShelf, colorOfMovableObject, sizeOfMovableObject};

private:
	//answer randomize
	string randomizeAnswer(int enumInt);
	int randomNumber(int max);


	/*Sprawdza czy wszystkie potrzebne elementy sa juz w vectorze script
	Przykladowy sposob uzycia:
	checkValide(order + adjToShelf, script) - sprawdza czy script posiada pozycje order oraz adjToShelf
	Jesli nie posiada, wczytuje je od usera
	*/
	void checkValide(int enumSum, vector<string> * script);
};

