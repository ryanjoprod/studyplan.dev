#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>

#include "Window.h"

void handleEvent(SDL_Event& e) {
	if (e.type == SDL_EVENT_MOUSE_MOTION) {
		std::cout << "Mouse motion detected - "
			<< "x: " << e.motion.x
			<< " y: " << e.motion.y << '\n';
	}
	else if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
		std::cout << "Mouse clicked.\n";
	}
	else if (e.type == SDL_EVENT_KEY_DOWN) {
		std::cout << "Keyboard button pressed.\n";
	}
}

int main(int, char**) {
	SDL_Init(SDL_INIT_VIDEO);
	Window window;

	SDL_Event e;
	bool isRunning{ true };

	while (isRunning) {
		while (SDL_PollEvent(&e)) {
			handleEvent(e);

			if (e.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}

		window.render();
		window.update();
	}


	SDL_Quit();

	return 0;
}