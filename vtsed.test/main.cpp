#include "..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    if (!enableVTS())
        return -1;

    initConsole();

    char k = _getch();

    return 0;
}
