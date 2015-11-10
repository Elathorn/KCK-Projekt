#pragma once
#include <fstream>
using namespace std;

static class Logger
{
public:
	Logger();
	~Logger();

private:
	ofstream _logOutput;
};

