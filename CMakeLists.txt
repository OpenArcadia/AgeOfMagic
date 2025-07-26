cmake_minimum_required(VERSION 3.31)
project(AgeOfMagic)

set(CMAKE_CXX_STANDARD 26)

include(FetchContent)

# Fetch raylib
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
)

set(FETCHCONTENT_QUIET OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_GAMES OFF)

# Fetch nlohmann/json
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG        v3.11.3
)

FetchContent_MakeAvailable(raylib nlohmann_json)

add_executable(AgeOfMagic
        main.cpp
        utils/renderer/Scene.cpp
        utils/renderer/Scene.h
        scenes/main-menu/MainMenu.cpp
        scenes/main-menu/MainMenu.h
        utils/config/GameConfig.cpp
        utils/config/GameConfig.h
        scenes/SceneManager.cpp
        scenes/SceneManager.hpp
        utils/config/FontManager.cpp
        utils/config/FontManager.hpp
        scenes/ui/MainMenuButton.cpp
        scenes/ui/MainMenuButton.hpp
)

# Link raylib and nlohmann_json
target_link_libraries(AgeOfMagic PRIVATE raylib nlohmann_json::nlohmann_json)


add_custom_command(TARGET AgeOfMagic POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:AgeOfMagic>/assets)
