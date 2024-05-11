#include "player.h"

Player::Player(SDL_Renderer* renderer) : Sprite(renderer, 200, 500, 100, 100, "assets/sprites.png")
{
    textRect.x = 0;
    textRect.y = 0;
    textRect.w = 100;
    textRect.h = 75;
    
    lastTime = SDL_GetTicks64();
    keys = SDL_GetKeyboardState(nullptr);
}

Player::~Player()
{
    
}

void Player::update()
{
    move();
    animate();
}

void Player::move()
{
    if(keys[SDL_SCANCODE_D])
    {
        rect.x += 1*speed;
    }
        
    if(keys[SDL_SCANCODE_A])
    {
        rect.x -= 1*speed;
    }
        
    if(keys[SDL_SCANCODE_W])
    {
        rect.y -= 1*speed;
    }
        
    if(keys[SDL_SCANCODE_S] && !(keys[SDL_SCANCODE_LCTRL] || keys[SDL_SCANCODE_RCTRL]))
    {
        rect.y += 1*speed;
    }
}

void Player::animate()
{
    Uint64 deltaTime = SDL_GetTicks64();
    if(keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_D])
    {
        if((deltaTime-lastTime) >= changeFrameTime) 
        {
            textRect.y += frameHeight;
            lastTime = SDL_GetTicks64();
        }
    }
    else
        textRect.y = 0;
    if(textRect.y >= frameHeight*3)
        textRect.y = 0;
}