#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <cstdint>
#include <nlohmann/json.hpp>

class GameConfig {
public:
    uint16_t screen_height = 720;
    uint16_t screen_width = 1280;
    bool fullscreen = false;
    uint8_t audio = 75;

    GameConfig() = default;

    void load();

    void save();
};

inline void to_json(nlohmann::json& j, const GameConfig& cfg) {
    j = {
        {"screen_height", cfg.screen_height},
        {"screen_width", cfg.screen_width},
        {"fullscreen", cfg.fullscreen},
        {"audio", cfg.audio}
    };
}

inline void from_json(const nlohmann::json& j, GameConfig& cfg) {
    j.at("screen_height").get_to(cfg.screen_height);
    j.at("screen_width").get_to(cfg.screen_width);
    j.at("fullscreen").get_to(cfg.fullscreen);
    j.at("audio").get_to(cfg.audio);
}

#endif //GAMECONFIG_H
