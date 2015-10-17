#include "ErrorHandler.h"


void ErrorHandler::errorMessage(int errorNumber, std::string errorString="")
{
	std::string _errorHelper;
	switch (errorNumber)
	{
	case (FILE_FAILED_TO_LOAD):
		_errorHelper = "Error 100: Nie uda³o siê wczytaæ pliku " + errorString + ". Plik nie istnieje lub program nie ma do niego dostêpu."; break;
	case (GRID_IS_NOT_A_SHELF) :
		_errorHelper = "Error 200: Pointer wskazuje na grida, wymagany shelf.";
	case (MAYBE_NULLPTR_EXCEPTION) :
		_errorHelper = "Error 201: Nullptr (Prawdopodobnie nie znaleziono obiektu, który mia³ byæ zanaleziony)";
	default:
		_errorHelper = "Niespodziewany b³¹d."; break;
	}
	//Znalezione na jakimœ forum
	//W du¿ym skrócie, tak to musi po prostu zostaæ
	MessageBoxA(NULL, _errorHelper.c_str(), NULL, 0x00000000L);
}