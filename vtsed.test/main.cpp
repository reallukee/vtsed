#include "..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    if (!enableVTS())
        return -1;

    initConsole();

    for (int i = 0; i < 16; i++)
    {
        setCursorPosition(0, i);
        setForegroundColorWin32(i);
        cout << "Hello, World!" << endl;
    }

    for (int i = 0; i < 16; i++)
    {
        setCursorPosition(16, i);
        setForegroundColorWin32(i);
        cout << i << " Hello, World!" << endl;
    }

    char k = _getch();

    return 0;
}
