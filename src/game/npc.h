#ifndef NPC_H
#define NPC_H

#include <cstdlib>
#include "../components/sprite.h"
#include "player.h"
#include "forms/tradeForm.h"
#include "score.h"

#define RED_NPC 0
#define PINK_NPC 1
#define BLUE_NPC 2

class Npc : public Sprite
{
    public:
    Npc(SDL_Renderer* renderer, SDL_Event event, Score* score);
    ~Npc();
    void update() override;
    void draw(SDL_Renderer* renderer) override;
    void openTradeForm(Player* player);

    private:
    int type;
    void setType();
    TradeForm* tradeForm;
    const Uint8* keys;
};

#endif