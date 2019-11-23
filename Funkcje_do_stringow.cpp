#pragma once
#include "Funkcje_od_stringow.h"


std::vector<std::string> dzielenie_na_slowa(std::string linia) {
	size_t pos = 0;
	std::vector<std::string> slowa_linijki;
	std::string spacja = " ";
	while ((pos = linia.find(spacja)) != std::string::npos) {  //dzieli na slowa i apisujew vectorze
		std::string slowo = linia.substr(0, pos);
		slowa_linijki.push_back(slowo);
		linia.erase(0, pos + spacja.length());
	}
	slowa_linijki.push_back(linia);
	return slowa_linijki;
}

std::string odcinanie_koncowki(std::string slowo, std::string koncowka) {
	if (slowo.find(koncowka) != std::string::npos) {
		size_t pozycja_obcinacza = slowo.find(koncowka);
		slowo = slowo.substr(0, pozycja_obcinacza);
		return slowo;
	}
	else return false;
}

std::string odcinanie_poczatku(std::string linia, std::string poczatek) {
	size_t pozycja = linia.find(poczatek);
	linia = linia.erase(0, pozycja + poczatek.length());
	return linia;
}

std::string usuwanie_tabulacji(std::string linia) {
	while (linia.find("\t") != std::string::npos) { //usuwa tabulacje zeby nie bylo problemow w porownywaniu slow
		size_t pozycja_tab = linia.find("\t");
		linia = linia.erase(0, 1);
	}
	return linia;
}