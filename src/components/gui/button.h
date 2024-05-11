#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "label.h"

class Button : public Label
{
    public:
    Button(SDL_Renderer* renderer, int x, int y, int w, int h, std::string font, int size, std::string text);
    ~Button();
    bool click(Uint8 button);

    private:
    bool isClicked = false;
};

#endif