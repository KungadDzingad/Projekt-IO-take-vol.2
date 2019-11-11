#pragma once

#include <iostream>
#include <io.h>
#include <vector>
#include "Graf.h"

using namespace std;

void Graf::znajdz_pliki()
{
	//struktura _findata przechowuje informacje o znalezionym pliku
	_finddata_t danePliku;

	//w przypadku powodzenia _findfirst zwraca uchwyt identyfikujący poszukiwaną grupę plików (wykoszystyane potem)
	long uchwyt = _findfirst("*.cpp", &danePliku);

	//jeśli uchywyt == -1 to znaczy że nic nie znalazł
	if (uchwyt != -1)
	{
		//przypisujemy do naszego wektora nazwe pierwszej pobranej strukuty za pomocą _findfirst w tym celu tworzymy obiekt Plik
		Plik obiekt(danePliku.name);
		pliki.push_back(obiekt);

		//jeśli _findnext niczego nie znajduje to zwraca -1 dla tego ten warunek
		while (_findnext(uchwyt,&danePliku) != -1)
		{
			//przypisujemy do naszego wektora nazwe kolejnej pobranej strukuty za pomocą _findnext w tym celu tworzymy obiekt Plik
			Plik obiekt(danePliku.name);
			pliki.push_back(obiekt);
		} 
	}
	//usuwamy uchwyt
	_findclose(uchwyt);

	//======================================================Wykonujemy to samo w poszukiwaniu plików .h

	//w przypadku powodzenia _findfirst zwraca uchwyt identyfikujący poszukiwaną grupę plików (wykoszystyane potem)
	uchwyt = _findfirst("*.h", &danePliku);

	//jeśli uchywyt == -1 to znaczy że nic nie znalazł
	if (uchwyt != -1)
	{
		
		//przypisujemy do naszego wektora nazwe pierwszej pobranej strukuty za pomocą _findfirst w tym celu tworzymy obiekt Plik
		Plik obiekt(danePliku.name);
		pliki.push_back(obiekt);

		//jeśli _findnext niczego nie znajduje to zwraca -1 dla tego ten warunek
		while (_findnext(uchwyt, &danePliku) != -1)
		{
			//przypisujemy do naszego wektora nazwe kolejnej pobranej strukuty za pomocą _findnext w tym celu tworzymy obiekt Plik
			Plik obiekt(danePliku.name);
			pliki.push_back(obiekt);
		}
	}
	//usuwamy uchwyt
	_findclose(uchwyt);

/*
	//sprawdzanie(wypisanie)
	
	for (int i = 0; i < pliki.size(); i++)
	{
		cout << pliki[i].nazwa_pliku << endl;
	}
*/
	
}
