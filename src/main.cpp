#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "components/scene.h"
#include "game/scenes/mainScene.h"
#include "game/scenes/menu.h"
#include "game/score.h"

// Window settings
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

Score* score;

// Scenes
MainScene* mainScene = nullptr;
Menu* menu = nullptr;

// TODO: Initialize here and no repeat
void init()
{
    // Create a score object and load the saving in "saving/saving.data"
    score = new Score();
    score->load();

    // Create scenes
    mainScene = new MainScene(renderer, event, score);
    menu = new Menu(renderer, event);
    // Add scenes to sceneList
    sceneList.push_back(mainScene);
    sceneList.push_back(menu);
}

// TODO: Code repeated unless the loop stop
void update()
{
    // Buttons on the menu
    menu->start(&currentSceneIndex);
    menu->quit(&running);

    // Quit event
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        running = false;

    // Update right scene
    for(Scene* scene : sceneList)
        if(scene->index == currentSceneIndex)
            scene->update();
}

// TODO: Draw and repeat unless the loop stop
void draw()
{
    // Draw right scene
    for(Scene* scene : sceneList)
        if(scene->index == currentSceneIndex)
            scene->draw(); 
}

// TODO: Destroy before quit
void destroy()
{
    // Delete all scenes
    for(Scene* scene : sceneList)
        delete scene;

    sceneList.clear();
    // Save the score and delete
    score->save();
    delete score;
}

int main()
{
    // Initialize SDL libraries
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    // Create window and renderer
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    init();

    // Game Loop
    while(running)
    {
        // Event handler
        while(SDL_PollEvent(&event))
        {
            update();

            if(event.type == SDL_QUIT)
                running = false;
        }

        // Clean the window
        SDL_RenderClear(renderer);

        draw();
        
        // Set BG color and update the window
        SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR);
        SDL_RenderPresent(renderer);

        // Set an interval by 1 millisecond
        SDL_Delay(1);
    }

    destroy();

    // Destroy window and renderer
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    // Quit SDL libraries
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();

    return 0;
}