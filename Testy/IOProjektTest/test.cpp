#include "pch.h"
#include "C:\Users\wojte\source\repos\IOnowy\IOnowy\Plik.cpp"
#include "C:\Users\wojte\source\repos\IOnowy\IOnowy\Funkcje_do_Stringow.cpp"
#include "C:\Users\wojte\source\repos\IOnowy\IOnowy\Funkcja.cpp"
#include "C:\Users\wojte\source\repos\IOnowy\IOnowy\znajdz_definicje_funkcji.cpp"
#include "C:\Users\wojte\source\repos\IOnowy\IOnowy\Modul.cpp"


namespace PlikTest {
	TEST_P(TestZnajdzDefinicje, ZnajdzDefFunkcji) {
		auto as = GetParam();
		plik->znajdz_funkcje_w_pliku();
		EXPECT_EQ(as.test_ilosc_funkcji, plik->funkcje.size());
	}
	INSTANTIATE_TEST_CASE_P(Default, TestZnajdzDefinicje,
			testing::Values(
			plik_parametry{ "plik_definicje_testowy_1.cpp" ,4 },
			plik_parametry{ "plik_definicje_testowy_2.cpp", 5 },
			plik_parametry{ "plik_definicje_testowy_3.cpp", 5 }
	));

	TEST(Modul_W_Pliku, CASE_1) {
		Plik plik("namespace_test.cpp");
		plik.znajdz_moduly();
		EXPECT_EQ(plik.namespacey.size(), 2);
		EXPECT_EQ(plik.namespacey[0].nazwa_przestrzeni, "Test");
		EXPECT_EQ(plik.namespacey[1].nazwa_przestrzeni, "TestDwa");
		EXPECT_EQ(plik.namespacey[0].elementy_modulu.size(), 0);
	}
}

namespace Polaczenia_Miedy_Funkcjami {
	TEST(Polaczenia_Miedy_Funkcjami,GdyIstnieje1) {
		Funkcja funkcja("sortowanie_przez_scalanie");
		std::fstream otwarty_plik;
		otwarty_plik.open("plik_definicje_testowy_3.cpp");
		Funkcja fun2("scal");
		funkcja.znajdz_polaczone_funkcje(fun2,otwarty_plik);
		EXPECT_EQ(funkcja.polaczenia_miedzy_funkcjami[0].nazwa_polaczonego_elementu, "scal");
		EXPECT_EQ(funkcja.polaczenia_miedzy_funkcjami[0].waga, 1);
		otwarty_plik.close();
	}
	TEST(Polaczenia_Miedy_Funkcjami, Szuka_Samej_Siebie) {
		Funkcja funkcja("sortowanie_przez_scalanie");
		std::fstream otwarty_plik;
		otwarty_plik.open("plik_definicje_testowy_3.cpp");
		Funkcja fun2("sortowanie_przez_scalanie");
		funkcja.znajdz_polaczone_funkcje(fun2, otwarty_plik);
		EXPECT_EQ(funkcja.polaczenia_miedzy_funkcjami[0].nazwa_polaczonego_elementu, "sortowanie_przez_scalanie");
		EXPECT_EQ(funkcja.polaczenia_miedzy_funkcjami[0].waga, 2);
		otwarty_plik.close();
	}
	TEST(Polaczenia_Miedy_Funkcjami, Gdy_Nie_Ma) {
		Funkcja funkcja("scal");
		std::fstream otwarty_plik;
		otwarty_plik.open("plik_definicje_testowy_3.cpp");
		Funkcja fun2("sortowanie_przez_scalanie");
		funkcja.znajdz_polaczone_funkcje(fun2, otwarty_plik);
		EXPECT_EQ(funkcja.polaczenia_miedzy_funkcjami.size(), 0);
		otwarty_plik.close();
	}	
}

namespace Przestrzenie {
	TEST(Elementy_Modulu, CASE_1) {
		Modul modul("Test");
		std::fstream plik;
		plik.open("namespace_test.cpp");
		modul.znajdz_elementy_modulu(plik);
		for (auto i : modul.elementy_modulu) {
			std::cout << i << std::endl;
		}
		EXPECT_EQ(modul.elementy_modulu[0], "Test::aa");
		EXPECT_EQ(modul.funkcje_modulu.size(), 1);
		EXPECT_EQ(modul.elementy_modulu.size(), 2);
		plik.close();
	}
	TEST(Elementy_Modulu, CASE_2) {
		Modul modul("TestDwa");
		std::fstream plik;
		plik.open("namespace_test.cpp");
		modul.znajdz_elementy_modulu(plik);
		for (auto i : modul.elementy_modulu) {
			std::cout << i << std::endl;
		}
		EXPECT_EQ(modul.elementy_modulu[0], "TestDwa::aa");
		EXPECT_EQ(modul.funkcje_modulu.size(), 1);
		EXPECT_EQ(modul.elementy_modulu.size(), 2);
		plik.close();
	}
}

//namespace ZnajdzFunkcjeGraf {
//	TEST(Znajdz_Funkcje_w_Grafie, CASE_1) {
//		Graf program;
//		Plik plik1("plik_definicje_testowy_1");
//		Plik plik2("plik_definicje_testowy_2");
//		Plik plik3("plik_definicje_testowy_3");
//		
//		program.pliki = { plik1, plik2, plik3 };
//		program.znajdz_definicje_funkcji();
//		EXPECT_EQ(program.wszystkie_funkcje_we_wszystkich_plikach.size(), 14);
//	}
//}



/*TEST_F(PlikTest, TestDodajFunkcjeGdyNiePowtarza) {
	plik->funkcje = {};
	plik->dodaj_niepowtarzajaca_sie_funkcje("FOO");
	EXPECT_EQ(plik->funkcje.size(), 1);
	EXPECT_EQ(plik->funkcje[0].nazwa_funkcji, "FOO");
}
TEST_F(PlikTest, TestDodajFunkcjeGdyNiePowtarza2) {
	Funkcja fun1("Funkcja");
	Funkcja fun2("FUN");
	plik->funkcje = { fun1, fun2 };
	plik->dodaj_niepowtarzajaca_sie_funkcje("FOO");
	EXPECT_EQ(plik->funkcje.size(), 3);
	EXPECT_EQ(plik->funkcje[2].nazwa_funkcji, "FOO");
}
TEST_F(PlikTest, TestDodajFunkcjeGdyPowtarza) {
	Funkcja fun1("Funkcja");
	Funkcja fun2("FOO");
	plik->funkcje = { fun1, fun2 };
	plik->dodaj_niepowtarzajaca_sie_funkcje("FOO");
	EXPECT_EQ(plik->funkcje.size(), 2);
}*/