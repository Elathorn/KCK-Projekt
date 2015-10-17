#include "ScriptInterpreter.h"




ScriptInterpreter::ScriptInterpreter()
{
	_mechanic = new Mechanic(); //tworzenie mechaniki
	_NI = new NaturalInterpreter(); //i interpretera jêzyka naturalnego

}

ScriptInterpreter::~ScriptInterpreter()
{
}

string ScriptInterpreter::interpretUserInput(string humanInput)
{
	vector<string>* script = _NI->recognizeOrder(humanInput);
	enum scriptPart { order, adjToShelf, lvlOfShelf, colorOfMovableObject, sizeOfMovableObject };
	
	char lvlOfShelfChar = script->at(lvlOfShelf)[0]; //konwersja stringa na chara

	if (script->at(order) == "go")
	{
		_mechanic->moveObject(_mechanic->findShelf(script->at(adjToShelf)),
			_mechanic->findMovableObject(script->at(colorOfMovableObject), script->at(sizeOfMovableObject)),
			lvlOfShelfChar);
	}


	return "";
}
