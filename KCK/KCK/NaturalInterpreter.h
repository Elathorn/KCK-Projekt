#pragma once
#include <list>
#include <string>

using namespace std;

class NaturalInterpreter //interpretacja jêzyka naturalnego
{
public:
	NaturalInterpreter();
	~NaturalInterpreter();
private:
	list<string> _ordersList;

};

