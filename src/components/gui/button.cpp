#include "button.h"

Button::Button(SDL_Renderer* renderer, int x, int y, int w, int h, std::string font, int size, std::string text) : Label(renderer, x, y, w, h, font, size, text)
{

}

Button::~Button()
{

}

bool Button::click(Uint8 button)
{
    SDL_Point mousePos;    
    const Uint32 mouse = SDL_GetMouseState(&mousePos.x, &mousePos.y);

    if((mouse & SDL_BUTTON(button)) && SDL_PointInRect(&mousePos, &rect))
        return true;
    else return false;
}