#include "form.h"

Form::Form(SDL_Renderer* renderer, SDL_Event event, bool isVisible, int x, int y, int w, int h) : Entity(x, y, w, h)
{
    this->isVisible = isVisible;
    this->renderer = renderer;
    setColor(255, 255, 255, 255);
}

Form::~Form()
{
    for(Entity* entity : entityList)
        delete entity;
    entityList.clear();
}

void Form::add(Entity* entity)
{
    entity->rect = {entity->rect.x+rect.x, entity->rect.y+rect.y, entity->rect.w, entity->rect.h};
    entityList.push_back(entity);
}

void Form::draw(SDL_Renderer* renderer)
{
    if(isVisible)
    {
        Entity::draw(renderer);
        for(Entity* entity : entityList)
            entity->draw(renderer);
    }
}

void Form::update()
{
    if(isVisible)
    {
        Entity::update();
        for(Entity* entity : entityList)
            entity->update();
    } 
}