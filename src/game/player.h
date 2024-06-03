#ifndef PLAYER_H
#define PLAYER_H

#include "../components/sprite.h"

class Player : public Sprite
{
    public:
    Player(SDL_Renderer* renderer);
    ~Player();
    void update() override;

    private:
    int speed = 5;
    void move();
    void animate();
    Uint64 lastTime;
    Uint64 changeFrameTime = 200;
    int frameHeight = 75;
    const Uint8* keys;
};

#endif