#include <vtsed.hpp>

using namespace vtsed;

int main()
{
    cout << sgr(SGR_BOLD_ON);
    cout << "Hello, World!" << endl;
    cout << sgr(SGR_BOLD_OFF);

    char k = _getch();

    return 0;
}
