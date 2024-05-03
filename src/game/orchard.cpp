#include "orchard.h"

Orchard::Orchard(SDL_Renderer* renderer) : Sprite(renderer, 400, 400, 300, 175, "assets/sprites.png")
{
    textRect.x = 295;
    textRect.y = 0;
    textRect.w = 425-295;
    textRect.h = 100;

    for(int i = 0; i < 3; i++)
        seedsList[i] = nullptr;

    for(int i = 0; i < 3; i++)
        plantList[i] = nullptr;

    for(int i = 0; i < 3; i++)
        wheatList[i] = nullptr;
} 

Orchard::~Orchard()
{
    for(Seeds* seeds : seedsList)
        if(seeds != nullptr)
            delete seeds;
    
    for(Plant* plant : plantList)
        if(plant != nullptr)
            delete plant;

    for(Wheat* wheat : wheatList)
        if(wheat != nullptr)
            delete wheat;
}

void Orchard::draw(SDL_Renderer* renderer)
{
    Sprite::draw(renderer);
    for(Seeds* seeds : seedsList)
        if(seeds != nullptr)
            seeds->draw(renderer);

    for(Plant* plant : plantList)
        if(plant != nullptr)
            plant->draw(renderer);

    for(Wheat* wheat : wheatList)
        if(wheat != nullptr)
            wheat->draw(renderer);
}

void Orchard::update()
{
    Sprite::update();
    for(Seeds* seeds : seedsList)
        if(seeds != nullptr)
            seeds->update();

    for(Plant* plant : plantList)
        if(plant != nullptr)
            plant->update();

    for(Wheat* wheat : wheatList)
        if(wheat != nullptr)
            wheat->update();
}

void Orchard::addSeeds(SDL_Renderer* renderer, Player* player)
{
    for(int i = 0; i < 3; i++)
    {
        if(seedsList[i] != nullptr || plantList[i] != nullptr || wheatList[i] != nullptr)
            continue;

        seedsList[i] = new Seeds(renderer, rect.x+20+75*i, rect.y+10);
    }
}

void Orchard::addPlant(SDL_Renderer* renderer)
{
    for(int i = 0; i < 3; i++)
    {
        if(plantList[i] != nullptr || seedsList[i] == nullptr)
            continue;

        plantList[i] = new Plant(renderer, seedsList[i]->rect.x, seedsList[i]->rect.y);
        delete seedsList[i];
        seedsList[i] = nullptr;
    }
}

void Orchard::addWheat(SDL_Renderer* renderer)
{
    for(int i = 0; i < 3; i++)
    {
        if(wheatList[i] != nullptr || plantList[i] == nullptr)
            continue;

        wheatList[i] = new Wheat(renderer, plantList[i]->rect.x, plantList[i]->rect.y);
        delete plantList[i];
        plantList[i] = nullptr;
    }
}

void Orchard::takeWheat()
{
    for(int i = 0; i < 3; i++)
    {
        if(wheatList[i] == nullptr)
            continue;

        delete wheatList[i];
        wheatList[i] = nullptr;
    }
}