#pragma once
#include <SDL3/SDL.h>

class Rectangle {
public:
	Rectangle(const SDL_Rect& rect)
		: rect{ rect }
	{
	}

	virtual ~Rectangle() = default;

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

	virtual void onMouseEnter() {}
	virtual void onMouseExit() {}
	virtual void onLeftClick() {}

	void handleEvent(SDL_Event& e) {
		if (e.type == SDL_EVENT_MOUSE_MOTION) {
			bool wasPointerHovering{ isPointerHovering };

			isPointerHovering = isWithinRect(
				(int)e.motion.x, (int)e.motion.y
			);

			if (!wasPointerHovering && isPointerHovering) {
				onMouseEnter();
			}
			else if (
				wasPointerHovering && !isPointerHovering
			){
				onMouseExit();
			}
		}
		else if (e.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
			isPointerHovering = false;
		}
		else if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			if (isPointerHovering &&
				e.button.button == SDL_BUTTON_LEFT
			) {
				onLeftClick();
			}
		}
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

protected:
	bool isPointerHovering{ false };

private:
	bool isWithinRect(int x, int y) {
		if (x < rect.x) return false;
		if (x > rect.x + rect.w) return false;
		if (y < rect.y) return false;
		if (y > rect.y + rect.h) return false;

		return true;
	}
};