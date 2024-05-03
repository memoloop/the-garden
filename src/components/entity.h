#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

class Entity
{
    public:
    Entity(int x, int y, int w, int h);
    ~Entity();
    SDL_Rect rect;
    SDL_Color color;
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
};

#endif