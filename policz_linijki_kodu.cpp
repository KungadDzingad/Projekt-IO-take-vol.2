#pragma once
#include "Graf.h"
#include <iostream>
#include <fstream>
#include <string>
void Graf::policz_linijki_kodu_dla_pliku()
{
	for (int i = 0; i < pliki.size(); i++) {
		fstream file;
		int ilosc = 0;
		string linijka;

		file.open(pliki[i].nazwa_pliku, std::ios::in);

		while (!file.eof())
		{
			getline(file, linijka);
			pliki[i].ilosc_linijek_kodu++;
		}


		file.close();
	}
	/*for (int i = 0; i < pliki.size(); i++) {
		std::cout << pliki[i].nazwa_pliku << " " << pliki[i].ilosc_linijek_kodu << std::endl;
	}*/


}