#include "plant.h"

Plant::Plant(SDL_Renderer* renderer, int x, int y) : Sprite(renderer, x, y, 100, 100, "assets/sprites.png")
{
    textRect.x = 145;
    textRect.y = 0;
    textRect.w = 180-145;
    textRect.h = 100;
}

Plant::~Plant()
{
    
}