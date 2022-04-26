#include "Application.h"
#include "Config/Config.h"

#include <ctime>

int main()
{
	std::srand(std::time(nullptr));
	g_config = { 1280, 720 };

	Application app;

	app.runLoop();

	return EXIT_SUCCESS;
}