
#ifndef APP_IG
#define APP_IG
#include <string>
#define row 12
#define column 9


class App
{
private:
    void help() const;
    void clear() const;
    void lowercase(std::string &);
    void runGame();
    void delay(int ms);
    void printBoard(std::string board[][column]);
    void frogStatus(int random, std::string board[][column], int down);
    bool checkStatus(std::string board[][column], int OX);
    void snakeStatus(char playerMove, std::string board[][column]);
    void createBoard(std::string board[][column]);
    int generateRandom();

public:
    App();
    void splashScreen() const;
    int exec();
};

#endif
