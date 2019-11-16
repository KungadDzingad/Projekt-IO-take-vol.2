#pragma once
#include "Funkcje_od_stringow.h"
std::string usuwanie_tabulacji(std::string linia) {
	while (linia.find("\t") != std::string::npos) { //usuwa tabulacje zeby nie bylo problemow w porownywaniu slow
		size_t pozycja_tab = linia.find("\t");
		linia = linia.erase(0, 1);
	}
	return linia;
}