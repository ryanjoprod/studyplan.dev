#pragma once

#include <SDL3/SDL.h>

#include <iostream>

#include "Rectangle.h"
#include "UserEvents.h"

class Button : public Rectangle {
public:
	Button(const SDL_Rect& rect)
	: Rectangle{ rect }
	{
		setColor({ 255, 165, 0, 255 });
	}

	void handleEvent(SDL_Event& e) {
		Rectangle::handleEvent(e);

		if (e.type == UserEvents::CLOSE_SETTINGS) {
			isSettingsOpen = false;
		}
		else if (e.type == UserEvents::OPEN_SETTINGS) {
			isSettingsOpen = true;
		}
	}

	void onLeftClick() override {
		SDL_Event e{ .type = isSettingsOpen
			? UserEvents::CLOSE_SETTINGS
			: UserEvents::OPEN_SETTINGS
		};

		if (e.type == UserEvents::OPEN_SETTINGS) {
			e.user.data1 = this;
		}

		SDL_PushEvent(&e);
	}

	UserEvents::SettingsConfig getConfig() {
		return config;
	}

	std::string getLocation() {
		return "The main menu.\n";
	}

private:
	bool isSettingsOpen{ false };

	UserEvents::SettingsConfig config{
		UserEvents::SettingsPage::GAMEPLAY,
		50, 100
	};
};