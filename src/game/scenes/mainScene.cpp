#include "mainScene.h"

// TODO: Initialize here
MainScene::MainScene(SDL_Renderer* renderer, SDL_Event event, Score* score) : Scene(renderer, event, 1)
{
    this->score = score;
    // Get keyboard state. Use it to click a key
    keys = SDL_GetKeyboardState(nullptr);

    // Initialize the player
    player = new Player(renderer);
    // Initialize the orchard
    orchard = new Orchard(renderer);
    // Initialize a npc
    npc = new Npc(renderer, event, score);

    // * ------ GUI --------
    // Create the label that visualize the score on top-left
    numberSeedsLabel = new Label(renderer, 10, 10, 100, 45, "assets/font.ttf", 19, "Seeds: "+std::to_string(score->numberSeeds));
    numberWheatLabel = new Label(renderer, 10, 10+numberSeedsLabel->rect.y+numberSeedsLabel->rect.h, 100, 45, "assets/font.ttf", 19, "Wheat: "+std::to_string(score->numberWheat));
    numberMoneyLabel = new Label(renderer, 10, numberWheatLabel->rect.y+numberWheatLabel->rect.h+10, 100, 45, "assets/font.ttf", 19, "Money: "+std::to_string(score->numberMoney));

    // Set the label's background color
    numberSeedsLabel->setBgColor(BACKGROUND_COLOR);
    numberWheatLabel->setBgColor(BACKGROUND_COLOR);
    numberMoneyLabel->setBgColor(BACKGROUND_COLOR);

    // Add all element created at the scene
    add(orchard);
    add(player);
    add(npc);
    add(numberSeedsLabel);
    add(numberWheatLabel);
    add(numberMoneyLabel);

    // Set a timer for seeds' grown in the orchard
    timerSeeds = new Timer(10000);
    timerPlant = new Timer(10000);
}

// TODO: Destroy Pointer here
MainScene::~MainScene()
{

}

// TODO: Update here
void MainScene::update()
{
    Scene::update();

    plant(player, orchard);
    createPlant(orchard);
    createWheat(orchard);

    takeWheat(player, orchard);

    // Update text
    numberSeedsLabel->setText(renderer, "Seeds: "+std::to_string(score->numberSeeds), 19);
    numberWheatLabel->setText(renderer, "Wheat: "+std::to_string(score->numberWheat), 19);
    numberMoneyLabel->setText(renderer, "Money: "+std::to_string(score->numberMoney), 19);

    // Open trade form
    npc->openTradeForm(player);

    // Save Game with CTRL+S
    if(keys[SDL_SCANCODE_LCTRL] || keys[SDL_SCANCODE_RCTRL])
        if(keys[SDL_SCANCODE_S])
            score->save();
}

// Plant a plant in an empty orchard
void MainScene::plant(Player* player, Orchard* orchard)
{
    if(!hasSeeds && !hasPlant && !hasWheat && score->numberSeeds >= 3)
        if(SDL_HasIntersection(&player->rect, &orchard->rect))
            if(keys[SDL_SCANCODE_SPACE])
            {   
                orchard->addSeeds(renderer, player);
                hasSeeds = true;
                score->numberSeeds -= 3;
                timerSeeds->start();
            }        
}

// The seeds grown in a plant
void MainScene::createPlant(Orchard* orchard)
{
    if(hasSeeds)
    {
        if(timerSeeds->update())
        {
            orchard->addPlant(renderer);
            lastTime = SDL_GetTicks64();
            timerPlant->start();
            timerSeeds->stop();
            hasPlant = true;
            hasSeeds = false;
        }
    }
    
}

// The plant grown in wheat
void MainScene::createWheat(Orchard* orchard)
{
    if(hasPlant)
    {
        if(timerPlant->update())
        {
            orchard->addWheat(renderer);
            lastTime = SDL_GetTicks64();
            timerPlant->stop();
            hasWheat = true;
            hasPlant = false;
        }
    }
}

// If player is in collision with orchard and user press LSHIFT, you take wheat
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