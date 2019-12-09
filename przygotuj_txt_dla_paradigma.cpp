#pragma once
#include"Graf.h"
#include<sstream>

using namespace std;


string Graf::przygotuj_txt_dla_funkcji_do_visual_paradigma()
{
	std::string strzalka = "->";
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

				temp += wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji + strzalka + wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].nazwa_polaczonego_elementu + " : [" + sila_polaczenia + "]\n";

			}
		}
	}

	tekst = temp;		//zawsze zamykajcie nawiasy klamrowe :D

	//std::cout << tekst; 		//tescik

	fstream plik_do_zapisu;
	plik_do_zapisu.open("funkcje.txt", ios::out);
	if (plik_do_zapisu.good())
	{
		plik_do_zapisu << tekst;
	}
	plik_do_zapisu.close();

	return tekst;
}


string Graf::przygotuj_txt_dla_plikow_do_visual_paradigma()
{
	string strzala = "->";
	string temp;
	string tekst;
	//std::string liczba;

	ostringstream ss;	//plik.ilosc_linijek_kodu	
	ostringstream ss2;	//dla obydwu
	ostringstream ss3;	//dla wagi polaczenia

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
				temp += pliki[i].nazwa_pliku + "(" + ilosc_lini_pierwszego_pliku + ")" + strzala + pliki[i].polaczenia_miedzy_plikami[j].nazwa_polaczonego_elementu + "(" + ilosc_linii_drugiego_pliku + ")" + " : [" + sila_polaczenia + "]\n";
				//std::cout << temp << endl;
			}
		}
	}
	tekst = temp;	//trzeba pamietac o zamknieciu nawiasu klamrowego

	//std::cout << tekst << endl;		//tescik

	fstream plik_do_zapisu;
	plik_do_zapisu.open("pliki.txt", ios::out);
	if (plik_do_zapisu.good())
	{
		plik_do_zapisu << tekst;
	}

	plik_do_zapisu.close();

	return tekst;

}


string Graf::przygotuj_txt_dla_plikow_i_funkcji_do_visual_paradigma(string pliki_txt, string funkcje_txt)
{
	//cout << endl << funkcje_txt << pliki_txt << endl << "LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOL" << endl;
	string polaczenia_miedzy_funkcjami_a_plikiami;
	string temp;
	ostringstream ss;

	for (unsigned int i = 0; i < pliki.size(); i++)
	{
		for (unsigned int j = 0; j < pliki[i].funkcje.size(); j++)
		{
			ss << pliki[i].ilosc_linijek_kodu;
			string ile_linii = ss.str();
			ss.str("");
			ss.clear();
			temp = pliki[i].nazwa_pliku + "(" + ile_linii + ")\"->\"" + pliki[i].funkcje[j].nazwa_funkcji + " : " + "\n";
			polaczenia_miedzy_funkcjami_a_plikiami = polaczenia_miedzy_funkcjami_a_plikiami + temp;
		}
	}
	//cout << polaczenia_miedzy_funkcjami_a_plikiami << endl;

	string scalone = pliki_txt + funkcje_txt + polaczenia_miedzy_funkcjami_a_plikiami;

	fstream plik_do_zapisu;
	plik_do_zapisu.open("pliki_i_funkcje.txt", ios::out);
	if (plik_do_zapisu.good())
	{
		plik_do_zapisu << scalone;
	}
	plik_do_zapisu.close();

	return scalone;
}