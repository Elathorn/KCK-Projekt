#pragma once
#include <list>
#include <string>

using namespace std;

class NaturalInterpreter //interpretacja j�zyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
private:
	list<string> _ordersList;

};

