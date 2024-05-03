#include "entity.h"

Entity::Entity(int x, int y, int w, int h)
{
    rect = {x, y, w, h};
    setColor(255, 255, 255, 255);
}

Entity::~Entity()
{
    
}

void Entity::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    color = {r, g, b, a};
}

void Entity::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Entity::update()
{
    
}