#pragma once
#include <sfml/Graphics.hpp>
#include "../include/frog.hpp"
#include "../include/snake.hpp"

#define row 12
#define column 9
#define x_SIZE 800
#define y_SIZE 600
#include <cctype>
#include <exception>
#include <string>
#include <array>
#include <iostream>
#include <time.h>
#include <iomanip>

#include <conio.h>
class Game
{
private:
  
    int score = 0;

public:
    // Game(/* args */);
    Frog frog;
    Snake snake;
    void runGame();
};
