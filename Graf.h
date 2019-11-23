#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Funkcje_od_stringow.h"


using namespace std;


struct Polaczenie {
	std::string nazwa_polaczonego_elementu;
	int waga;   //zalezne od liczby wywolan funkcji
	Polaczenie(std::string a) {
		nazwa_polaczonego_elementu = a;
		waga = 1;
	}
};

struct Funkcja {
	std::string nazwa_funkcji;
	std::vector<Polaczenie> polaczenia_miedzy_funkcjami;
	Funkcja(std::string a) {
		nazwa_funkcji = a;
		polaczenia_miedzy_funkcjami = {};
	}
};

struct Plik {
	std::string nazwa_pliku;
	int ilosc_linijek_kodu;
	std::vector<Polaczenie> polaczenia_miedzy_plikami;
	std::vector<Funkcja> funkcje;
	Plik(std::string a) {
		nazwa_pliku = a;
		polaczenia_miedzy_plikami = {};
		funkcje = {};
		ilosc_linijek_kodu = 0;
	}
};

//struktura z namespaceami - nowa 16.11.2019
struct Modul {
	std::string nazwa_przestrzeni;
	std::vector<Funkcja> funkcje_modulu;
	std::vector<std::string> elementy_modulu;
	std::vector<Polaczenie> polaczenia_miedzy_namespaceami;
	Modul(std::string a) {
		nazwa_przestrzeni = a;
		funkcje_modulu = {};
		elementy_modulu = {};
		polaczenia_miedzy_namespaceami = {};
	}
};

class Graf {
public:
	std::vector<Funkcja> wszystkie_funkcje_we_wszystkich_plikach;
	std::vector<Plik> pliki;
	std::vector<Modul> przestrzenie_nazw;

	//znajduje pliki w folderze : dodaje znalezione do vectora Graf::pliki definiujac nazwe w konstruktorze
	void znajdz_pliki();     //                                                            || -> Patryk

	//dodaje liczbe linijek do pola Plik::ilosc_linijek_kodu dla kazdego pliku z vectora
	void policz_linijki_kodu_dla_pliku(); //liczy linijki kodu dla pliku                   || -> Ewelina

	//znajduje includy etc : dla kazdego pliku dodajego do jego pola vector Plik::polaczenia_miedzy_plikami elemty polaczen do vectora (dodaje nazwy)
	void znajdz_polaczenia_pomiedzy_plikami();  //znajduje polaczenia pomiedzy plikami     || -> Patryk

	//dodaje definicje do pola Graf::wszystkie_funkcje... oraz dla kazdego pliku do pola Plik::funkcje jego pliki
	void znajdz_definicje_funkcji();			//										   || -> Wojtek

	//dla kazdego Pliku dodaje do polaczeniamiedzyplikami[].waga ich wage szuka funkcji dla pliku ktore sa w Graf::wsystkie.. a nie ma w Plik::funkcje
	void znajdz_funkcje_i_wagi_pomiedzy_plikami();//                                       || -> Bartek

	//dla kazdej Funkcji dodaje polaczenia do vecota Funkcja::polaczenia_miedzy_funkcjami (nazwy polaczonych funkcji)
	void znajdz_polaczenia_miedzy_funkcjami();                 //                          || -> Matuesz Witkowski i Wojtek
	
	//znajduje przestrzenie 
	void znajdz_przestrzenie_nazw();									//                 || -> Wojtek

	//znajduje pola dla  przestrzeni zdefiniowanych przez uzytkownika i napisuje (narazie czesc, wiec jak potzreba to dopisac)
	//dla domyslnych jak std
	void znajdz_elementy_przestrzeni_nazw();							//                 || -> Wojtek

	std::string zamien_na_string_dla_plikow_do_grafu();  //                                || -> Matuesz Wicherski // Mateusz Witkowski
	std::string zamien_na_string_dla_funkcji_do_grafu(); //do skopiowania i prxerobienia   || -> Matuesz Wicherski // Mateusz Witkowski
	void rysuj_graf(std::string do_rysowania_grafu, std::string nazwa_pliku);//GOTOWE      || -> Matuesz Wich i Wojtek // Mateusz Witkowski
};