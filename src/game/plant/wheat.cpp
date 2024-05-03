#include "wheat.h"

Wheat::Wheat(SDL_Renderer* renderer, int x, int y) : Sprite(renderer, x, y, 100, 100, "assets/sprites.png")
{
    textRect.x = 180;
    textRect.y = 0;
    textRect.w = 230-180;
    textRect.h = 100;
}

Wheat::~Wheat()
{
    
}