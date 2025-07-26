//
// Created by akash on 7/25/25.
//

#include "MainMenu.h"
#include <print>

#include "raylib.h"
#include "../../utils/config/FontManager.hpp"

void MainMenu::create() {
    background = LoadTexture("assets/background/main_menu.png");
    playButton = new MainMenuButton(60, GetScreenHeight() - 150, 130, 80, "Play", [] {});
    optionsButton = new MainMenuButton(230, GetScreenHeight() - 150, 130, 80, "Options", [] {});
    exitButton = new MainMenuButton(400, GetScreenHeight() - 150, 130, 80, "Exit", [] {
        CloseWindow();
    });
}

void MainMenu::update() {
    playButton->update();
    optionsButton->update();
    exitButton->update();
}

void MainMenu::render() {
    ClearBackground(RAYWHITE);

    const Rectangle src = { 0.0f, 0.0f, static_cast<float>(background.width), static_cast<float>(background.height) };
    const Rectangle dest = { 0.0f, 0.0f, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
    constexpr Vector2 origin = { 0.0f, 0.0f };

    DrawTexturePro(background, src, dest, origin, 0.0f, WHITE);

    playButton->render();
    optionsButton->render();
    exitButton->render();
}


void MainMenu::destroy() {
    UnloadTexture(background);
}