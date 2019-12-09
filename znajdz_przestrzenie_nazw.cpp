#pragma once
#include "Graf.h"


void Graf::znajdz_przestrzenie_nazw() {
	//najpierw szukanie "domyslnych" przestrzeni
	Modul wchodza_przestrzen("std");
	//przestrzenie_nazw.push_back(wchodza_przestrzen);
	

	//szukanie innych przestrzeni
	for (auto& _aktualny_plik : pliki) {
		_aktualny_plik.znajdz_moduly();
		for (auto& _namespace : _aktualny_plik.namespacey) {
			unsigned int licznik_spr = 0;
			//za pomoca tego licznika sprawdzam, ilosc NIEwystepowania tej nazwy w vectorze, przez co wiadomo kiedy push_backowac
			for (auto& nr_przestzreni : przestrzenie_nazw) {
				if (_namespace.nazwa_przestrzeni != nr_przestzreni.nazwa_przestrzeni)
					licznik_spr++;
			}
			if (licznik_spr >= przestrzenie_nazw.size()) {

				przestrzenie_nazw.push_back(_namespace.nazwa_przestrzeni);
			}
		}
		
	}
	for (int i = 0; i < przestrzenie_nazw.size(); i++) {
		std::cout << przestrzenie_nazw[i].nazwa_przestrzeni << std::endl;
	}
}