#include "../include/frog.hpp"
#include <time.h>
#include <string>

void Frog::frogStatus(int random, std::string board[][column], int down)
{
    for (size_t i = 0; i < down; i++)
    {
        board[i][random] = "   ";
    }
    board[down][random] = " * ";
}
int Frog::generateRandom()

{
    srand((unsigned)time(NULL));
    int random = rand() % column;
    return random;
}
