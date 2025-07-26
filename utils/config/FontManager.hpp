//
// Created by akash on 7/26/25.
//

#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP
#include "raylib.h"


class FontManager {
private:
    static Font font;

public:
    static void init();
    static Font getFont();
};



#endif //FONTMANAGER_HPP
