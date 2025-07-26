//
// Created by akash on 7/26/25.
//

#include "FontManager.hpp"

#include <print>

Font FontManager::font;

void FontManager::init() {
    const auto f = LoadFont("assets/font.ttf");

    std::println("Font loaded: glyphCount={}, baseSize={}, texture.width={}", f.glyphCount, f.baseSize, f.texture.width);

    if (f.glyphCount == 0) {
        TraceLog(LOG_ERROR, "Font failed to load!");
    }

    font = f;
}

Font FontManager::getFont() {
    return font;
}