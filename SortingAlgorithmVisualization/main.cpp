#include <iostream>
#include "Application.h"
#include <exception>

int main()
{
	try {
		Application app;
		app.run();
	}
	catch (std::exception & e) {
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}