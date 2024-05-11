#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "components/scene.h"
#include "game/scenes/mainScene.h"
#include "game/scenes/menu.h"

#define TITLE "The Garden"
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900
#define BACKGROUND_COLOR 39, 179, 44, 255

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
bool running = true;
SDL_Event event;
int currentSceneIndex = 0;
std::vector<Scene*> sceneList;

MainScene* mainScene = nullptr;
Menu* menu = nullptr;

void init()
{
    mainScene = new MainScene(renderer, event);
    menu = new Menu(renderer, event);
    sceneList.push_back(mainScene);
    sceneList.push_back(menu);
}

void update()
{
    menu->start(&currentSceneIndex);
    menu->quit(&running);

    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        running = false;

    for(Scene* scene : sceneList)
        if(scene->index == currentSceneIndex)
            scene->update();
    
}

void draw()
{
    for(Scene* scene : sceneList)
        if(scene->index == currentSceneIndex)
            scene->draw(); 
}

void destroy()
{
    for(Scene* scene : sceneList)
        delete scene;
    sceneList.clear();
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    init();

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            update();

            if(event.type == SDL_QUIT)
                running = false;
        }

        SDL_RenderClear(renderer);

        draw();
        
        SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR);
        SDL_RenderPresent(renderer);
    }

    destroy();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();

    return 0;
}