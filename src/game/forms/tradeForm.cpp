#include "tradeForm.h"

#define BACKGROUND_COLOR 184, 195, 212, 0

TradeForm::TradeForm(SDL_Renderer* renderer, SDL_Event event, Score* score) : Form(renderer, event, false, 200, 250, 1600-200*2, 900-250*2)
{
    this->score = score;
    setColor(BACKGROUND_COLOR);
    
    Label* moneyNumber = new Label(renderer, 20, 20, 50, 50, "assets/font.ttf", 19, "3");
    moneyNumber->setBgColor(BACKGROUND_COLOR);
    Sprite* money = new Sprite(renderer, moneyNumber->rect.x+moneyNumber->rect.w, 0, 100, 100, "assets/sprites.png");
    money->textRect = {240, 0, 290-240, 75};
    Label* equal = new Label(renderer, money->rect.x+money->rect.w+20, moneyNumber->rect.y, 50, 50, "assets/font.ttf", 19, "=");
    equal->setBgColor(BACKGROUND_COLOR);
    Label* wheatNumber = new Label(renderer, equal->rect.x+equal->rect.w+20, equal->rect.y, 50, 50, "assets/font.ttf", 19, "6");
    wheatNumber->setBgColor(BACKGROUND_COLOR);
    Sprite* wheat = new Sprite(renderer, wheatNumber->rect.x+wheatNumber->rect.w-10, 0, 100, 100, "assets/sprites.png");
    wheat->textRect = {180, 0, 230-180, 100};

    sell = new Button(renderer, 200, 200, 150, 100, "assets/font.ttf", 19, "Sell");
    decline = new Button(renderer, 410, 200, 150, 100, "assets/font.ttf", 19, "Decline");

    add(moneyNumber);
    add(money);
    add(equal);
    add(wheatNumber);
    add(wheat);

    add(sell);
    add(decline);
}

void TradeForm::update()
{
    Form::update();
    if(isVisible)
    {
        if(sell->click(SDL_BUTTON_LEFT))
        {
            if(score->numberWheat >= 6)
            {
                score->numberWheat -= 6;
                score->numberMoney += 3;
                score->save();
            }
            isVisible = false;
        }

        if(decline->click(SDL_BUTTON_LEFT))
        {
            isVisible = false;
        }
    }
}

TradeForm::~TradeForm()
{

}