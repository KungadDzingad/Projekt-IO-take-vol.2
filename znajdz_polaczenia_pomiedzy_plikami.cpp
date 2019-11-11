#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graf.h"

using namespace std;

void Graf::znajdz_polaczenia_pomiedzy_plikami()
{
	fstream otwarty_plik;
	string linia;
	
	//w tej pętli otwieramy wszystkie pliki po koleii do ostatniego
	for (int i = 0; i < pliki.size(); i++)
	{
		otwarty_plik.open(pliki[i].nazwa_pliku, ios::in);

		//pobieramy linie z obecnie otwartego pliku
		while (getline(otwarty_plik, linia))
		{
			//warunek jest spełniony jeśli znajdzie include w linii 
			if (linia.find("include \"") != string::npos)
			{
				//Wymazanie cudzysłowu na końcu includa
				linia.erase(linia.size() - 1, linia.size());
				//Wymazanie pierwszych 10 znakow (include i ")  
				linia.erase(0, 10);
				//przypisanie zawartości include do odpowiedniego wektora wewnątrz struktury
				Polaczenie obiekt(linia);
				pliki[i].polaczenia_miedzy_plikami.push_back(obiekt);
			}
		}
		//zamykamy obecnie otwarty plik
		otwarty_plik.close();
	}

	/*
	
	//sprawdzanie(wypisanie)

	for (int i = 0; i < pliki.size(); i++)
	{
		for (int j = 0; j < pliki[i].polaczenia_miedzy_plikami.size(); j++)
		{
			cout << pliki[i].polaczenia_miedzy_plikami[j].nazwa_polaczonego_elementu << endl;
		}
		
	}

	*/

}
