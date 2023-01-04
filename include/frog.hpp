#pragma once
#include <string>

#define row 12
#define column 9

class Frog
{
private:
    

public:
    int generateRandom();
    void frogStatus(int random, std::string board[][column], int down);
    
};
