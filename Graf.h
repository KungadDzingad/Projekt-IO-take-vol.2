#pragma once
#include <iostream>
#include <vector>

using namespace std;
//NIGDY NIE UZYWAMY DWA RAZY FUNKCJI W JEDNEJ LINII BO SIE SPIERDOLI
class Graf {
	std::vector<Funkcja> wszystkie_funkcje_we_wszystkich_plikach;
	std::vector<Plik> pliki;

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
	void znajdz_polaczenia_miedzy_funkcjami();                 //                          || -> Matuesz Witkowski
	//dodaje do vecotra z Polaczeniami w Funkcji polaczenia_miedzy_funkcjami.waga
	void znajdz_wagi_pomiedzy_funkcjami(); //                                              || -> Matuesz Witkowski

	std::string zamien_na_string_dla_plikow_do_grafu();  //                                || -> Matuesz Wicherski
	std::string zamien_na_string_dla_funkcji_do_grafu(); //do skopiowania i prxerobienia   || -> Matuesz Wicherski
	void rysuj_graf(std::string do_rysowania_grafu, std::string nazwa_grafu);//GOTOWE      || -> Matuesz Wich i Wojtek
};

struct Plik {
	std::string nazwa_pliku;
	int ilosc_linijek_kodu;
	std::vector<Polaczenie> polaczenia_miedzy_plikami;
	std::vector<Funkcja> funkcje;
	Plik(std::string);
};

struct Polaczenie {
	std::string nazwa_polaczonego_elementu;
	int waga;   //zalezne od liczby wywolan funkcji
	Polaczenie(std::string);
};

struct Funkcja {
	std::string nazwa_funkcji;
	std::vector<Polaczenie> polaczenia_miedzy_funkcjami;
	Funkcja(std::string);
};
