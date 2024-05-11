#ifndef MENU_H
#define MENU_H

#include "../../components/scene.h"
#include "../../components/gui/label.h"
#include "../../components/gui/button.h"

class Menu : public Scene
{
    public:
    Menu(SDL_Renderer* renderer, SDL_Event event);
    ~Menu();
    void start(int* currentSceneIndex);
    void quit(bool* running);
    
    private:
    Label* title;
    Button* startButton;
    Button* quitButton;
};

#endif