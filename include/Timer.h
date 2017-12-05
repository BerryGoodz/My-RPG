#ifndef TIMER_H
#define TIMER_H

#include <Entity.h>
using namespace sf;

class Timer
{
    public:
        Timer();
        virtual ~Timer();
        void setTimer(float n);
        float getTime();
        void frameRun();

    private:
        float t = 0;
};

#endif // TIMER_H
