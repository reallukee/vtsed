#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    string* content[3] = {
        new string[3] { "Lorem ipsum", "Lorem ipsum", "Lorem ipsum" },
        new string[3] { "Lorem ipsum", "Lorem ipsum", "Lorem ipsum" },
        new string[3] { "Lorem ipsum", "Lorem ipsum", "Lorem ipsum" },
    };

    if (!enableVTS())
        return -1;

    table(content, 3, 3, 4, 2);

    _getch();

    return 0;
}
