#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL_image.h>
#include "entity.h"

class Sprite : public Entity
{
    public:
    Sprite(SDL_Renderer* renderer, int x, int y, int w, int h, std::string path);
    ~Sprite();
    void setTexture(SDL_Renderer* renderer, std::string path);
    virtual void draw(SDL_Renderer* renderer) override;
    virtual void update() override;
    SDL_Rect textRect;

    protected:
    std::string path;
    SDL_Texture* texture;
};

#endif