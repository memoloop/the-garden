#ifndef WHEAT_H
#define WHEAT_H

#include "../../components/sprite.h"

class Wheat : public Sprite
{
    public:
    Wheat(SDL_Renderer* renderer, int x, int y);
    ~Wheat();
};

#endif