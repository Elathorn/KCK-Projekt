#include "NaturalInterpreter.h"
#include <cstdio>
#include <iostream>
using namespace std;


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
	int position = str.find("zielona");
	cout << position << endl;
	string substr = str.substr(position);
	

	getchar();
	return 0;
	//TEST DRUGI
}