#pragma once
#include "Graf.h"


void Graf::znajdz_definicje_funkcji() {
	for (auto &_ktory_plik : pliki) {
		_ktory_plik.znajdz_funkcje_w_pliku();

		for (const auto& _funkcja_pliku : _ktory_plik.funkcje) {
			unsigned int licznik_spr = 0;
			//za pomoca tego licznika sprawdzam, ilosc NIEwystepowania tej nazwy w vectorze, przez co wiadomo kiedy push_backowac
			for (auto& nr_funkcji : wszystkie_funkcje_we_wszystkich_plikach) {
				if (_funkcja_pliku.nazwa_funkcji != nr_funkcji.nazwa_funkcji)
					licznik_spr++;			
			}
			if (licznik_spr >= wszystkie_funkcje_we_wszystkich_plikach.size()) {

				wszystkie_funkcje_we_wszystkich_plikach.push_back(_funkcja_pliku.nazwa_funkcji);
			}
		}
		std::cout << _ktory_plik.nazwa_pliku << ": "<<std::endl;
		for (auto & _funkcja_pliku : _ktory_plik.funkcje) {
			std::cout << "\t" << _funkcja_pliku.nazwa_funkcji << std::endl;
		}
	}

	/*unsigned int licznik_spr = 0;
			for (size_t i2 = 0; i2 < wszystkie_funkcje_we_wszystkich_plikach.size(); i2++) {
				if (nazwa != wszystkie_funkcje_we_wszystkich_plikach[i2].nazwa_funkcji)
					licznik_spr++;
			}*/


	/*for (size_t i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++) {
		std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji << std::endl;
	}*/

	/*for (int i = 0; i < pliki.size(); i++) {
		std::cout << pliki[i].nazwa_pliku << " : " << std::endl;
		for (int i2 = 0; i2 < pliki[i].funkcje.size(); i2++) {
			std::cout << "     " << pliki[i].funkcje[i2].nazwa_funkcji << std::endl;
		}
		std::cout << std::endl;
	}*/
}
