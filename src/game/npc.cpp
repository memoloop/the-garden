#include "npc.h"

Npc::Npc(SDL_Renderer* renderer, SDL_Event event, Score* score) : Sprite(renderer, 1600-200, 500, 125, 125, "assets/sprites.png")
{
    setType();
    tradeForm = new TradeForm(renderer, event, score);
    keys = SDL_GetKeyboardState(nullptr);
}

Npc::~Npc()
{

}

void Npc::update()
{
    Sprite::update();
    tradeForm->update();
}

void Npc::draw(SDL_Renderer* renderer)
{
    Sprite::draw(renderer);
    tradeForm->draw(renderer);
}

void Npc::openTradeForm(Player* player)
{
    if(SDL_HasIntersection(&rect, &player->rect)) 
    {
        if(keys[SDL_SCANCODE_SPACE])
        {
            tradeForm->isVisible = true;
        }
    }
}

void Npc::setType()
{
    type = std::rand()%3;
    switch(type)
    {
        case RED_NPC:
        textRect = {425, 0, 100, 100};
        break;
        case PINK_NPC:
        textRect = {425+100, 0, 100, 100};
        break;
        case BLUE_NPC:
        textRect = {425+100*2, 0, 100, 100};
        break;
        default: break;
    }
}