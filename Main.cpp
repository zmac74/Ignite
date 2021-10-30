#include "input.h"
#include "gui.h"

int main() 
{
	gui::Window window(800, 600, "Hello World");
	window.create();

	while (window.exists()) 
	{
		window.update();
	}

	return 0;
}