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

	SDL_Surface* getSurface() const {
		return SDL_GetWindowSurface(window);
	}

	void render() {
		const auto* fmt = SDL_GetPixelFormatDetails(
			getSurface()->format
		);

		SDL_FillSurfaceRect(
			getSurface(),
			nullptr,
			SDL_MapRGB(fmt, nullptr, 50, 50, 50)
		);
	}

	void update() {
		SDL_UpdateWindowSurface(window);
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