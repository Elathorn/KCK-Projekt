#pragma once
#include <Windows.h>
#include <string>

static class ErrorHandler
{
public:
	static void errorMessage(int errorNumber, std::string errorString);

public:
	static const int FILE_FAILED_TO_LOAD = 100;
};

