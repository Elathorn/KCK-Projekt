#include "NaturalInterpreter.h"



NaturalInterpreter::NaturalInterpreter()
{
}


NaturalInterpreter::~NaturalInterpreter()
{
}

int NaturalInterpreter::recognizeOrder(string humanInput)
{
	string str = "Wez zielona paczke i przenies ja na wschodnia polke";
	string found;
	int position = str.find("Wez");
	cout << str.substr(position);
	getchar();
	//TEST DRUGI
}