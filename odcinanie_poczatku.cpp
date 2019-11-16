#pragma once
#include "Funkcje_od_stringow.h"

std::string odcinanie_poczatku(std::string linia, std::string poczatek) {
	size_t pozycja = linia.find(poczatek);
	linia = linia.erase(0, pozycja + poczatek.length());
	return linia;
}