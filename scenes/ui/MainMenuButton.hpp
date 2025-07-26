//
// Created by akash on 7/26/25.
//

#ifndef MAINMENUBUTTON_HPP
#define MAINMENUBUTTON_HPP

#include <functional>
#include <string>


class MainMenuButton {
private:
    int x, y;
    int width, height;
    std::function<void()> callback;
    std::string text;
    bool isHovered = false;
    bool isPressed = false;

public:
    MainMenuButton(int x, int y, int width, int height, std::string text, const std::function<void()> &callback);
    void render() const;
    void update();
};



#endif //MAINMENUBUTTON_HPP
