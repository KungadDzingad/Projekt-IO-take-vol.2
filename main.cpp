#include "Graf.h"
#include "menu.h"
#include <iostream>
#include <sstream>


int main() {
	Graf* program = new Graf;
	program->wykonaj();

	menu();

	delete program;
	
	return 0;
}
