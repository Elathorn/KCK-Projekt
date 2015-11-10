#pragma once
#include <iostream>
#include <string>
#include "ScriptInterpreter.h"
using namespace std;

class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	void runGraphic(); //todo: grafika, lul

private:
	ScriptInterpreter* _SI;
	Mechanic* _mech; //todo: zmieniæ to jakoœ?
};

