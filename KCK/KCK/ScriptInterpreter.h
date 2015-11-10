#pragma once
#include "Mechanic.h"
#include "NaturalInterpreter.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

class ScriptInterpreter
{
public:
	ScriptInterpreter();
	~ScriptInterpreter();

	string interpretUserInput(string humanInput);
	Mechanic* getMechanic() { return _mechanic; }

private:
	vector<string>* _script;
	Mechanic* _mechanic;
	NaturalInterpreter* _NI;

	vector<string>* _shelfNotFoundTxt;
	vector<string>* _movableObjNotFoundTxt;
	vector<string>* _shelfIsFullTxt;
	vector<string>* _commandNotUnderstandedTxt;
	vector<string>* _goOrderDoneTxt;
	vector<string>* _rackNotFoundTxt;

	//answer randomize
	string randomizeAnswer(int enumInt);
	int randomNumber(int max);
	enum _typeOfAnswerChoice { shelfNotFound, movableObjNotFound, shelfIsFull, goOrderDone, commandNotUnderstanded, rackNotFound };

};

