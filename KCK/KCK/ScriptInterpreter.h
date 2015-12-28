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


private:
	//answer randomize
	string randomizeAnswer(int enumInt);
	int randomNumber(int max);


};

