#include "Graf.h"
#include "menu.h"
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
	std::string graf_pliki_funkcje= program->string_dla_plikow_i_funkcji(graf_pliki,graf_funkcje);
	std::string graf_modul = program->zamien_na_string_dla_modulu();
	std::string graf_modul_pliki = program->zamien_na_string_dla_plikow_z_modulem_do_grafu();

	std::string do_txt_funkcje = program->przygotuj_txt_dla_funkcji_do_visual_paradigma();
	std::string do_txt_pliki = program->przygotuj_txt_dla_plikow_do_visual_paradigma();
	program->przygotuj_txt_dla_plikow_i_funkcji_do_visual_paradigma(do_txt_pliki, do_txt_funkcje);
	
	program->rysuj_graf(graf_pliki_funkcje, "graf_pliki_funkcje");
	program->rysuj_graf(graf_pliki, "graf_plikow");
	program->rysuj_graf(graf_funkcje, "graf_funkcji");
	program->rysuj_graf(graf_modul, "graf_modulu");

	menu();

	delete program;
	
	return 0;
}
