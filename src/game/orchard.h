#ifndef ORCHARD_H
#define ORCHARD_H

#include <vector>
#include "../components/sprite.h"
#include "plant/seeds.h"
#include "plant/plant.h"
#include "plant/wheat.h"
#include "player.h"

class Orchard : public Sprite
{
    public:
    Orchard(SDL_Renderer* renderer);
    ~Orchard();
    void draw(SDL_Renderer* renderer) override;
    void update() override;
    void addSeeds(SDL_Renderer* renderer, Player* player);
    void addPlant(SDL_Renderer* renderer);
    void addWheat(SDL_Renderer* renderer);
    void takeWheat();

    private:
    Seeds* seedsList[3];
    Plant* plantList[3];
    Wheat* wheatList[3];
};

#endif