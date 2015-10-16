//////////////////
//Projekt KCK
//G³azik Micha³
//Hliwa Kamil
//
//Wózek wid³owy
//////////////////

#include "IOManager.h"
#include "NaturalInterpreter.h"
#include <iostream>
using namespace std;

int main()
{
	NaturalInterpreter nat;
	nat.recognizeOrder("String");

	/*
	//sandbox 
	map<string, string>* myMap;
	myMap = IOManager::loadMapFromFile("test.txt");
	for (auto elem : *myMap)
	{
		std::cout << elem.first << " " << elem.second << "\n";
	}
	getchar();
	//end of sandbox

	return 0; //test
	*/
}

