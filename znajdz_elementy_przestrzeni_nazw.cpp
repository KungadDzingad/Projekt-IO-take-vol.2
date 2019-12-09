#pragma once
#include "Graf.h"



void Graf::znajdz_elementy_przestrzeni_nazw() {
	for (auto &_przestrzen : przestrzenie_nazw) {
		if (_przestrzen.nazwa_przestrzeni == "std") {
			_przestrzen.elementy_modulu = { "string", "ios", "cout",
				"endl", "list", "stringstream", "ofstringstream", "fstream" };
		}
		else {
			for (auto& _aktualny_plik : pliki) {
				fstream otwarty_plik;
				for (auto& _aktualny_modul : przestrzenie_nazw) {
				otwarty_plik.open(_aktualny_plik.nazwa_pliku, std::ios::in);
				_aktualny_modul.znajdz_elementy_modulu(otwarty_plik);
				otwarty_plik.close();
				}
			}
			
		}
	}
	/*for (int i = 0; i < przestrzenie_nazw.size(); i++) {
		std::cout << przestrzenie_nazw[i].nazwa_przestrzeni << " : " << std::endl;
		for (int j = 0; j < przestrzenie_nazw[i].elementy_modulu.size(); j++) {
			std::cout << "  " << przestrzenie_nazw[i].elementy_modulu[j] << std::endl;
		}
	}*/
	for (const auto& _przestrzen : przestrzenie_nazw) {
		std::cout << _przestrzen.nazwa_przestrzeni << std::endl;
		for (auto& funkcja : _przestrzen.funkcje_modulu) {
			std::cout << "\t" << funkcja.nazwa_funkcji << std::endl;
		}
	}
}
