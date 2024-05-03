#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "../../components/scene.h"
#include "../player.h"
#include "../orchard.h"
#include "../score.h"
#include "../../components/gui/label.h"

class MainScene : public Scene
{
    public:
    MainScene(SDL_Renderer* renderer);
    ~MainScene();
    void update() override;

    private:
    Player* player;
    Orchard* orchard;

    void plant(Player* player, Orchard* orchard);
    void createPlant(Orchard* orchard);
    void createWheat(Orchard* orchard);

    const Uint8* keys;
    Uint64 lastTime;

    bool hasSeeds = false;
    bool hasPlant = false;
    bool hasWheat = false;

    void takeWheat(Player* player, Orchard* orchard);
    Score score;

    Label* numberSeedsLabel;
    Label* numberWheatLabel;
};

#endif