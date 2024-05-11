#include "mainScene.h"

MainScene::MainScene(SDL_Renderer* renderer, SDL_Event event) : Scene(renderer, event, 1)
{
    keys = SDL_GetKeyboardState(nullptr);

    score.numberSeeds = 3;
    score.numberWheat = 0;

    score.load();

    player = new Player(renderer);
    orchard = new Orchard(renderer);

    numberSeedsLabel = new Label(renderer, 10, 10, 300, 50, "assets/font.ttf", 19, "Number seeds: "+std::to_string(score.numberSeeds));
    numberWheatLabel = new Label(renderer, 10, 10+numberSeedsLabel->rect.y+numberSeedsLabel->rect.h, 300, 50, "assets/font.ttf", 19, "Number wheat: "+std::to_string(score.numberWheat));
    
    numberSeedsLabel->setBgColor(39, 179, 44, 255);
    numberWheatLabel->setBgColor(39, 179, 44, 255);

    button = new Button(renderer, 500, 300, 200, 100, "assets/font.ttf", 18, "Hello");

    add(orchard);
    add(player);
    add(numberSeedsLabel);
    add(numberWheatLabel);
    add(button);

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
    numberSeedsLabel->setText(renderer, "Number seeds: "+std::to_string(score.numberSeeds), 19);
    numberWheatLabel->setText(renderer, "Number wheat: "+std::to_string(score.numberWheat), 19);
    if(keys[SDL_SCANCODE_LCTRL] || keys[SDL_SCANCODE_RCTRL])
        if(keys[SDL_SCANCODE_S])
            score.save();
    if(button->click(SDL_BUTTON_LEFT))
        std::cout << "Click" << std::endl;

}

void MainScene::plant(Player* player, Orchard* orchard)
{
    if(!hasSeeds && score.numberSeeds >= 3)
        if(SDL_HasIntersection(&player->rect, &orchard->rect))
            if(keys[SDL_SCANCODE_SPACE])
            {   
                orchard->addSeeds(renderer, player);
                hasSeeds = true;
                score.numberSeeds -= 3;
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
                score.numberWheat += 3;
                score.numberSeeds += 4;
            }
}