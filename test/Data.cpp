#include "Data.h"
DaneOsobowe DataBaseInput::wypisz()
{
	DaneOsobowe e;
	e.imie = imie;
	e.f_imie = f_imie;
	e.nazwisko = nazwisko;
	e.f_nazwiko = f_nazwiko;
	e.data = data;
	e.f_data = f_data;
	e.plec = plec;
	e.f_plec = f_plec;
	return e;

}