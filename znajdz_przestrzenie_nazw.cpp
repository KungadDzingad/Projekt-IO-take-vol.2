#pragma once
#include "Graf.h"


void Graf::znajdz_przestrzenie_nazw() {
	//najpierw szukanie "domyslnych" przestrzeni
	Modul wchodza_przestrzen("std");
	//przestrzenie_nazw.push_back(wchodza_przestrzen);
	

	//szukanie innych przestrzeni
	for (int aktualny_plik = 0; aktualny_plik < pliki.size(); ++aktualny_plik) {
		std::fstream otwarty_plik;
		std::string linia;
		otwarty_plik.open(pliki[aktualny_plik].nazwa_pliku, std::ios::in);
		while (!otwarty_plik.eof()) {
			getline(otwarty_plik, linia);

			std::vector<std::string> slowa_w_linii = dzielenie_na_slowa(linia); //dla dokladniejszego przeszukiwania
			slowa_w_linii[0] = usuwanie_tabulacji(slowa_w_linii[0]);

			for (int aktualne_slowo = 0; aktualne_slowo < slowa_w_linii.size(); ++aktualne_slowo) {
				if (slowa_w_linii[aktualne_slowo] == "namespace") {									//szukanie definicji namespace
					if (aktualne_slowo + 1 < slowa_w_linii.size()) {
						std::string nazwa_slowa;
						if (slowa_w_linii[aktualne_slowo + 1].find(";") != std::string::npos) {
							nazwa_slowa = odcinanie_koncowki(slowa_w_linii[aktualne_slowo + 1], ";");
							/*size_t pos = slowa_w_linii[aktualne_slowo + 1].find(";");
							nazwa_slowa = slowa_w_linii[aktualne_slowo + 1].substr(0, pos);		*/				
						}
						else if (slowa_w_linii[aktualne_slowo + 1].find("{") != std::string::npos) {
							nazwa_slowa = odcinanie_koncowki(slowa_w_linii[aktualne_slowo + 1], "{");
						}
						else {
							nazwa_slowa = slowa_w_linii[aktualne_slowo + 1];																		// licznik sluzy do sprawdzania powtarzania naz
						}
						int licznik = 0;
						for (int i = 0; i < przestrzenie_nazw.size(); i++) {
							if (przestrzenie_nazw[i].nazwa_przestrzeni != nazwa_slowa)
								licznik++;
						}
						if (licznik == przestrzenie_nazw.size()) {
							wchodza_przestrzen.nazwa_przestrzeni = nazwa_slowa;
							przestrzenie_nazw.push_back(wchodza_przestrzen);
						}
						break;
					}
				}
			}
		}
		otwarty_plik.close();
	}
	for (int i = 0; i < przestrzenie_nazw.size(); i++) {
		std::cout << przestrzenie_nazw[i].nazwa_przestrzeni << std::endl;
	}
}