//
// Created by akash on 7/25/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include "raylib.h"
#include "../../utils/renderer/Scene.h"
#include "../ui/MainMenuButton.hpp"


class MainMenu : public Scene {
private:
    Texture2D background = Texture2D{};
    MainMenuButton* playButton = nullptr;
    MainMenuButton* optionsButton = nullptr;
    MainMenuButton* exitButton = nullptr;

public:
    void create() override;
    void update() override;
    void render() override;
    void destroy() override;
};



#endif //MAINMENU_H
