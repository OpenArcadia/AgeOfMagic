//
// Created by akash on 7/25/25.
//

#include "SceneManager.hpp"

Scene* SceneManager::scene = nullptr;

Scene* SceneManager::getCurrentScene() {
    return scene;
}

void SceneManager::ChangeScene(Scene* scene) {
    if (scene == nullptr) {
        return;
    }

    if (SceneManager::scene != nullptr) {
        SceneManager::scene->destroy();
        delete SceneManager::scene;
    }

    SceneManager::scene = scene;
    scene->create();
}