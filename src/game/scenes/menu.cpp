#include "menu.h"

#define FONT "assets/font.ttf"
#define BACKGROUND_COLOR 39, 179, 44, 255
#define BUTTON_BG_COLOR 213, 224, 221, 255
#define WHITE 255, 255, 255, 255

Menu::Menu(SDL_Renderer* renderer, SDL_Event event) : Scene(renderer, event, 0)
{
    title = new Label(renderer, 1600/2-500/2, 300, 500, 250, FONT, 19, "The Garden");
    startButton = new Button(renderer, title->rect.x+title->rect.w/2-100/2, title->rect.y+title->rect.h+50, 100, 50, FONT, 19, "START");
    quitButton = new Button(renderer, startButton->rect.x, startButton->rect.y+startButton->rect.h+10, 100, 50, FONT, 19, "QUIT");

    title->setBgColor(BACKGROUND_COLOR);
    startButton->setBgColor(BUTTON_BG_COLOR);
    quitButton->setBgColor(BUTTON_BG_COLOR);

    title->setFgColor(WHITE);
    startButton->setFgColor(WHITE);
    quitButton->setFgColor(WHITE);

    add(title);
    add(startButton);
    add(quitButton);
}

Menu::~Menu()
{

}

void Menu::start(int* currentSceneIndex)
{
    if(startButton->click(SDL_BUTTON_LEFT))
    {
        *currentSceneIndex = 1;
    }
}

void Menu::quit(bool* running)
{
    if(quitButton->click(SDL_BUTTON_LEFT))
        *running = false;
}