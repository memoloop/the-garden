#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>
#include <iostream>

#include "entity.h"

class Timer
{
    public:
    Timer(Uint64 time);
    ~Timer();
    void start();
    void stop();
    bool update();
    bool isStarted = false;

    private:
    Uint64 time;
    Uint64 currentTime;
    Uint64 deltaTime;
};

#endif