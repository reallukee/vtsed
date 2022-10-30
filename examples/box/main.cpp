#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    string content[] = {
        "Lorem ipsum dolor sit.",
        "Lorem ipsum dolor sit.",
        "Lorem ipsum dolor sit.",
    };

    if (!enableVTS())
        return -1;

    box(content, 3, "Lorem ipsum", 4, 2);

    _getch();

    return 0;
}
