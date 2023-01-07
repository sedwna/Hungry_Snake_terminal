#include "../include/frog.hpp"

int Frog::frogStartpos()
{
    int random = 0;
    while (random < 50 || random > x_SIZE - 50)
    {
        random = rand() % x_SIZE;
    }
    return random;
}
void Frog::frog_setSpeed()
{
    frogSpeed += 0.3;
}
float Frog::frog_getSpeed()
{
    return frogSpeed;
}
void Frog::frog_speed_reset()
{
    frogSpeed = 1;
}