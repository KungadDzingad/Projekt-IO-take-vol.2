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

