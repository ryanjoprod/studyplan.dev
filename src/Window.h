#pragma once
#include <SDL3/SDL.h>

class Window {
public:
	Window() {
		window = SDL_CreateWindow(
			"Hello window",
			800, 300, 0
		);
	}

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	~Window() {
		if (window && SDL_WasInit(SDL_INIT_VIDEO)) {
			SDL_DestroyWindow(window);
		}
	}

private:
	SDL_Window* window{ nullptr };
};