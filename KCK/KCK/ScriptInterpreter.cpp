#include "ScriptInterpreter.h"




ScriptInterpreter::ScriptInterpreter()
{
	_mechanic = new Mechanic(); //tworzenie mechaniki
	_NI = new NaturalInterpreter(); //i interpretera j?zyka naturalnego

	_shelfNotFoundTxt = IOManager::loadVectorFromFile("shelfNotFound.txt");
	_movableObjNotFoundTxt = IOManager::loadVectorFromFile("movableObjectNotFound.txt");
	_shelfIsFullTxt = IOManager::loadVectorFromFile("shelfIsFull.txt");
	_commandNotUnderstandedTxt = IOManager::loadVectorFromFile("commandNotUnderstanded.txt");
	_goOrderDoneTxt = IOManager::loadVectorFromFile("goOrderDone.txt");
	_rackNotFoundTxt = IOManager::loadVectorFromFile("rackNotFound.txt");

	srand(time(NULL));
}

ScriptInterpreter::~ScriptInterpreter()
{

}

string ScriptInterpreter::interpretUserInput(string humanInput)
{
	vector<string>* script = _NI->recognizeOrder(humanInput);
	enum scriptPart { order, adjToShelf, lvlOfShelf, colorOfMovableObject, sizeOfMovableObject };

	if (script->at(order) == "")
		return randomizeAnswer(commandNotUnderstanded);

	char lvlOfShelfChar = script->at(lvlOfShelf)[0]; //konwersja stringa na chara

	Shelf* shelf = _mechanic->findShelf(script->at(adjToShelf));
	if (shelf == NULL) //je?li nie znaleziono pó³ki
		return randomizeAnswer(shelfNotFound);
	MovableObject* obj = _mechanic->findMovableObject(script->at(colorOfMovableObject), script->at(sizeOfMovableObject));
	if (obj == NULL) //je?li nie znaleziono obiektu
		return randomizeAnswer(movableObjNotFound);
	if (!lvlOfShelfChar) //je?li nie istnieje lokalizator konkretnej pó³ki (przegródki)
		return randomizeAnswer(rackNotFound);

	if (script->at(order) == "go")
		if (_mechanic->moveObject(shelf, obj, lvlOfShelfChar))
			return randomizeAnswer(shelfIsFull);
		else
			return randomizeAnswer(goOrderDone);

	return randomizeAnswer(commandNotUnderstanded);
}

string ScriptInterpreter::randomizeAnswer(int enumInt)
{
	switch (enumInt)
	{
	case (shelfNotFound) : return _shelfNotFoundTxt->at(randomNumber(_shelfNotFoundTxt->size()));break;
	case (movableObjNotFound) : return _movableObjNotFoundTxt->at(randomNumber(_movableObjNotFoundTxt->size()));break;
	case (shelfIsFull) : return _shelfIsFullTxt->at(randomNumber(_shelfIsFullTxt->size()));break;
	case (commandNotUnderstanded) : return _commandNotUnderstandedTxt->at(randomNumber(_commandNotUnderstandedTxt->size()));break;
	case (goOrderDone) : return _goOrderDoneTxt->at(randomNumber(_goOrderDoneTxt->size())); break;
	case (rackNotFound) : return _rackNotFoundTxt->at(randomNumber(_rackNotFoundTxt->size())); break;
	}

}

int ScriptInterpreter::randomNumber(int max)
{
	return rand() % max;
}
