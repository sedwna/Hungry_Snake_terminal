#pragma once
#include "../include/frog.hpp"
#include "../include/snake.hpp"
#include <string>
#include <array>
#define row 12
#define column 9

class App
{
private:
    Frog frog;
    Snake snake;
    void help() const;
    void clear() const;
    void lowercase(std::string &);
    void runGame();
    void delay(int ms);
    void printBoard(std::string board[][column]);
    bool checkStatus(std::string board[][column], int OX);
    void createBoard(std::string board[][column]);

public:
    App();
    int speed = 350;
    unsigned int point = 0;
    void splashScreen() const;
    int exec();
};

