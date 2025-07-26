#include "raylib.h"
#include "scenes/SceneManager.hpp"
#include "scenes/main-menu/MainMenu.h"
#include "utils/config/FontManager.hpp"
#include "utils/config/GameConfig.h"


int main() {
    GameConfig gameConfig;
    gameConfig.load();
    SetExitKey(0);

    InitWindow(gameConfig.screen_width, gameConfig.screen_height, "Age Of Magic");

    // initalization that require a opengl context
    FontManager::init();

    if (gameConfig.fullscreen) {
        ToggleFullscreen();
    }

    Scene* menu = new MainMenu();

    SceneManager::ChangeScene(menu);

    SceneManager::getCurrentScene()->create();

    while (!WindowShouldClose()) {
        SceneManager::getCurrentScene()->update();

        BeginDrawing();

        SceneManager::getCurrentScene()->render();

        EndDrawing();
    }

    if (SceneManager::getCurrentScene() != nullptr) {
        delete SceneManager::getCurrentScene();
    }

    CloseWindow();
}
