#pragma once
#include <SDL3/SDL.h>

#include <vector>
#include <memory>

#include "SettingsMenu.h"
#include "Button.h"

class UI {
public:
	
	void render(SDL_Surface* surface) const {
		settingsButton.render(surface);
		settings.render(surface);
	}

	void handleEvent(SDL_Event& e) {
		settingsButton.handleEvent(e);
		settings.handleEvent(e);
	}

private:
	Button settingsButton{ {50, 50, 50, 50} };
	SettingsMenu settings;
};