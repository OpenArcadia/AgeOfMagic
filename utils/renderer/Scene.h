//
// Created by akash on 7/25/25.
//

#ifndef SCENE_H
#define SCENE_H



class Scene {
    public:
    virtual ~Scene() = default;

    virtual void create();
        virtual void render();
        virtual void update();
        virtual void destroy();
};



#endif //SCENE_H
