//
// Created by akash on 7/26/25.
//

#include "MainMenuButton.hpp"

#include <raylib.h>

#include "../../utils/config/FontManager.hpp"

#define BUTTON_BG_COLOR (Color){ 255, 239, 178, 255 }     // parchment-like warm yellow
#define BUTTON_BORDER_COLOR_TOP (Color){ 181, 101, 29, 255 }   // top & sides (lighter wood)
#define BUTTON_BORDER_COLOR_BOTTOM (Color){ 140, 75, 18, 255 } // bottom (shadow wood)
#define BUTTON_TEXT_COLOR (Color){ 92, 51, 23, 255 }

MainMenuButton::MainMenuButton(const int x, const int y, const int width, const int height, std::string text, const std::function<void()> &callback) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->callback = callback;
    this->text = text;
}

void MainMenuButton::render() const {
    constexpr int border = 4;
    int yOffset = isPressed ? 2 : 0;

    // Button base
    Color bgColor = isHovered
        ? (isPressed
            ? Color{ 230, 210, 140, 255 }
            : Color{ 255, 250, 190, 255 })
        : BUTTON_BG_COLOR;

    // Draw top, left, right borders (lighter)
    DrawRectangle(x - border, y - border + yOffset, width + 2 * border, border, BUTTON_BORDER_COLOR_TOP);                  // top
    DrawRectangle(x - border, y + yOffset, border, height, BUTTON_BORDER_COLOR_TOP);                                      // left
    DrawRectangle(x + width, y + yOffset, border, height, BUTTON_BORDER_COLOR_TOP);                                       // right

    // Draw bottom border (darker for shadow effect)
    DrawRectangle(x - border, y + height + yOffset, width + 2 * border, border, BUTTON_BORDER_COLOR_BOTTOM);              // bottom

    // Main background
    DrawRectangle(x, y + yOffset, width, height, bgColor);

    // Text
    const Font font = FontManager::getFont();
    constexpr float fontSize = 32;
    constexpr float spacing = 2;

    Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, spacing);
    Vector2 textPos = {
        x + (width - textSize.x) / 2,
        y + (height - textSize.y) / 2 + yOffset
    };

    DrawTextEx(font, text.c_str(), textPos, fontSize, spacing, BUTTON_TEXT_COLOR);
}

void MainMenuButton::update() {
    Vector2 mouse = GetMousePosition();
    Rectangle bounds = { (float)x, (float)y, (float)width, (float)height };

    isHovered = CheckCollisionPointRec(mouse, bounds);

    // Check for click
    if (isHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isPressed = true;
    } else if (isPressed && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        if (isHovered && callback) {
            callback(); // Only call if mouse is still over
        }
        isPressed = false;
    }
}
