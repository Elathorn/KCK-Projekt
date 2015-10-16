#include "ErrorHandler.h"


void ErrorHandler::errorMessage(int errorNumber, std::string errorString="")
{
	std::string _errorHelper;
	switch (errorNumber)
	{
	case (FILE_FAILED_TO_LOAD) :
		_errorHelper = "Nie uda³o siê wczytaæ pliku " + errorString + ". Plik nie istnieje lub program nie ma do niego dostêpu."; break;
	default:
		_errorHelper = "Niespodziewany b³¹d."; break;
	}
	//Znalezione na jakimœ forum
	//W du¿ym skrócie, tak to musi po prostu zostaæ
	MessageBoxA(NULL, _errorHelper.c_str(), NULL, 0x00000000L);
}