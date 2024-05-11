#include "label.h"

Label::Label(SDL_Renderer* renderer, int x, int y, int w, int h, std::string path, int size, std::string text) : Entity(x, y, w, h)
{
    this->path = path;
    setFgColor(0, 0, 0, 255);
    setBgColor(255, 255, 255, 0);
    setText(renderer, text, size);
}

Label::~Label()
{
    TTF_CloseFont(font);
}

void Label::setFgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    fgColor = {r, g, b, a};
}

void Label::setBgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    bgColor = {r, g, b, a};
    color = bgColor;
}

void Label::draw(SDL_Renderer* renderer)
{
    Entity::draw(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void Label::update()
{
    
}

void Label::setText(SDL_Renderer* renderer, std::string text, int size)
{
    this->text = text;
    this->size = size;
    font = TTF_OpenFont(path.c_str(), 19);
    if(font == nullptr)
    {
        std::cerr << "Impossible create the font!" << std::endl;
        std::cerr << TTF_GetError() << std::endl;
    }
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fgColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
}