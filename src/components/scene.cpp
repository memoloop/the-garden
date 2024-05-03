#include "scene.h"

Scene::Scene(SDL_Renderer* renderer, int index)
{
    this->renderer = renderer;
    this->event = event;
    this->index = index;
}

Scene::~Scene()
{
    for(Entity* entity : entityList)
        delete entity;
    entityList.clear();
}

void Scene::add(Entity* entity)
{
    entityList.push_back(entity);
}

void Scene::draw()
{
    for(Entity* entity : entityList)
        entity->draw(renderer);
}

void Scene::update()
{
    for(Entity* entity : entityList)
        entity->update();
}