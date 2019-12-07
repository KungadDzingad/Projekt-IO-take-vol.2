#pragma once
#include "Graf.h"
#include <sstream>


using namespace std;

string Graf::string_dla_plikow_i_funkcji(string pierwsza_czesc_stringa, string druga_czesc_stringa)
{
	string poczatek = "digraph G {";
	pierwsza_czesc_stringa.erase(0, 11);
	pierwsza_czesc_stringa.erase(pierwsza_czesc_stringa.length() - 1, pierwsza_czesc_stringa.length());
	druga_czesc_stringa.erase(0, 11);
	druga_czesc_stringa.erase(druga_czesc_stringa.length() - 1, druga_czesc_stringa.length());
	string trzecia_czesc_stringa;
	string temp;
	ostringstream ss;
	std::string styl_strzalki = "[color=\"purple\", penwidth = 2]";	//¿eby strzalki inny kolor mialy


	for (unsigned int i = 0; i < pliki.size(); i++)
	{
		for (unsigned int j = 0; j < pliki[i].funkcje.size(); j++)
		{
			ss << pliki[i].ilosc_linijek_kodu;
			string ile_linii = ss.str();
			ss.str("");
			ss.clear();
			temp = "\"" + pliki[i].nazwa_pliku + "(" + ile_linii + ")\"->\"" + pliki[i].funkcje[j].nazwa_funkcji + "\""+ styl_strzalki + ";\n";
			//std::cout << temp << endl;";\n";
			trzecia_czesc_stringa = trzecia_czesc_stringa + temp;
		}
	}
	cout << trzecia_czesc_stringa << endl;

	string scalone = poczatek + pierwsza_czesc_stringa + druga_czesc_stringa + trzecia_czesc_stringa + "\n}";

	return scalone;
}