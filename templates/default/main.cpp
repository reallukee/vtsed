#include <vtsed.hpp>

using namespace vtsed;

#define EXIT_OK      0
#define EXIT_ERROR   -1

void _sgr(unsigned c);
void pause();

int main()
{
    if (!initConsole())
        return EXIT_ERROR;

    _sgr(SGR_BOLD);
    cout << "Hello, World!" << endl;
    _sgr(SGR_NO_BOLD);

    pause();

    return EXIT_OK;
}

void _sgr(unsigned c)
{
    cout << sgr(c);
}

void pause()
{
    char k = _getch();
}
