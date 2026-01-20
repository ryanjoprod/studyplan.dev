#include "Button.h"
#include "UI.h"

void Button::onLeftClick() {
	UIManager.setRectangleColor(
		{ 0, 255, 0, 255 }
	);
}