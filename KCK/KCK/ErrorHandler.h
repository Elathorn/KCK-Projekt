#pragma once
#include <Windows.h>
#include <string>

static class ErrorHandler
{
public:
	static void errorMessage(int errorNumber, std::string errorString);

public:
	//1XX files errors
	static const int FILE_FAILED_TO_LOAD = 100;
	//2XX pointers errors
	static const int GRID_IS_NOT_A_SHELF = 200;
	static const int MAYBE_NULLPTR_EXCEPTION = 201;
	//3XX logic errors
	static const int SCRIPT_INTERPRETATION_ERROR = 300;
};

