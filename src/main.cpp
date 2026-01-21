#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>
#include <string>

#include "Window.h"
#include "Image.h"

int main(int, char**) {
	SDL_Init(SDL_INIT_VIDEO);

	Window window;

	/*
	std::string BASE_PATH{ SDL_GetBasePath() };
	std::string IMAGE_PATH{ BASE_PATH + "..\\assets\\images\\example.bmp" };
	Image example(IMAGE_PATH.c_str());
	*/
	Image example("assets/images/example.bmp");

	SDL_Event e;
	bool isRunning{ true };

	while (isRunning) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}

		window.render();
		example.render(window.getSurface());
		window.update();
	}


	SDL_Quit();

	return 0;
}