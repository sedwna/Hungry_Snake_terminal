
#include "../include/snake.hpp"

Snake::Snake()
{
}
void Snake::snakeStatus(char playerMove, std::string board[][column])
{
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
}