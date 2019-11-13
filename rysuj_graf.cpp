﻿
#pragma once
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Graf.h"

void Graf::rysuj_graf(std::string do_rysowania_graphu, std::string nazwa_pliku) {
	//tlumaczenie 
	std::ofstream plik_wyjsciowy;

	plik_wyjsciowy.open(nazwa_pliku.c_str(), std::ios::out);		//zapis  do pliku
	plik_wyjsciowy << do_rysowania_graphu;
	plik_wyjsciowy.close();							//zamykanie pliku

	system(("C:\\Users\\wojte\\source\\repos\\IOnowy\\IOnowy\\release\\bin\\dot.exe " + nazwa_pliku + "  -Tpng -o graf.png").c_str());    //musisz sobie zamienic na swoja sciezke 
			//chyba musi byc na tej samej partycji co projekt
}

