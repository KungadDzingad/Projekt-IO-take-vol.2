#include <iostream>
#include <math.h>


int funkcja(int a, int b, int c, int x) {
	int wynik = a * pow(x, 2) + b * x + c;
	return wynik;
}
void swap(int& tab1, int& tab2) {
	int temp = tab1;
	tab1 = tab2;
	tab2 = temp;
}

int* tablica_funkcja2(int* tab1, int n) {
	int a = 1, b = 0, c = 0;
	int* tab2 = new int[n];
	for (int i = 0; i < n; i++) {
		tab2[i] = funkcja(a, b, c, tab1[i]);
	}
	return tab2;
}

int* tablica_funkcja(int* tab1, int n) {
	int a = 1, b = 0, c = 0;
	int* tab2 = new int[n];
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			tab2[i] = funkcja(a, b, c, tab1[i]);
			
		}
		else if (i == 0) {
			tab2[i] = funkcja(a, b, c, tab1[i]);
		}
	}
	return tab2;
}


int main() {
	int tablica[3] = { -1,0,1 };
	int* tablica_wynikow = tablica_funkcja(tablica, 3);
	for (int i = 0; i <3; i++) {
		std::cout << tablica_wynikow[i] << std::endl;
	}
	delete[] tablica_wynikow;
	return 0;
}