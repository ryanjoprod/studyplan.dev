#pragma once
#include <SDL3/SDL.h>

#include "Rectangle.h"

class GreenRectangle : public Rectangle {
public:
	GreenRectangle(const SDL_Rect& rect)
	: Rectangle{ rect } {
		setColor({ 0, 255, 0, 255 });
	}
};