#include <vtsed.hpp>

using namespace vtsed;

void _sgr(unsigned int c);
void pause();

int main()
{
    if (!initConsole())
        return -1;

    _sgr(SGR_BOLD);
    cout << "Hello, World!" << endl;
    _sgr(SGR_NO_BOLD);

    pause();

    return 0;
}

void _sgr(unsigned int c)
{
    cout << sgr(c);
}

void pause()
{
    char k = _getch();
}
