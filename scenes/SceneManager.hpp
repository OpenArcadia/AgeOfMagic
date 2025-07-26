//
// Created by akash on 7/25/25.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include "../utils/renderer/Scene.h"


class SceneManager {
    static Scene* scene;

public:
    static Scene* getCurrentScene();
    static void ChangeScene(Scene* scene);
};



#endif //SCENEMANAGER_HPP
