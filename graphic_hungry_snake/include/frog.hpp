#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <time.h>
#include <iomanip>
#define x_SIZE 800
#define y_SIZE 600

class Frog
{
private:
     float frogSpeed = 1;
public:
    // Frog(/* args */);
    int frogStartpos();
    void frog_setSpeed();
    float frog_getSpeed();
    void frog_speed_reset();
   
};
