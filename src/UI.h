#pragma once
#include <SDL3/SDL.h>

#include <vector>
#include <memory>

#include "Rectangle.h"

class UI {
public:
	
	void render(SDL_Surface* surface) const {
		a.render(surface);
		b.render(surface);
		c.render(surface);
	}

	void handleEvent(SDL_Event& e) {
		a.handleEvent(e);
		b.handleEvent(e);
		c.handleEvent(e);
	}

private:
	Rectangle a{ SDL_Rect{50, 50, 50, 50} };
	Rectangle b{ SDL_Rect{150, 50, 50, 50} };
	Rectangle c{ SDL_Rect{250, 50, 50, 50} };
};