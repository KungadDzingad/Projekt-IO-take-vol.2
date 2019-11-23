#pragma once
#include "Graf.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Graf::znajdz_polaczenia_miedzy_funkcjami() {
	for (int aktualny_plik = 0; aktualny_plik < pliki.size(); aktualny_plik++) {
		for (int sprawdzana_fun = 0; sprawdzana_fun < wszystkie_funkcje_we_wszystkich_plikach.size(); sprawdzana_fun++) {
			if (pliki[aktualny_plik].nazwa_pliku.find(".h") == std::string::npos) {
				if (pliki[aktualny_plik].funkcje[0].nazwa_funkcji != wszystkie_funkcje_we_wszystkich_plikach[sprawdzana_fun].nazwa_funkcji) {
					std::fstream otwarty_plik;
					std::string linia;
					//std::cout << "dupa";
					otwarty_plik.open(pliki[aktualny_plik].nazwa_pliku, std::ios::in);
					int licznik = pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.size();
					while (getline(otwarty_plik, linia)) {
						std::vector<std::string> slowa_w_linii = dzielenie_na_slowa(linia);
						for (int nr_slowa = 0; nr_slowa < slowa_w_linii.size(); nr_slowa++) {//petla do spradzania kazdego slowa w linii
							if (slowa_w_linii[nr_slowa].find(wszystkie_funkcje_we_wszystkich_plikach[sprawdzana_fun].nazwa_funkcji) != std::string::npos) {
								if (pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.size() == licznik) {
									Polaczenie temp(wszystkie_funkcje_we_wszystkich_plikach[sprawdzana_fun].nazwa_funkcji);
									pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.push_back(temp);
									std::cout << "raz" << std::endl;
									std::cout << licznik << " " << pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.size() << std::endl;

								}
								else {
									pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami[licznik].waga += 1;
									std::cout << "wiecej niz raz" << std::endl;
								}
							}
						}
					}
					otwarty_plik.close();
				}
			}

		}
		/*for (int i = 0; i < pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.size(); i++) {
			std::cout << pliki[aktualny_plik].funkcje[i].polaczenia_miedzy_funkcjami[0].nazwa_polaczonego_elementu << std::endl;
		}*/
		for (int i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++) {
			if (pliki[aktualny_plik].funkcje[0].nazwa_funkcji == wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji) {
				wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami = pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami;
			}
		}

	}
	/*for (int i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++) {
		std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji << " : " << std::endl;
		for (int j = 0; j < wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami.size(); j++) {
			std::cout << "      " << wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].nazwa_polaczonego_elementu << " " << wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami[j].waga << std::endl;
		}
	}*/
}