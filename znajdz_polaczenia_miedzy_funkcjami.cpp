#pragma once
#include "Graf.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Graf::znajdz_polaczenia_miedzy_funkcjami() {
	for (auto& _aktualny_plik : pliki) {
		if (_aktualny_plik.nazwa_pliku.find(".h") == std::string::npos){
			for (auto& _funkcja_w_pliku : _aktualny_plik.funkcje) {
				for (auto& _sprawdzana_fun : wszystkie_funkcje_we_wszystkich_plikach) {
					if (_funkcja_w_pliku.nazwa_funkcji != _sprawdzana_fun.nazwa_funkcji) {
						std::fstream otwarty_plik;
						otwarty_plik.open(_aktualny_plik.nazwa_pliku, std::ios::in);
						_funkcja_w_pliku.znajdz_polaczone_funkcje(_sprawdzana_fun, otwarty_plik);
						otwarty_plik.close();
					}
				}
			}

		}
		/*for (int i = 0; i < pliki[aktualny_plik].funkcje[0].polaczenia_miedzy_funkcjami.size(); i++) {
			std::cout << pliki[aktualny_plik].funkcje[i].polaczenia_miedzy_funkcjami[0].nazwa_polaczonego_elementu << std::endl;
		}*/
		for (const auto& _fun_plik : _aktualny_plik.funkcje) {
			if (_aktualny_plik.nazwa_pliku.find(".h") == std::string::npos) {
				for (auto& _wsz_fun : wszystkie_funkcje_we_wszystkich_plikach) {
					if (_fun_plik.nazwa_funkcji == _wsz_fun.nazwa_funkcji) {
						_wsz_fun.polaczenia_miedzy_funkcjami = _fun_plik.polaczenia_miedzy_funkcjami;
					}
				}
			}
		}
	}
}
