#pragma once
#include"Graf.h"
#include<sstream>

//trezeba zmienic definicje w headerze
std::string Graf::zamien_na_string_dla_funkcji_do_grafu()
{
	std::string strzalka = "->";
	std::string poczatek = "digraph G {";
	std::string temp;
	std::string tekst;
	std::ostringstream waga_polaczenia;		//definiuje przed bo po co definiowac to samo wiele razy

	for (size_t i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++)
	{
		//std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji << endl;
		for (size_t j = 0; j < wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami.size(); j++)
		{
			if (wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].waga != 0)		//drugi warunek po to zeby nie rysowalo polaczen z waga 0
			{
				//std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji << endl;
				waga_polaczenia << wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].waga;
				std::string sila_polaczenia = waga_polaczenia.str();
				waga_polaczenia.str("");
				waga_polaczenia.clear();

				temp += "\"" + wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji + "\"" + strzalka + "\"" + wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].nazwa_polaczonego_elementu + "\"" + "[ label = \"" + sila_polaczenia + "\" ];\n";
				
			}
		}
	}

	tekst = poczatek + temp + "}";		//zawsze zamykajcie nawiasy klamrowe :D

	std::cout << tekst; 		//tescik
	return tekst;
}