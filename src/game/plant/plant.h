#ifndef PLANT_H
#define PLANT_H

#include "../../components/sprite.h"

class Plant : public Sprite
{
    public:
    Plant(SDL_Renderer* renderer, int x, int y);
    ~Plant();
};

#endif