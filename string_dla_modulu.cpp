#include"Graf.h"

std::string Graf::zamien_na_string_dla_modulu()
{
	std::string strzalka = "->";
	std::string poczatek = "digraph G {\nbgcolor=\"#66cc99:#009966\"\n";
	std::string node = "node [shape=diamond fillcolor=\"#de00ba:#fdb0aa\" style=\"filled\" gradientangle=120]\n";
	std::string styl_strzalki = "[color=\"#FDFF56\", penwidth = 2]";
	std::string temp = "";
	std::string tekst;
	//int j = 0;

	if (przestrzenie_nazw.size() <= 1)
	{
		temp += przestrzenie_nazw[0].nazwa_przestrzeni + ";\n";
	}
	else {
		for (unsigned int i = 0; i < przestrzenie_nazw.size(); i++)
		{
			for (unsigned int j = 0; j < przestrzenie_nazw[i].polaczenia_miedzy_namespaceami.size(); j++)
			{
				temp += przestrzenie_nazw[i].nazwa_przestrzeni + strzalka + przestrzenie_nazw[i].polaczenia_miedzy_namespaceami[j].nazwa_polaczonego_elementu + "\"" + styl_strzalki + ";\n";
			}
		}
	}
	tekst = poczatek + node + temp + "}";
	std::cout << tekst;
	return (tekst);
}