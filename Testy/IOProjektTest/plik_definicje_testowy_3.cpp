#include <iostream>
#include <ctime>
#include<cstdlib>
#include <math.h>

int *pom;
void scal(int tab[], int lewy, int srodek, int prawy)
{
	int i = lewy, j = srodek + 1;

	for (int i = lewy; i <= prawy; i++)
		pom[i] = tab[i];

	
	for (int k = lewy; k <= prawy; k++)
		if (i <= srodek)
			if (j <= prawy)
				if (pom[j] < pom[i])
					tab[k] = pom[j++];
				else
					tab[k] = pom[i++];
			else
				tab[k] = pom[i++];
		else
			tab[k] = pom[j++];
}

void sortowanie_przez_scalanie(int tab[], int lewy, int prawy)
{
	if (prawy <= lewy) return;
	int srodek = (prawy + lewy) / 2;
	sortowanie_przez_scalanie(tab, lewy, srodek);
	sortowanie_przez_scalanie(tab, srodek + 1, prawy);

	scal(tab, lewy, srodek, prawy);
}

int funkcja(int a, int b, int c, int x);
int *tablica_funkcja(int *tab1, int n);

int main() {
	int n;
	std::cin >> n;
	srand(time(NULL));
	int* tablica = new int[n];
	pom = new int[n];
	for (int i = 0; i < n; i++) {
		tablica[i] = rand() % 1000 + 1;
	}
	for (int i = 0; i < n; i++) {
		std::cout << tablica[i] << ", ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < n; i++) {
		std::cout << tablica[i] << ", ";
	}
	std::cout << std::endl;

	delete[] tablica;
	delete[] pom;
	/*int tablica[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* tablica_wynikow = tablica_funkcja(tablica, 10);
	
	for (int i = 0; i < 10; i++) {
		std::cout << tablica_wynikow[i] << std::endl;
	}
	delete[] tablica_wynikow;
	return 0;*/
}

int funkcja(int a, int b, int c, int x) {
	int wynik = a * pow(x, 2) + b * x + c;
	return wynik;
}

int *tablica_funkcja(int* tab1, int n) {
	int a = 2, b = 3, c = 4;
	int* tab2 = new int[n];
	for (int i = 0; i < n; i++) {
		tab2[i] = funkcja(2, 3, 4, tab1[i]);
	}
	return tab2;
}