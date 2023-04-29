/*
#include "../vtsed/vtsed.hpp"

using namespace vtsed;

#define EXIT_OK      0
#define EXIT_ERROR   -1

int main()
{
    cout << "Hello, World!" << endl;

    return EXIT_OK;
}
*/

#include "../vtsed/vtsed.hpp"

using namespace vtsed;

#define EXIT_OK      0
#define EXIT_ERROR   -1

bool myOnDraw(string content, int row);

int main()
{
    if (!enableVTS())
        return EXIT_ERROR;

    eraseInDisplay(TEXT_MODIFICATION_ERASE_ENTIRE);

    int size = 5;

    string options[] = {
        "Mele",
        "Pere",
        "Banane",
        "Kiwi",
        "Ananas"
    };

    ListBox* myListBox = new ListBox(options, size);

    myListBox->setOptionState(0, false);
    myListBox->setCurrentOption(2);

    int result = myListBox->call();

#ifdef WIN  // WIN
    char k = _getch();
#endif  // ! WIN

#ifdef UNIX // UNIX
    char k = getchar();
#endif  // ! UNIX

    return EXIT_OK;
}
