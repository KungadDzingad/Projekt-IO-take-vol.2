#include "Graf.h"
#include <iostream>
#include <sstream>


int main() {
	Graf* program = new Graf;
	program->znajdz_pliki();
	program->policz_linijki_kodu_dla_pliku();
	program->znajdz_polaczenia_pomiedzy_plikami();

	program->znajdz_definicje_funkcji();
	program->znajdz_funkcje_i_wagi_pomiedzy_plikami();
	program->znajdz_polaczenia_miedzy_funkcjami();

	program->znajdz_przestrzenie_nazw();
	program->znajdz_elementy_przestrzeni_nazw();

	std::string graf_pliki = program->zamien_na_string_dla_plikow_do_grafu();
	std::string graf_funkcje = program->zamien_na_string_dla_funkcji_do_grafu();
	program->rysuj_graf(graf_pliki, "graf_plikow");
	program->rysuj_graf(graf_funkcje, "graf_funkcji");
	delete program;
	system("Pause");
	return 0;
}