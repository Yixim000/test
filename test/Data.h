#pragma once
#include <String>

using namespace std;

struct DaneOsobowe
{
	string imie;
	string f_imie;
	string nazwisko;
	string f_nazwiko;
	char plec;
	char f_plec;
	string data;
	string f_data;
};

class DataBaseInput
{
public:
	string imie = "Adam";
	string f_imie = "Adan";
	string nazwisko = "Kowalski";
	string f_nazwiko = "Kowanski";
	char plec = 'M';
	char f_plec = 'K';
	string data = "1.3.2003";
	string f_data = "2.4.2005";
public:
	DaneOsobowe wypisz();
};


