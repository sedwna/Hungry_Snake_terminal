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
#include <string>
#include<fstream>

#include <conio.h>
class Game
{
private:
    int score = 0;
    std::string set_score();
    void tryAgain(sf::RenderWindow &window, sf::Text point);
    //----------------- set sound -----------------
    sf::SoundBuffer back_sound;
    sf::SoundBuffer eat_sound;
    sf::SoundBuffer gameover_sound;
    //---------------------------------------------
    //------------------- set font ----------------
    sf::Font font;
    //---------------------------------------------

    //------------------ set photo ----------------
    sf::Texture texture;
    sf::Texture snake_image;
    sf::Texture frog_image;
    //---------------------------------------------

public:
    // Game(/* args */);
    Frog frog;
    Snake snake;
    void runGame(sf::RenderWindow &window);
};
