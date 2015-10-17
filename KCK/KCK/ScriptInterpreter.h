#pragma once
#include "Mechanic.h"
#include "NaturalInterpreter.h"
using namespace std;

class ScriptInterpreter
{
public:
	ScriptInterpreter();
	~ScriptInterpreter();

	string interpretUserInput(string humanInput);

private:
	vector<string>* _script;
	Mechanic* _mechanic;
	NaturalInterpreter* _NI;
};

