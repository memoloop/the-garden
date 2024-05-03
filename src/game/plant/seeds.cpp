#include "seeds.h"

Seeds::Seeds(SDL_Renderer* renderer, int x, int y) : Sprite(renderer, x, y, 100, 100, "assets/sprites.png")
{
    textRect.x = 85;
    textRect.y = 0;
    textRect.w = 140-85;
    textRect.h = 75;
}

Seeds::~Seeds()
{

}