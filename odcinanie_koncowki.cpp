#pragma once
#include "Funkcje_od_stringow.h"

std::string odcinanie_koncowki(std::string slowo, std::string koncowka) {
	if (slowo.find(koncowka) != std::string::npos) {
		size_t pozycja_obcinacza = slowo.find(koncowka);
		slowo = slowo.substr(0, pozycja_obcinacza);
		return slowo;
	}
	else return false;
}