#pragma once
#include "Graf.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Graf::znajdz_polaczenia_miedzy_funkcjami() {
	for (auto &_aktualny_plik : pliki) {
		for (auto& _funkcja_w_pliku : _aktualny_plik.funkcje) {			
			if (_aktualny_plik.nazwa_pliku.find(".h") == std::string::npos) {
				for (auto& _sprawdzana_fun : wszystkie_funkcje_we_wszystkich_plikach) {
					if (_funkcja_w_pliku.nazwa_funkcji != _sprawdzana_fun.nazwa_funkcji) {
						std::fstream otwarty_plik;
						std::string linia;
						//std::cout << "dupa";
						otwarty_plik.open(_aktualny_plik.nazwa_pliku, std::ios::in);

						int licznik = _funkcja_w_pliku.polaczenia_miedzy_funkcjami.size();
						int licznik_klamer = 0;

						while (getline(otwarty_plik, linia)) {
							if (linia.find(_funkcja_w_pliku.nazwa_funkcji)!=std::string::npos) {
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
									if (licznik_klamer == 0) {
										break;
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
		/*for (int i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++) {
			for (int j = 0; j < _aktualny_plik.funkcje.size(); j++) {
				if (_aktualny_plik.funkcje[j].nazwa_funkcji == wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji) {
					wszystkie_funkcje_we_wszystkich_plikach[i].polaczenia_miedzy_funkcjami = _aktualny_plik.funkcje[j].polaczenia_miedzy_funkcjami;
				}
			}
		}*/
		/*for (auto &_wsz_fun : wszystkie_funkcje_we_wszystkich_plikach) {
			for (const auto &_fun_plik : _aktualny_plik.funkcje) {
				if (_fun_plik.nazwa_funkcji == _wsz_fun.nazwa_funkcji) {
					_wsz_fun.polaczenia_miedzy_funkcjami = _fun_plik.polaczenia_miedzy_funkcjami;
				}
			}
		}*/

	}
	for (auto &plik : pliki) {
		if (plik.nazwa_pliku.find(".h") == std::string::npos) {
			for (auto &fun_plik : plik.funkcje) {
				/*std::cout << fun_plik.nazwa_funkcji << " : \n";
				for (auto i : fun_plik.polaczenia_miedzy_funkcjami) {
					std::cout << "\t" << i.nazwa_polaczonego_elementu << std::endl;
				}*/
				for (auto& funk : wszystkie_funkcje_we_wszystkich_plikach) {
					if (fun_plik.nazwa_funkcji == funk.nazwa_funkcji) {
						funk.polaczenia_miedzy_funkcjami = fun_plik.polaczenia_miedzy_funkcjami;
					}
				}
			}
		}
	}
