#pragma once
#include <SDL3/SDL.h>

#include <vector>
#include <memory>

#include "Rectangle.h"
#include "GreenRectangle.h"

class UI {
public:
	UI() {
		int rowCount{ 5 }, colCount{ 12 };
		rectangles.reserve(rowCount * colCount);
		for (int row{ 0 }; row < rowCount; ++row) {
			for (int col{ 0 }; col < colCount; ++col) {
				bool useGreen{ (row + col) % 2 == 0 };
				rectangles.emplace_back(useGreen
				? std::make_unique<GreenRectangle>(SDL_Rect{
					60 * col, 60 * row, 50, 50 })
				: std::make_unique<Rectangle>(SDL_Rect{
					60 * col, 60 * row, 50, 50})
				);
			}
		}
	}
	void render(SDL_Surface* surface) const {
		//a.render(surface);
		//b.render(surface);
		//c.render(surface);
		for (auto& rect : rectangles) {
			rect->render(surface);
		}
	}

	void handleEvent(SDL_Event& e) {
		//a.handleEvent(e);
		//b.handleEvent(e);
		//c.handleEvent(e);
		for (auto& rect : rectangles) {
			rect->handleEvent(e);
		}
	}

private:
	//Rectangle a{ SDL_Rect{50, 50, 50, 50} };
	//Rectangle b{ SDL_Rect{150, 50, 50, 50} };
	//Rectangle c{ SDL_Rect{250, 50, 50, 50} };
	std::vector<std::unique_ptr<Rectangle>> rectangles;
};