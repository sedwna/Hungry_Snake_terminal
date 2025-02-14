#include <iostream>
#include "../include/app.hpp"

using namespace std;

int main()
{
    cout << "hello" << endl;
    App app;
    try
    {
        return app.exec();
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }

    return 0;
}