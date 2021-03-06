#include "ErrorHandler.h"


void ErrorHandler::errorMessage(int errorNumber, std::string errorString="")
{
	std::string _errorHelper;
	switch (errorNumber)
	{
	case (FILE_FAILED_TO_LOAD):
		_errorHelper = "Error 100: Nie uda�o si� wczyta� pliku " + errorString + ". Plik nie istnieje lub program nie ma do niego dost�pu."; break;
	case (GRID_IS_NOT_A_SHELF) :
		_errorHelper = "Error 200: Pointer wskazuje na grida, wymagany shelf.";break;
	case (MAYBE_NULLPTR_EXCEPTION) :
		_errorHelper = "Error 201: Nullptr (Prawdopodobnie nie znaleziono obiektu, kt�ry mia� by� zanaleziony)";break;
	case(SCRIPT_INTERPRETATION_ERROR) :
		_errorHelper = "Error 300: B��d interpretera skrypt�w.";break;
	case(WANT_NONEXIST_RESPONSE) :
		_errorHelper = "Error 301: Program oczekuje nieistniejacego typu odpowiedzi.";break;
	default:
		_errorHelper = "Niespodziewany b��d."; break;
	}
	//Znalezione na jakim� forum
	//W du�ym skr�cie, tak to musi po prostu zosta�
	MessageBoxA(NULL, _errorHelper.c_str(), NULL, 0x00000000L);
}