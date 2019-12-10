#include "Graf.h"

void Modul::znajdz_elementy_modulu(std::fstream &otwarty_plik) {
	std::vector<std::string> slowa_kluczowe = { "int","vector","float", "void","string" };
	std::string linia;

	//licznik klamer pozwala bezpiecznie przejsc od otwarca do zamkniecia glownej klamry namespacea
	int licznik_klamer = 0;

	while (!otwarty_plik.eof()) {		
		getline(otwarty_plik, linia);
		std::vector<std::string> slowa_w_linii = Wojtas::dzielenie_na_slowa(linia);
		if (slowa_w_linii[0] == "namespace" && slowa_w_linii.size()>1) {
			if (slowa_w_linii[1] == nazwa_przestrzeni || slowa_w_linii[1] == nazwa_przestrzeni + "{") {			
				Wojtas::szukanie_klamer(linia, licznik_klamer);
				linia = Wojtas::usuwanie_tabulacji(linia);
				while (getline(otwarty_plik, linia)) {
					Wojtas::szukanie_klamer(linia, licznik_klamer);
					if (licznik_klamer == 0) {
						break;
					}
					//jesli wszystkie klamry "zamkna sie" to wychodzi z petli;
					std::string spacja = " ";
					slowa_w_linii = Wojtas::dzielenie_na_slowa(linia);
					slowa_w_linii[0] = Wojtas::usuwanie_tabulacji(slowa_w_linii[0]);
					//zapisywanie elementow i metody namespace
					for (auto& _kluczowe : slowa_kluczowe) {
						if (slowa_w_linii[0].find(_kluczowe) != std::string::npos) {
							//po znalezieniu slowa kluczowego sprawdza nastepne slowo
							if (slowa_w_linii.size() > 1) {
								std::string nazwa_slowa;
								if (slowa_w_linii[1].find("(") == std::string::npos && licznik_klamer == 1) {
									if (slowa_w_linii[1].find(";") != std::string::npos) {//jedno z oczyszczan ze zbednych znakow
										nazwa_slowa = Wojtas::odcinanie_koncowki(slowa_w_linii[1], ";");
									}
									else if (slowa_w_linii[1].find("=") != std::string::npos) {
										nazwa_slowa = Wojtas::odcinanie_koncowki(slowa_w_linii[1], "=");
									}

									else {
										nazwa_slowa = slowa_w_linii[1];							// licznik sluzy do sprawdzania powtarzania nazw
									}
								}
								else if (slowa_w_linii[1].find("(") != std::string::npos) { //tutaj zapisuje metode, jak znajdzie nawias
									if (licznik_klamer == 1 || licznik_klamer == 2) {
										znajdz_funkcje_w_module(slowa_w_linii[1]);
										break;
									}
								}
								else break;
								//za pomoca licznika sprawdza wystepowanie nazwy w vectorze
								dodaj_niepowtarzajacy_sie_modul(nazwa_slowa);
								break;
							}
						}
					}


				}
			}
		}
	}
}

void Modul::znajdz_funkcje_w_module(std::string slowo) {
	std::string nazwa_slowa = Wojtas::odcinanie_koncowki(slowo, "(");
	int licznik = 0;
	for (auto& funkcja : funkcje_modulu) {
		if (funkcja.nazwa_funkcji != nazwa_slowa)licznik++;		
	}
	if (licznik == funkcje_modulu.size()) {
		nazwa_slowa = nazwa_przestrzeni + "::" + nazwa_slowa;
		int licznik = 0;
		for (auto& _element : funkcje_modulu) {
			if (_element.nazwa_funkcji != nazwa_slowa) {
				licznik++;
			}
		}
		if (licznik == funkcje_modulu.size()) {
			Funkcja wchodzaca_funkcja(nazwa_slowa);
			funkcje_modulu.push_back(wchodzaca_funkcja);
		}
	}
	//break;
}

void Modul::dodaj_niepowtarzajacy_sie_modul(std::string nazwa_slowa) {
	int licznik = 0;
	for (auto& _element : elementy_modulu) {
		if (_element != nazwa_slowa)
			licznik++;
	}
	if (licznik == elementy_modulu.size()) {
		nazwa_slowa = nazwa_przestrzeni + "::" + nazwa_slowa;
		elementy_modulu.push_back(nazwa_slowa);
	}
}