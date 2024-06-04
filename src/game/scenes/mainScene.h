#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "../../components/scene.h"
#include "../player.h"
#include "../orchard.h"
#include "../npc.h"
#include "../score.h"
#include "../../components/gui/label.h"
#include "../../components/gui/button.h"
#include "../forms/tradeForm.h"
#include "../../components/timer.h"

#define BACKGROUND_COLOR 39, 179, 44, 255

// Scene core where are the game
class MainScene : public Scene
{
    public:
    MainScene(SDL_Renderer* renderer, SDL_Event event, Score* score);
    ~MainScene();
    void update() override;

    private:
    // Player
    Player* player;
    // Orchard
    Orchard* orchard;
    Npc* npc;
    // Score
    Score* score;

    // Player plant seeds in a orchard
    void plant(Player* player, Orchard* orchard);
    // Seeds in orchard in params grown in plant
    void createPlant(Orchard* orchard);
    // Plant in orchard in params grown in wheat
    void createWheat(Orchard* orchard);

    Timer* timerSeeds;
    Timer* timerPlant;

    const Uint8* keys;
    Uint64 lastTime;

    bool hasSeeds = false;
    bool hasPlant = false;
    bool hasWheat = false;

    // Player take wheat in orchard
    void takeWheat(Player* player, Orchard* orchard);

    // GUI
    Label* numberSeedsLabel;
    Label* numberWheatLabel;
    Label* numberMoneyLabel;

    // Form where are the GUI to sell the wheat and take money
    TradeForm* tradeForm;
};

#endif