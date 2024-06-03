#ifndef TRADEFORM_H
#define TRADEFORM_H

#include "../../components/form.h"
#include "../../components/gui/button.h"
#include "../../components/gui/label.h"
#include "../../components/sprite.h"
#include "../score.h"

class TradeForm : public Form
{
    public:
    TradeForm(SDL_Renderer* renderer, SDL_Event event, Score* score);
    ~TradeForm();
    void update() override;

    private:
    Score* score;
    Button* sell;
    Button* decline;
};

#endif