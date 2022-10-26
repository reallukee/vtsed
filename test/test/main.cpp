#include "..\..\vtsed\vtsed.hpp"

int main()
{
    if (!enableVTS())
        return -1;

    initConsole();

    return 0;
}
