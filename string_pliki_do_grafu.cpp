#pragma once
#include"Graf.h"
#include<sstream>
//trezeba zmienic definicje w headerze

std::string Graf::zamien_na_string_dla_plikow_do_grafu()
{
	std::string strzala = "->";
	std::string poczatek = "digraph G {";
	std::string temp;
	std::string tekst;
	//std::string liczba;

	std::ostringstream ss;	//plik.ilosc_linijek_kodu	
	std::ostringstream ss2;	//dla obydwu
	std::ostringstream ss3;	//dla wagi polaczenia

	for (size_t i = 0; i < pliki.size(); i++)	//pierwszy plik
	{
		ss << pliki[i].ilosc_linijek_kodu;
		std::string ilosc_lini_pierwszego_pliku = ss.str();
		ss.str("");
		ss.clear();
		for (size_t j = 0; j < pliki[i].polaczenia_miedzy_plikami.size(); j++)		//porownywanie z kazdym innym po kolei		
		{
			if (i != j && pliki[i].polaczenia_miedzy_plikami[j].waga != 0)	//zeby nie sparwdzalo dla samego sb		trzeba dodac warunek ze jak bd waga polaczenia 0 to zeby nie wchodzilo do ifa
			{

				ss2 << pliki[j].ilosc_linijek_kodu;
				std::string ilosc_linii_drugiego_pliku = ss2.str();
				ss2.str("");
				ss2.clear();
				ss3 << pliki[i].polaczenia_miedzy_plikami[j].waga;
				std::string sila_polaczenia = ss3.str();
				ss3.str("");
				ss3.clear();

				temp += "\"" + pliki[i].nazwa_pliku + "(" + ilosc_lini_pierwszego_pliku + ")\"" + strzala + "\"" + pliki[j].nazwa_pliku + "(" + ilosc_linii_drugiego_pliku + ")\"" + "[ label = \"" + sila_polaczenia + "\" ];\n";


			}
		}

	}
	tekst = poczatek + temp + "}";	//trzeba pamietac o zamknieciu nawiasu klamrowego

	std::cout << tekst << endl;		//tescik
	return tekst;

}