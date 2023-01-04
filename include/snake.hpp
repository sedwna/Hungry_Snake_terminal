#pragma once
#include <string>

#define row 12
#define column 9

class Snake
{
private:
public:
    Snake(/* args */);
    void snakeStatus(char playerMove, std::string board[][column]);
    int ox = 3; // snake head position
};
