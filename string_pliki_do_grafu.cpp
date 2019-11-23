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
				if (pliki[i].polaczenia_miedzy_plikami[j].waga != 0)	//zeby nie sparwdzalo dla samego sb(xD)		trzeba dodac warunek ze jak bd waga polaczenia 0 to zeby nie wchodzilo do ifa(xD) - TEN IF JEST WGL NIE POTRZEBNY JAK COS
				{
					//std::cout << "nazwa pliku: " <<  pliki[i].nazwa_pliku << endl;
					//std::cout << "nazwa poloczonego elementu: " << pliki[i].polaczenia_miedzy_plikami[j].nazwa_polaczonego_elementu << endl;
					std::string ilosc_linii_drugiego_pliku;

					for (int k = 0; k < pliki.size(); k++) {
						if (pliki[k].nazwa_pliku == pliki[i].polaczenia_miedzy_plikami[j].nazwa_polaczonego_elementu) {
							ss2 << pliki[k].ilosc_linijek_kodu;
							ilosc_linii_drugiego_pliku = ss2.str();
							ss2.str("");
							ss2.clear();	
						}
					}

					ss3 << pliki[i].polaczenia_miedzy_plikami[j].waga;
					std::string sila_polaczenia = ss3.str();
					ss3.str("");
					ss3.clear();
					temp += "\"" + pliki[i].nazwa_pliku + "(" + ilosc_lini_pierwszego_pliku + ")\"" + strzala + "\"" + pliki[i].polaczenia_miedzy_plikami[j].nazwa_polaczonego_elementu + "(" + ilosc_linii_drugiego_pliku + ")\"" + "[ label = \"" + sila_polaczenia + "\" ];\n";
					//std::cout << temp << endl;
				}
			}
	}
	tekst = poczatek + temp + "}";	//trzeba pamietac o zamknieciu nawiasu klamrowego

	//std::cout << tekst << endl;		//tescik
	return tekst;

}