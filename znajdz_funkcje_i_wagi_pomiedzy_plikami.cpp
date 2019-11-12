#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Graf.h"

using namespace std;


void znajdz_funkcje_i_wagi_pomiedzy_plikami() {

	//w tej pętli iterujemy po wszystkich plikach
	for (int i = 0; i < pliki.size(); i++) {

		//ta petla iteruje po wszystkich "poleczenia_miedzy_plikami" dla danego pliku
		for (int j = 0; j < pliki[i].polaczenia_miedzy_plikami.size(); j++) {

			//ta petla iteruje po wszystkich "wszystkie_funkcje_we_wszystkich_plikach" dla danego połączenia pliku
			for (int k = 0; k < wszystkie_funkcje_we_wszystkich_plikach.size(); k++) {
				if (pliki[i].polaczenia_miedzy_plikami[j].nazwa_polaczonego_elementu == wszystkie_funkcje_we_wszystkich_plikach[k].nazwa_funkcji)
					pliki[i].polaczenia_miedzy_plikami[j].waga++;
			}
		}
	}
}
