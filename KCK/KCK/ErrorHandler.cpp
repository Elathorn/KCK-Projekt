#include "ErrorHandler.h"


void ErrorHandler::errorMessage(int errorNumber, std::string errorString="")
{
	std::string _errorHelper;
	switch (errorNumber)
	{
	case (FILE_FAILED_TO_LOAD) :
		_errorHelper = "Nie uda�o si� wczyta� pliku " + errorString + ". Plik nie istnieje lub program nie ma do niego dost�pu."; break;
	default:
		_errorHelper = "Niespodziewany b��d."; break;
	}
	//Znalezione na jakim� forum
	//W du�ym skr�cie, tak to musi po prostu zosta�
	MessageBoxA(NULL, _errorHelper.c_str(), NULL, 0x00000000L);
}