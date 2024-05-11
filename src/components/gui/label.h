#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../entity.h"

class Label : public Entity
{
    public:
    Label(SDL_Renderer* renderer, int x, int y, int w, int h, std::string path, int size, std::string text);
    ~Label();
    void setText(SDL_Renderer* renderer, std::string text, int size);
    void setFgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void setBgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    virtual void draw(SDL_Renderer* renderer) override;
    virtual void update() override;

    protected:
    SDL_Color fgColor;
    SDL_Color bgColor = color;
    std::string path;
    std::string text;
    int size;
    SDL_Texture* texture;
    TTF_Font* font;
};

#endif