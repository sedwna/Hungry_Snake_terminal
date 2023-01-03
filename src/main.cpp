#include <iostream>
#include <time.h>
#include "../include/app.hpp"


using namespace std;


int main()
{

    App app;
    try
    {
        App app;
        return app.exec();
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }

    return 0;
}