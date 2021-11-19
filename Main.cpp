#include <chrono>
#include <string>

#include "gui.h"
#include "core.h"

gui::Window window = gui::Window(800, 600, "Hello World");

void init() 
{
	window.create();
	core::init();
}

void update() 
{
	window.update();
}

void render()
{	
	window.render();
}

void run() 
{
	init();

	float seconds = 0;
	while (window.exists())
	{
		auto start = std::chrono::high_resolution_clock::now();
		
		update();
		render();

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> deltaTime = end - start;

		int fps = (int)(1 / deltaTime.count());
		seconds += deltaTime.count();

		if (seconds >= 0.1f)
		{
			std::string title =  "Ignite | FPS: " + std::to_string(fps);
			window.setTitle(title.c_str());
			seconds = 0;
		}
	}
}

int main() 
{
	run();

	return 0;
}