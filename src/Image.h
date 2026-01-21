#pragma once

#include <SDL3/SDL.h>

#include <string>
#include <iostream>

class Image {
public:
	Image(const std::string& file)
	: imageSurface{ SDL_LoadBMP(file.c_str()) } {
		if (!imageSurface) {
			std::cout << "Failed to load image "
				<< file << ":\n " << SDL_GetError() << '\n';
		}
	}

	void render(SDL_Surface* surface) {}

	~Image() {
		if (imageSurface) {
			SDL_DestroySurface(imageSurface);
		}
	}

	Image(const Image&) = delete;
	Image& operator=(const Image&) = delete;

private:
	SDL_Surface* imageSurface{ nullptr };
};