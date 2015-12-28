//////////////////
//Projekt KCK
//G�azik Micha�
//Hliwa Kamil
//
//W�zek wid�owy
//////////////////

#include "GraphicManager.h"
#include "NaturalInterpreter.h"
#include "ScriptInterpreter.h"
#include "Mechanic.h"

using namespace std;

GraphicManager * GM = NULL;
NaturalInterpreter * NI = NULL;
ScriptInterpreter * SI = NULL;
Mechanic * mechanic = NULL;

int main()
{
	GM = new GraphicManager();
	GM->runGraphic();

	return 0; 
}

