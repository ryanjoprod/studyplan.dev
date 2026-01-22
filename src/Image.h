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
		else {
			sourceRect = { 0, 0, imageSurface->w, imageSurface->h };  // full size
			// sourceRect = { 0, 0, 300, 150 };  // cropping #1
			// sourceRect = { 100, 100, 300, 150 };  //  cropping #2
		}
	}

	void render(SDL_Surface* surface) {
		if (!imageSurface) return;

		SDL_Surface* in = SDL_ConvertSurface(imageSurface, surface->format);
		SDL_BlitSurfaceScaled(in, &sourceRect, surface, &destRect, SDL_SCALEMODE_LINEAR);
	}

	~Image() {
		if (imageSurface) {
			SDL_DestroySurface(imageSurface);
		}
	}

	Image(const Image&) = delete;
	Image& operator=(const Image&) = delete;

private:
	SDL_Surface* imageSurface{ nullptr };
	SDL_Rect sourceRect{};
	SDL_Rect destRect{ 0, 0, 600, 300 };  // full window
	// SDL_Rect destRect{ 0, 0, 300, 150 };  // scaled window (cropping)
};