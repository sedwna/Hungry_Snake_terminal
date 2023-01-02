#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <time.h>

#define row 12
#define column 9

using namespace std;
int ox = 3; // مختصات سر مار
int speed = 400;
unsigned int point = 0;
void delay(int ms)
{
    clock_t start = clock();
    while (clock() < start + ms)
        ;
}
void printBoard(string board[][column])
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
void frogStatus(int random, string board[][column], int down)
{
    for (size_t i = 0; i < down; i++)
    {
        board[i][random] = "   ";
    }

    board[down][random] = " * ";
}
bool checkStatus(string board[][column], int OX)
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
void snakeStatus(char playerMove, string board[][column])
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
void createBoard(string board[][column])
{

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            board[i][j] = "   ";
        }
    }
}
int generateRandom()
{
    srand((unsigned)time(NULL));
    int random = rand() % column;
    return random;
}
void app()
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

int main()
{

    app();

    return 0;
}