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
        std::cerr << "Could not open config file: " << config_path << " [creating new config]" << "\n";
        std::ofstream config_file;
        config_file.open(config_path);
        if (!config_file.is_open()) {
            std::cerr << "Could not create new config file: " << config_path << "\n";
            config_file.close();
        }
        return;
    }

    nlohmann::json j;

    file >> j;

    *this = j.get<GameConfig>();
}


