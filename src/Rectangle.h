#pragma once
#include <SDL3/SDL.h>

#include <iostream>

class Rectangle {
public:
	Rectangle(const SDL_Rect& rect)
		: rect{ rect }
	{
	}

	void handleEvent(SDL_Event& e) {
		if (e.type == SDL_EVENT_MOUSE_MOTION) {
			isPointerHovering = isWithinRect(
				(int)e.motion.x, (int)e.motion.y
			);
		}
		else if (e.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
			isPointerHovering = false;
		}
		else if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			if (isPointerHovering &&
				e.button.button == SDL_BUTTON_LEFT
			) {
				std::cout << "A left click happened on me.\n";
			}
		}
	}
	
	void render(SDL_Surface* surface) const {
		auto [r, g, b, a] {
			isPointerHovering ? hoverColor : color
		};

		const auto* fmt = SDL_GetPixelFormatDetails(
			surface->format
		);

		SDL_FillSurfaceRect(
			surface,
			&rect,
			SDL_MapRGB(
				fmt, nullptr,
				r, g, b
			)
		);
	}

	void setColor(const SDL_Color& newColor) {
		color = newColor;
	}

	void setHoverColor(const SDL_Color& newColor) {
		hoverColor = newColor;
	}

	SDL_Color getColor() const {
		return color;
	}

	SDL_Color getHoverColor() const {
		return hoverColor;
	}

private:
	SDL_Rect rect;
	SDL_Color color{ 255, 0, 0, 255 };
	SDL_Color hoverColor{ 0, 0, 255, 255 };

	bool isPointerHovering{ false };
	bool isWithinRect(int x, int y) {
		if (x < rect.x) return false;
		if (x > rect.x + rect.w) return false;
		if (y < rect.y) return false;
		if (y > rect.y + rect.h) return false;

		return true;
	}
};