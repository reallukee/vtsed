#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

#define EXIT_OK      0
#define EXIT_ERROR   -1

bool myOnDraw(string content, int row);

int main()
{
    if (!enableVTS())
        return EXIT_ERROR;

    GridRow myGridRow;

    string* content[5] = {
        new string[2] { "NOME", "COGNOME" },
        new string[2] { "Mario", "Rossi" },
        new string[2] { "Luigi", "Verdi" },
        new string[2] { "Mario", "Rossi" },
        new string[2] { "Luigi", "Verdi" },
    };

    myGridRow.setX(6);
    myGridRow.setY(2);
    myGridRow.setContent(content, 2, 5);

    myGridRow.onDraw = myOnDraw;

    myGridRow.draw();

    char k = _getch();

    return EXIT_OK;
}


bool myOnDraw(string content, int row)
{
    if (row == 0)
    {
        cout << sFC(RGBCOLOR(240));
        cout << sBC(RGBCOLOR(0, 128, 128));
    }
    else
    {
        if (row % 2 == 0)
        {
            cout << sFC(RGBCOLOR(240));
            cout << sBC(RGBCOLOR(150));
        }
        else
        {
            cout << sFC(RGBCOLOR(240));
            cout << sBC(RGBCOLOR(100));
        }
    }

    cout << content;

    return false;
}
