#include "sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, int x, int y, int w, int h, std::string path) : Entity(x, y, w, h)
{
    rect = {x, y, w, h};
    textRect = {0, 0, w, h};
    this->path = path;
    setColor(255, 255, 255, 255);
    setTexture(renderer, this->path);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::setTexture(SDL_Renderer* renderer, std::string path)
{   
    this->path = path;
    texture = IMG_LoadTexture(renderer, path.c_str());
    if(!texture)
    {
        std::cout << "Error impossible load the texture: " << this->path << std::endl;
        SDL_Surface* surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
}

void Sprite::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &textRect, &rect);
}

void Sprite::update()
{
    
}