#include "Application.h"

#include <ctime>

int main()
{
	std::srand(std::time(nullptr));

	Application app;

	app.runLoop();

	return EXIT_SUCCESS;
}