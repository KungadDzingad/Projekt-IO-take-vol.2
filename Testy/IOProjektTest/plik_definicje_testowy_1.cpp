#include "Nag³ówek.h"


List::Player::Player() {
	next = nullptr;
}
List::List() {
	head = nullptr;
}

void List::add(std::string a,  int b, std::string c, std::string d) {
	Player* nowy = new Player;
	nowy->imie = a;
	nowy->rok = b;
	nowy->klub = c;
	nowy->kraj = d;
	if (head == nullptr) {
		head = nowy;
	}
	else {
		Player* wsk = head;
		while (wsk->next) {
			wsk = wsk->next;
		}
		wsk->next = nowy;
	}	
	nowy->next = nullptr;
}
void List::show_country(std::string a) {
	if (head == nullptr) {
		std::cout << "nie ma graczy" << std::endl;
	}
	else {
		Player* pom = head;
		while (pom) {		
			if (pom->kraj == a) {
				std::cout << pom->imie <<" "<<pom->kraj << " " << pom->rok<<std::endl;
			}
			pom = pom->next;
		}
	}
}

void List::show_clubs_winners() {
	if (head == nullptr) {
		std::cout << "nie ma graczy" << std::endl;
	}
	else {
		struct Klub {
			std::string nazwa;
			int laureaci;
		};
		std::vector<Klub> kluby;
		Klub temp;
		Player* pom = head;
		while (pom) {
			int dlugosc = 0;
			for (int i = 0; i < kluby.size(); i++) {
				if (pom->klub != kluby[i].nazwa)
					dlugosc++;
				else kluby[i].laureaci++;
			}
			if (dlugosc == kluby.size()) {
				temp.nazwa = pom->klub;
				temp.laureaci = 1;
				kluby.push_back(temp);
			}
			pom = pom->next;
		}
		for (int i = 0; i < kluby.size(); i++) {
			std::cout << kluby[i].nazwa << ": " <<kluby[i].laureaci << std::endl;
		}
	}
}
void List::show_year(int a) {
	if (head == nullptr) {
		std::cout << "nie ma graczy" << std::endl;
	}
	else {
		Player* pom = head;
		while (pom) {
			if (pom->rok == a) {
				std::cout << pom->imie << " " << pom->klub << std::endl;
				break;
			}
			pom = pom->next;
		}
	}
}