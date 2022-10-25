#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    if (!enableVTS())
        return -1;

    initConsole();

    return 0;
}
