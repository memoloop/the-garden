#ifndef SEEDS_H
#define SEEDS_H

#include "../../components/sprite.h"

class Seeds : public Sprite
{
    public:
    Seeds(SDL_Renderer* renderer, int x, int y);
    ~Seeds();
};

#endif