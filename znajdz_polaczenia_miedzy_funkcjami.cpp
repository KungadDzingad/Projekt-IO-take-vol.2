#pragma once
#include "Graf.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Graf::znajdz_polaczenia_miedzy_funkcjami() {
	for (auto &_aktualny_plik : pliki) {
		for (auto &_sprawdzana_fun : wszystkie_funkcje_we_wszystkich_plikach) {
			if (_aktualny_plik.nazwa_pliku.find(".h") == std::string::npos) {
				for (auto &_funkcja_w_pliku : _aktualny_plik.funkcje) {
					if (_funkcja_w_pliku.nazwa_funkcji != _sprawdzana_fun.nazwa_funkcji) {
						std::fstream otwarty_plik;
						std::string linia;
						//std::cout << "dupa";
						otwarty_plik.open(_aktualny_plik.nazwa_pliku, std::ios::in);

						int licznik = _funkcja_w_pliku.polaczenia_miedzy_funkcjami.size();
						int licznik_klamer = 0;

						while (getline(otwarty_plik, linia)) {
							if (linia.find(_funkcja_w_pliku.nazwa_funkcji)) {
								if (linia.find('{') != std::string::npos) {
									licznik_klamer++;
								}
								if (linia.find('}') != std::string::npos) {
									licznik_klamer--;
								}
								while(getline(otwarty_plik, linia)){
									if (linia.find('{') != std::string::npos) {
										licznik_klamer++;
									}
									if (linia.find('}') != std::string::npos) {
										licznik_klamer--;
									}
									if (licznik_klamer == 0) {
										break;
									}
									std::vector<std::string> slowa_w_linii = dzielenie_na_slowa(linia);
									for (auto& _aktualne_slowo : slowa_w_linii) {//petla do spradzania kazdego slowa w linii
										if (_aktualne_slowo.find(_sprawdzana_fun.nazwa_funkcji) != std::string::npos) {
											if (_funkcja_w_pliku.polaczenia_miedzy_funkcjami.size() == licznik) {
												Polaczenie temp(_sprawdzana_fun.nazwa_funkcji);
												_funkcja_w_pliku.polaczenia_miedzy_funkcjami.push_back(temp);
												std::cout << "raz" << std::endl;
												std::cout << licznik << " " << _funkcja_w_pliku.polaczenia_miedzy_funkcjami.size() << std::endl;

											}
											else {
												_funkcja_w_pliku.polaczenia_miedzy_funkcjami[licznik].waga += 1;
												std::cout << "wiecej niz raz" << std::endl;
											}
										}
									}
									
								}
							}
						}
						otwarty_plik.close();
					}
				}
			}

		}
		/*for (int i = 0; i < pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.size(); i++) {
			std::cout << pliki[aktualny_plik].funkcje[i].polaczenia_miedzy_funkcjami[0].nazwa_polaczonego_elementu << std::endl;
		}*/
		for (int i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++) {
			if (_aktualny_plik.funkcje[0].nazwa_funkcji == wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji) {
				wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami = _aktualny_plik.funkcje[0].polaczenia_miedzy_funkcjami;
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