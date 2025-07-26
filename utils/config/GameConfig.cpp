//
// Created by akash on 7/25/25.
//

#include "GameConfig.h"

#include <fstream>
#include <iostream>

const auto config_path = "config.json";


void GameConfig::load() {
    std::ifstream file(config_path);

    if (!file.is_open()) {
        std::cerr << "Could not open config file: " << config_path << " [creating new config]\n";
        screen_width = 1920;
        screen_height = 1080;
        fullscreen = true;
        audio = 100;
        save();
        return;
    }

    // Check if the file is empty
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        std::cerr << "Config file is empty. Writing default config.\n";
        file.close();
        screen_width = 1920;
        screen_height = 1080;
        fullscreen = true;
        audio = 100;
        save();
        return;
    }

    file.seekg(0); // Go back to beginning for reading
    try {
        nlohmann::json j;
        file >> j;
        *this = j.get<GameConfig>();
    } catch (const std::exception& e) {
        std::cerr << "Error reading/parsing config: " << e.what() << "\n";
    }
}




void GameConfig::save() {
    std::ofstream file(config_path);
    if (!file.is_open()) {
        std::cerr << "Could not write config file: " << config_path << "\n";
        return;
    }

    nlohmann::json j = *this;
    file << j.dump(4);
}