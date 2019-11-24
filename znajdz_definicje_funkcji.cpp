#pragma once
#include "Graf.h"


void Graf::znajdz_definicje_funkcji() {
	std::fstream plik_operacyjny;
	for (auto &_ktory_plik : pliki) {
		std::string linia;
		std::string slowo = "";
		plik_operacyjny.open(_ktory_plik.nazwa_pliku, std::ios::in);
		while (!plik_operacyjny.eof()) {
			getline(plik_operacyjny, linia);
			
			std::vector<std::string> slowa_linijki = dzielenie_na_slowa(linia);
			slowa_linijki[0] = usuwanie_tabulacji(slowa_linijki[0]);

			if (slowa_linijki[0] == "void" || slowa_linijki[0] == "std::string" || slowa_linijki[0] == "int" || slowa_linijki[0].find("vector")!=std::string::npos) {
				if (slowa_linijki[1].find("(") != std::string::npos) {
					std::string nazwa = odcinanie_koncowki(slowa_linijki[1], "(");
					if (nazwa.find("::") != std::string::npos) {
						nazwa = odcinanie_poczatku(nazwa, "::");
					}
					_ktory_plik.funkcje.push_back(nazwa);

					unsigned int licznik_spr = 0;
					//za pomoca tego licznika sprawdzam, ilosc NIEwystepowania tej nazwy w vectorze, przez co wiadomo kiedy push_backowac
					for (auto &nr_funkcji : wszystkie_funkcje_we_wszystkich_plikach) {
						if (nazwa != nr_funkcji.nazwa_funkcji)
							licznik_spr++;
					}
					
					/*unsigned int licznik_spr = 0;				
					for (size_t i2 = 0; i2 < wszystkie_funkcje_we_wszystkich_plikach.size(); i2++) {
						if (nazwa != wszystkie_funkcje_we_wszystkich_plikach[i2].nazwa_funkcji)
							licznik_spr++;
					}*/
					if (licznik_spr >= wszystkie_funkcje_we_wszystkich_plikach.size()) {

						wszystkie_funkcje_we_wszystkich_plikach.push_back(nazwa);
					}
				}
			}
		}
		plik_operacyjny.close();


	}
	/*for (size_t i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++) {
		std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].nazwa_funkcji << std::endl;
	}*/

	for (int i = 0; i < pliki.size(); i++) {
		std::cout << pliki[i].nazwa_pliku << " : " << std::endl;
		for (int i2 = 0; i2 < pliki[i].funkcje.size(); i2++) {
			std::cout << "     " << pliki[i].funkcje[i2].nazwa_funkcji << std::endl;
		}
		std::cout << std::endl;
	}
}