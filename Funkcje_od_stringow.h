#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace Wojtas {
	//tutaj zawarte sa funkcje do ulatwienia i lepszej czytelnosci operowania na stringach
	std::vector<std::string> dzielenie_na_slowa(std::string linia);
	std::string usuwanie_tabulacji(std::string linia);
	std::string odcinanie_koncowki(std::string slowo, std::string koncowka);
	std::string odcinanie_poczatku(std::string linia, std::string poczatek);
	void szukanie_klamer(std::string&, int&);
}