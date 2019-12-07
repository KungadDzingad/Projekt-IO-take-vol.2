#pragma once
#include <sstream>
#include "Graf.h"



	using namespace std;

	std::string Graf::zamien_na_string_dla_plikow_z_modulem_do_grafu()
	{
		std::string strzalka = "->";
		std::string poczatek = "digraph G {";
		std::string temp;
		std::string tekst;
		std::ostringstream waga_polaczenia;		//waga 1 wszedzie bedzie? chyba tak. powinno byc: 1 czy "1"??? pierwszy raz widze ostringa

		for (size_t i = 0; i < przestrzenie_nazw.size(); i++) //dla kazdej przestrzeni nazw (ale i tak mamy tylko std)
		{
			for (size_t j = 0; j < przestrzenie_nazw[i].funkcje_modulu.size(); j++) //dla kazdego pliku w tej przestrzeni(ZAKLADAM ZE W POLU ELEMENTY MODULU ZNAJDUJĄ SIE NAZWY PLIKOW W DANEJ PRZESTRZENI NAZW)
			{
				//std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji << endl;
				//waga_polaczenia << wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].waga;
				std::string sila_polaczenia = waga_polaczenia.str();
				waga_polaczenia.str("");
				waga_polaczenia.clear();

				temp += "\"" + przestrzenie_nazw[i].nazwa_przestrzeni + "\"" + strzalka + "\"" + przestrzenie_nazw[i].funkcje_modulu[j].nazwa_funkcji; // + "\"" + "[ label = \"" + sila_polaczenia + "\" ];\n";
			}
		}
	tekst = poczatek + temp + "}";		//zawsze zamykajcie nawiasy klamrowe :D

	std::cout << tekst; 		//tescik
	return tekst;
	}

