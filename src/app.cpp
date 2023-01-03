#include "../include/app.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <exception>
#include <cctype>
#include <time.h>
#include <conio.h>

int ox = 3; // مختصات سر مار
int speed = 350;
unsigned int point = 0;
using namespace std;

App::App()
{
    splashScreen();
}
void App::splashScreen() const
{

    cout << "   |=|===================|=|      \n";
    cout << "   |=|                   |=|      \n";
    cout << "   |=|   Hungry Snake    |=|      \n";
    cout << "   |                       |      \n";
    cout << "   |=======================|      \n";
    cout << "   |=======================|      \n";

    cout << endl;
    cout << "[<!>] "
         << "Enter <help> command to guide you\n"
         << endl;
}
void App::help() const
{
    cout << "[<!>] "
         << "app commands : (case insensitive)" << endl;

    cout << "for start game enter : s"
         << endl;
}
int App::exec()
{
    string command;
    while (1)
    {
        try
        {
            cout << "> ";
            getline(cin, command);
            lowercase(command);

            if (cin.eof() || command == "s")
            {
                runGame();
            }
            else if (command == "help")
            {
                help();
            }

            else if (command.empty())
            {
                // to prevent print undefined command in empty command
            }
            else
            {
                throw "undefined command";
            }
        }
        catch (const char *message)
        {
            std::cerr << "[<!>] " << message << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "[<!>] " << e.what() << endl;
        }
    }

    command.clear();

    cout << "[<!>] "
         << "app finished" << endl;
    return EXIT_SUCCESS;
}

void App::lowercase(string &str)
{
    if (cin.eof() || str.empty())
    {
        return;
    }

    for (char &ch : str)
    {
        ch = tolower(ch);
    }
}
void App::clear() const
{
#ifdef WINDOWS // windows based OS
    std::system("cls");
#else // unix like OS
    std::system("clear");
#endif

    splashScreen();
}

void App::runGame()
{
    string board[row][column];
    createBoard(board);
    printBoard(board);
    board[row - 1][ox] = " ^ ";

    while (1)
    {
        int random = generateRandom();

        for (int i = 0; i < row; i++)
        {

            if (_kbhit())
            {
                char ch = _getch();
                snakeStatus(ch, board);
            }

            frogStatus(random, board, i);
            if (checkStatus(board, ox))
            {
                i += 2;
            };

            printBoard(board);
        }
    }
}
void App::delay(int ms)
{
    clock_t start = clock();
    while (clock() < start + ms)
        ;
}
void App::printBoard(string board[][column])
{
    system("cls");
    cout << "point : " << point << "\n"
         << endl;
    for (size_t i = 0; i < row; i++)
    {
        cout << "|";
        for (size_t j = 0; j < column; j++)
        {
            cout << board[i][j];
        }
        cout << "|";
        cout << endl;
    }
    cout << "-----------------------------" << endl;
    delay(speed);
    speed--;
}
void App::frogStatus(int random, string board[][column], int down)
{
    for (size_t i = 0; i < down; i++)
    {
        board[i][random] = "   ";
    }

    board[down][random] = " * ";
}
bool App::checkStatus(string board[][column], int OX)
{

    if (board[row - 1][OX] == " ^ " && board[row - 2][OX] == " * ")
    {
        point++;
        board[row - 2][OX] = "   ";
        return true;
    }
    else
    {
        for (size_t i = 0; i < column; i++)
        {
            if (board[row - 1][i] == " * ")
            {

                board[row - 2][i] == "   ";
                printBoard(board);
                cout << "GAME OVER" << endl;
                exit(0);
            }
        }
    }
}
void App::snakeStatus(char playerMove, string board[][column])
{

    if (playerMove == 'a' || playerMove == 'd')
    {
        if (playerMove == 'a')
        {
            board[row - 1][ox] = "   ";
            if (ox > 0) // check out of range
            {
                ox -= 1;
            }

            board[row - 1][ox] = " ^ ";
        }
        if (playerMove == 'd')
        {
            board[row - 1][ox] = "   ";
            if (ox < column - 1) // check out of range
            {
                ox += 1;
            }
            board[row - 1][ox] = " ^ ";
        }
    }
}
void App::createBoard(string board[][column])
{

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            board[i][j] = "   ";
        }
    }
}
int App::generateRandom()
{
    srand((unsigned)time(NULL));
    int random = rand() % column;
    return random;
}
