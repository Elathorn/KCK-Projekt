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
		Shelf* shelf = _mechanic->findShelf(script->at(adjToShelf));
		if (shelf == NULL) //jeœli nie znaleziono pó³ki
			return "Wozek nie odnalazl polki."; //todo: losowanie odpowiedzi
		MovableObject* obj = _mechanic->findMovableObject(script->at(colorOfMovableObject), script->at(sizeOfMovableObject));
		if (obj == NULL) //jeœli nie znaleziono obiektu
			return "Wozek nie znalazl przedmiotu do przeniesienia."; //todo: losowanie odpowiedzi
		if (_mechanic->moveObject(shelf, obj, lvlOfShelfChar))
			return "Nie udalo sie przeniesc przedmiotu. Najprawdopodobniej pelna polka."; //todo: losowanie odpowiedzi
		return "Hurra, udalo sie!"; //todo: wczytywanie tekstow
	}
	return "Rozkaz niezrozumialy, wozek nie wie co zrobic."; //todo: losowanie odpowiedzi
}
