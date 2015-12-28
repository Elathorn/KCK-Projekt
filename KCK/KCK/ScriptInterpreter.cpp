#include "ScriptInterpreter.h"
#include "GraphicManager.h"

extern NaturalInterpreter * NI;
extern ScriptInterpreter * SI;
extern GraphicManager * GM;
extern Mechanic * mechanic;

ScriptInterpreter::ScriptInterpreter()
{
	mechanic = new Mechanic(); //tworzenie mechaniki
	NI = new NaturalInterpreter(); //i interpretera jezyka naturalnego
	_shelfNotFoundTxt = IOManager::loadVectorFromFile("shelfNotFound.txt");
	_movableObjNotFoundTxt = IOManager::loadVectorFromFile("movableObjectNotFound.txt");
	_shelfIsFullTxt = IOManager::loadVectorFromFile("shelfIsFull.txt");
	_commandNotUnderstandedTxt = IOManager::loadVectorFromFile("commandNotUnderstanded.txt");
	_goOrderDoneTxt = IOManager::loadVectorFromFile("goOrderDone.txt");
	_rackNotFoundTxt = IOManager::loadVectorFromFile("rackNotFound.txt");
	_objectIsActuallyHereTxt = IOManager::loadVectorFromFile("objectIsActuallyHere.txt");
	srand(time(NULL));
}

ScriptInterpreter::~ScriptInterpreter()
{

}

string ScriptInterpreter::interpretUserInput(string humanInput)
{
	vector<string>* script = NI->recognizeOrder(humanInput);
	enum scriptPart { order, adjToShelf, lvlOfShelf, colorOfMovableObject, sizeOfMovableObject };
	bool commandComplete = false;
	Shelf* shelf = nullptr;
	MovableObject* obj = nullptr;
	while (!commandComplete) //todo: wszystko - to jest spierdolone
	{
		commandComplete = true;
		if (script->at(order) == "")
		{
			GM->printCommunicate(randomizeAnswer(commandNotUnderstanded));
			script->at(order) = NI->searchForToken(commandNotUnderstanded);
			commandComplete = false;
			break;

		}
		shelf = mechanic->findShelf(script->at(adjToShelf));
		if (shelf == NULL) //je?li nie znaleziono pó³ki
		{
			GM->printCommunicate(randomizeAnswer(shelfNotFound));
			script->at(adjToShelf) = NI->searchForToken(shelfNotFound);
			commandComplete = false;
			break;
		}
		obj = mechanic->findMovableObject(script->at(colorOfMovableObject), script->at(sizeOfMovableObject));
		if (obj == NULL) //je?li nie znaleziono obiektu
		{
			GM->printCommunicate(randomizeAnswer(movableObjNotFound));
			script->at(colorOfMovableObject) = NI->searchForToken(movableObjNotFound); //todo: ogarn¹æ
			commandComplete = false;
			break;
		}
		if (script->at(lvlOfShelf) == "") //jesli nie istnieje lokalizator konkretnej polki (przegrodki)
		{
			GM->printCommunicate(randomizeAnswer(rackNotFound)); 
			(*script)[lvlOfShelf] = NI->searchForToken(rackNotFound);
			commandComplete = false;
			break;
		}
	}

	char lvlOfShelfChar = script->at(lvlOfShelf)[0]; //konwersja stringa na chara (wszystko działa)
	string orderStr = (*script)[order];
	delete script;
	MovableObject* objAtTargetShelf = shelf->getShelf(lvlOfShelfChar); //obiekt ktory moze byc na polce na ktora przenosimy


	if (orderStr == "go")
		if (objAtTargetShelf == obj) //jesli ten obiekt jest juz na tej polce
			return randomizeAnswer(objectIsActuallyHere); //informujemy o tym uzytkownika
		else if (mechanic->moveObject(shelf, obj, lvlOfShelfChar)) //jezeli NIE udalo sie przeniesc obiektu (pelna polka)
			return randomizeAnswer(shelfIsFull);
		else  //inaczej jesli sie udalo
			return randomizeAnswer(goOrderDone);

	return randomizeAnswer(commandNotUnderstanded); //todo: wrzucic to do petli dialogowania
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
	case (objectIsActuallyHere) : return _objectIsActuallyHereTxt->at(randomNumber(_objectIsActuallyHereTxt->size())); break;
	}

}

int ScriptInterpreter::randomNumber(int max)
{
	return rand() % max;
}
