#include "..\vtsed\vtsed.hpp"

using namespace vtsed;

#define EXIT_OK      0
#define EXIT_ERROR   -1

int main()
{
    if (!enableVTS())
        return EXIT_ERROR;

    initConsole();

    char k = _getch();

    return EXIT_OK;
}
