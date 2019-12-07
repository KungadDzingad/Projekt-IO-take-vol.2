#pragma once
#include "Graf.h"

std::vector<std::string> slowa_kluczowe = { "int","vector", "std::string", "float", "void","string" };

void Graf::znajdz_elementy_przestrzeni_nazw() {
	for (int nr_przestrzeni = 0; nr_przestrzeni < przestrzenie_nazw.size(); nr_przestrzeni++) {
		if (przestrzenie_nazw[nr_przestrzeni].nazwa_przestrzeni == "std") {
			przestrzenie_nazw[nr_przestrzeni].elementy_modulu = { "string", "ios", "cout",
				"endl", "list", "stringstream", "ofstringstream", "fstream" };
		}
		else {
			for (int aktualny_plik = 0; aktualny_plik < pliki.size(); aktualny_plik++) {
				fstream otwarty_plik;
				std::string linia;
				otwarty_plik.open(pliki[aktualny_plik].nazwa_pliku, std::ios::in);
				while (!otwarty_plik.eof()) {
					size_t licznik_klamer = 0;
					getline(otwarty_plik, linia);
					if (linia.find("namespace " + przestrzenie_nazw[nr_przestrzeni].nazwa_przestrzeni) != std::string::npos) {
						//licznik klamer pozwala bezpiecznie przejsc od otwarca do zamkniecia glownej klamry namespacea
						if (linia.find("{") != std::string::npos) {
							licznik_klamer++;
						}
						if (linia.find("}") != std::string::npos) {
							licznik_klamer--;
						}
						linia = usuwanie_tabulacji(linia);
						while (getline(otwarty_plik, linia)) {
							if (linia.find("{") != std::string::npos) {
								licznik_klamer++;
							}
							if (linia.find("}") != std::string::npos) {
								licznik_klamer--;
							}
							//jesli wszystkie klamry "zamkna sie" to wychodzi z petli;
							if (licznik_klamer == 0) break;
							std::string spacja = " ";
							std::vector<std::string> slowa_w_linii = dzielenie_na_slowa(linia);
							slowa_w_linii[0] = usuwanie_tabulacji(slowa_w_linii[0]);
							//zapisywanie elementow i metody namespace
							for (size_t aktualne_slowo = 0; aktualne_slowo < slowa_w_linii.size(); aktualne_slowo++) {
								for (size_t nr_kluczowego = 0; nr_kluczowego < slowa_kluczowe.size(); nr_kluczowego++) {
									if (slowa_w_linii[aktualne_slowo] == slowa_kluczowe[nr_kluczowego] ) {
										//po znalezieniu slowa kluczowego sprawdza nastepne slowo
										if (aktualne_slowo + 1 < slowa_w_linii.size()) {				
											aktualne_slowo++;
											std::string nazwa_slowa;
											if (slowa_w_linii[aktualne_slowo ].find(";") != std::string::npos) {//jedno z oczyszczan ze zbednych znakow
												nazwa_slowa = odcinanie_koncowki(slowa_w_linii[aktualne_slowo ], ";");
											}
											else if (slowa_w_linii[aktualne_slowo ].find("=") != std::string::npos) {
												size_t pos = slowa_w_linii[aktualne_slowo].find("=");
												nazwa_slowa = slowa_w_linii[aktualne_slowo].substr(0, pos);
											}
											else if (slowa_w_linii[aktualne_slowo ].find("(") != std::string::npos) { //tutaj zapisuje metode, jak znajdzie nawias
												size_t pos = slowa_w_linii[aktualne_slowo].find("(");
												nazwa_slowa = slowa_w_linii[aktualne_slowo].substr(0, pos);
												int licznik = 0;
												for (int i = 0; i < przestrzenie_nazw[nr_przestrzeni].funkcje_modulu.size(); i++) {
													if (przestrzenie_nazw[nr_przestrzeni].funkcje_modulu[i].nazwa_funkcji != nazwa_slowa)
														licznik++;
												}
												if (licznik == przestrzenie_nazw.size()) {
													Funkcja wchodzaca_funkcja(nazwa_slowa);
													przestrzenie_nazw[nr_przestrzeni].funkcje_modulu.push_back(wchodzaca_funkcja);												}
													//break;
											}
											else {
												nazwa_slowa = slowa_w_linii[aktualne_slowo];							// licznik sluzy do sprawdzania powtarzania nazw
											}

											//za pomoca licznika sprawdza wystepowanie nazwy w vectorze
											int licznik = 0;
											for (int i = 0; i < przestrzenie_nazw[nr_przestrzeni].elementy_modulu.size(); i++) {
												if (przestrzenie_nazw[nr_przestrzeni].elementy_modulu[i] != nazwa_slowa)
													licznik++;
											}
											if (licznik == przestrzenie_nazw[nr_przestrzeni].elementy_modulu.size()) {						
												przestrzenie_nazw[nr_przestrzeni].elementy_modulu.push_back(nazwa_slowa);											}
											break;
										}
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
	for (int i = 0; i < przestrzenie_nazw.size(); i++) {
		std::cout << przestrzenie_nazw[i].nazwa_przestrzeni << " : " << std::endl;
		for (int j = 0; j < przestrzenie_nazw[i].elementy_modulu.size(); j++) {
			std::cout << "  " << przestrzenie_nazw[i].elementy_modulu[j] << std::endl;
		}
	}
}