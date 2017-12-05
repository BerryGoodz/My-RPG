#include "Timer.h"

Timer::Timer()
{
    //ctor
}

Timer::~Timer()
{
    //dtor
}
void Timer::setTimer(float n)
{
    t = n;
}
float Timer::getTime()
{
    return t;
}
void Timer::frameRun()
{
    t --;
}
