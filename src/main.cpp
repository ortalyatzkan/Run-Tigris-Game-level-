#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Menu.h"

int main()
{
	try
	{
		Menu m;
		m.openMenu();
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Exception opening/reading/closing file\n";
	}

	


    
}
