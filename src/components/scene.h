#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "entity.h"
#include "sprite.h"

class Scene
{
    public:
    Scene(SDL_Renderer* renderer, SDL_Event event, int index);
    ~Scene();
    void add(Entity* entity);
    int index;
    void draw();
    virtual void update();

    protected:
    SDL_Renderer* renderer;
    SDL_Event event;

    private:
    std::vector<Entity*> entityList;
};

#endif