#include "../include/frog.hpp"

int Frog::frogStartpos()
{
    int random = 0;
    while (random < 50 || random >x_SIZE -50)
    {
        random = rand() % x_SIZE ;
    }
    return random;
}

