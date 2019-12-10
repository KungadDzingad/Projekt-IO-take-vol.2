#include "Graf.h"

void Graf::wykonaj() {
	znajdz_pliki();
	policz_linijki_kodu_dla_pliku();
	znajdz_polaczenia_pomiedzy_plikami();

	znajdz_definicje_funkcji();
	znajdz_funkcje_i_wagi_pomiedzy_plikami();
	znajdz_polaczenia_miedzy_funkcjami();

	znajdz_przestrzenie_nazw();
	znajdz_elementy_przestrzeni_nazw();

	std::string graf_pliki = zamien_na_string_dla_plikow_do_grafu();
	std::string graf_funkcje = zamien_na_string_dla_funkcji_do_grafu();
	std::string graf_pliki_funkcje = string_dla_plikow_i_funkcji(graf_pliki, graf_funkcje);
	std::string graf_modul = zamien_na_string_dla_modulu();
	std::string graf_modul_pliki = zamien_na_string_dla_plikow_z_modulem_do_grafu();

	std::string do_txt_funkcje = przygotuj_txt_dla_funkcji_do_visual_paradigma();
	std::string do_txt_pliki = przygotuj_txt_dla_plikow_do_visual_paradigma();
	przygotuj_txt_dla_plikow_i_funkcji_do_visual_paradigma(do_txt_pliki, do_txt_funkcje);

	rysuj_graf(graf_pliki_funkcje, "graf_pliki_funkcje");
	rysuj_graf(graf_pliki, "graf_plikow");
	rysuj_graf(graf_funkcje, "graf_funkcji");
	rysuj_graf(graf_modul, "graf_modulu");
}