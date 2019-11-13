#include "Graf.h"


void Graf::znajdz_definicje_funkcji() {
	std::fstream plik_operacyjny;
	for (size_t ktory_plik = 0; ktory_plik < pliki.size(); ktory_plik++) {
		std::string linia;
		std::string slowo = "";
		plik_operacyjny.open(pliki[ktory_plik].nazwa_pliku, std::ios::in);
		while (!plik_operacyjny.eof()) {
			getline(plik_operacyjny, linia);
			std::vector<std::string> slowa_linijki;
			size_t pos = 0;
			std::string spacja = " ";
			std::string slowo;
			while ((pos = linia.find(spacja)) != std::string::npos) {
				slowo = linia.substr(0, pos);
				slowa_linijki.push_back(slowo);
				linia.erase(0, pos + spacja.length());
			}
			slowa_linijki.push_back(linia);
			while (slowa_linijki[0].find("\t") != std::string::npos) {
				size_t pozycja_tab = slowa_linijki[0].find("\t");
				slowa_linijki[0]=slowa_linijki[0].erase(0, 1);
			}
			if (slowa_linijki[0] == "void" || slowa_linijki[0]=="std::string" || slowa_linijki[0]=="int") {
				if (slowa_linijki[1].find("(") != std::string::npos) {
					size_t pozycja_nawiasu = slowa_linijki[1].find("(");
					std::string nazwa = slowa_linijki[1].substr(0, pozycja_nawiasu);
					if (nazwa.find("::") != std::string::npos) {
						std::string funkcja_klasy = "::";
						size_t pozycja_dwukropkow = nazwa.find(funkcja_klasy);
						nazwa = nazwa.erase(0, pozycja_dwukropkow + funkcja_klasy.length());
					}
					pliki[ktory_plik].funkcje.push_back(nazwa);
					unsigned int licznik_spr =0;
					for (size_t i2 = 0; i2 < wszystkie_funkcje_we_wszystkich_plikach.size(); i2++) {
						if (nazwa != wszystkie_funkcje_we_wszystkich_plikach[i2].nazwa_funkcji)
							licznik_spr++;
					}
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
		for (int i2 = 0; i2<pliki[i].funkcje.size(); i2++) {
			std::cout << "     " << pliki[i].funkcje[i2].nazwa_funkcji << std::endl;
		}
		std::cout << std::endl;
	}
}