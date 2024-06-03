#include "mainScene.h"

MainScene::MainScene(SDL_Renderer* renderer, SDL_Event event, Score* score) : Scene(renderer, event, 1)
{
    this->score = score;
    keys = SDL_GetKeyboardState(nullptr);

    player = new Player(renderer);
    orchard = new Orchard(renderer);
    npc = new Npc(renderer, event, score);

    numberSeedsLabel = new Label(renderer, 10, 10, 100, 45, "assets/font.ttf", 19, "Seeds: "+std::to_string(score->numberSeeds));
    numberWheatLabel = new Label(renderer, 10, 10+numberSeedsLabel->rect.y+numberSeedsLabel->rect.h, 100, 45, "assets/font.ttf", 19, "Wheat: "+std::to_string(score->numberWheat));
    numberMoneyLabel = new Label(renderer, 10, numberWheatLabel->rect.y+numberWheatLabel->rect.h+10, 100, 45, "assets/font.ttf", 19, "Money: "+std::to_string(score->numberMoney));

    numberSeedsLabel->setBgColor(BACKGROUND_COLOR);
    numberWheatLabel->setBgColor(BACKGROUND_COLOR);
    numberMoneyLabel->setBgColor(BACKGROUND_COLOR);

    add(orchard);
    add(player);
    add(npc);
    add(numberSeedsLabel);
    add(numberWheatLabel);
    add(numberMoneyLabel);
    
    lastTime = SDL_GetTicks64();
}

MainScene::~MainScene()
{

}

void MainScene::update()
{
    Scene::update();

    plant(player, orchard);
    createPlant(orchard);
    createWheat(orchard);

    takeWheat(player, orchard);

    numberSeedsLabel->setText(renderer, "Seeds: "+std::to_string(score->numberSeeds), 19);
    numberWheatLabel->setText(renderer, "Wheat: "+std::to_string(score->numberWheat), 19);
    numberMoneyLabel->setText(renderer, "Money: "+std::to_string(score->numberMoney), 19);

    npc->openTradeForm(player);

    if(keys[SDL_SCANCODE_LCTRL] || keys[SDL_SCANCODE_RCTRL])
        if(keys[SDL_SCANCODE_S])
            score->save();
}

void MainScene::plant(Player* player, Orchard* orchard)
{
    if(!hasSeeds && score->numberSeeds >= 3)
        if(SDL_HasIntersection(&player->rect, &orchard->rect))
            if(keys[SDL_SCANCODE_SPACE])
            {   
                orchard->addSeeds(renderer, player);
                hasSeeds = true;
                score->numberSeeds -= 3;
            }        
}

void MainScene::createPlant(Orchard* orchard)
{
    if(hasSeeds)
    {
        Uint64 deltaTime = SDL_GetTicks64();
        Uint64 grownTime = 5000;
        if((deltaTime-lastTime) >= grownTime)
        {
            orchard->addPlant(renderer);
            lastTime = SDL_GetTicks64();
            hasPlant = true;
            hasSeeds = false;
        }
    }
    
}

void MainScene::createWheat(Orchard* orchard)
{
    if(hasPlant)
    {
        Uint64 deltaTime = SDL_GetTicks64();
        Uint64 grownTime = 10000;
        if((deltaTime-lastTime) >= grownTime)
        {
            orchard->addWheat(renderer);
            lastTime = SDL_GetTicks64();
            hasWheat = true;
            hasPlant = false;
        }
    }
}

void MainScene::takeWheat(Player* player, Orchard* orchard)
{
    if(hasWheat)
        if(SDL_HasIntersection(&player->rect, &orchard->rect))
            if(keys[SDL_SCANCODE_LSHIFT])
            {
                orchard->takeWheat();
                hasWheat = false;
                score->numberWheat += 3;
                score->numberSeeds += 4;
            }
}