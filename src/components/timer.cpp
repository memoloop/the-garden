#include "timer.h"

Timer::Timer(Uint64 time)
{
    this->time = time;
    currentTime = 0;
    deltaTime = 0;
}

Timer::~Timer()
{

}

void Timer::start()
{
    isStarted = true;
}

void Timer::stop()
{
    isStarted = false;
    currentTime = 0;
}

bool Timer::update()
{
    if(isStarted)
    {
        currentTime += 100;
        if(currentTime >= time)
            return true;
        return false;
    }
    return false;
}