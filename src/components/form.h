#ifndef FORM_H
#define FORM_H

#include <vector>
#include "entity.h"

class Form : public Entity
{
    public:
    Form(SDL_Renderer* renderer, SDL_Event event, bool isVisible, int x, int y, int w, int h);
    ~Form();
    void add(Entity* entity);
    virtual void draw(SDL_Renderer* renderer) override;
    virtual void update() override;
    bool isVisible;

    protected:
    SDL_Renderer* renderer;
    std::vector<Entity*> entityList;
};

#endif