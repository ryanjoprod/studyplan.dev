#pragma once

#include <SDL3/SDL.h>

#include <iostream>

#include "Rectangle.h"

class UI;

class Button : public Rectangle {
public:
	Button(
		UI& UIManager,
		const SDL_Rect& rect
	)
	: Rectangle{ rect },
	  UIManager{ UIManager }
	{
		setColor({ 255, 165, 0, 255 });
	}

	void onLeftClick() override;

private:
	UI& UIManager;
};