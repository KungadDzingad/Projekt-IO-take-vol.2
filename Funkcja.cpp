#pragma once
#include "Graf.h"

void Funkcja::znajdz_polaczone_funkcje(Funkcja sprawdzana_fun,std::fstream &otwarty_plik) {
	std::string szukany_string= Wojtas::odcinanie_poczatku(sprawdzana_fun.nazwa_funkcji, "::");
	std::string linia;	
	int licznik = polaczenia_miedzy_funkcjami.size();
	int licznik_klamer = 0;
	while (getline(otwarty_plik, linia)) {
		if (linia.find(nazwa_funkcji) != std::string::npos) {
			Wojtas::szukanie_klamer(linia, licznik_klamer);
			while (getline(otwarty_plik, linia)) {
				Wojtas::szukanie_klamer(linia, licznik_klamer);
				std::vector<std::string> slowa_w_linii = Wojtas::dzielenie_na_slowa(linia);
				slowa_w_linii[0] = Wojtas::usuwanie_tabulacji(slowa_w_linii[0]);
				for (const auto& _aktualne_slowo : slowa_w_linii) {//petla do spradzania kazdego slowa w linii
					if (_aktualne_slowo.find(szukany_string) != std::string::npos) {
						if (polaczenia_miedzy_funkcjami.size() == licznik) {
							Polaczenie temp(sprawdzana_fun.nazwa_funkcji);
							polaczenia_miedzy_funkcjami.push_back(temp);
						}
						else {
							polaczenia_miedzy_funkcjami[licznik].waga += 1;
							//std::cout << "wiecej niz raz" << std::endl;
						}
					}
				}
				if (licznik_klamer == 0) {
					break;
				}

			}
		}
	}	
}