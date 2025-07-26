//
// Created by akash on 7/25/25.
//

#ifndef SCENE_H
#define SCENE_H



class Scene {
    public:
    virtual ~Scene();

    virtual void create() = 0;
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;
};

#endif //SCENE_H
