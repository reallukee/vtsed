#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

#define EXIT_OK      0
#define EXIT_ERROR   -1

#define APPLES  1
#define BANANAS 2
#define ORANGES 3
#define PEACHES 4
#define KIWI    5

void myOnCallStart();
void myOnCallEnd();
bool myOnDraw(int index, string option, bool state, bool selected, bool current);

int main()
{
    if (!enableVTS())
        return EXIT_ERROR;

    string options[] = {
        "----------------",
        " Apples  ",
        " Bananas ",
        " Oranges ",
        " Peaches ",
        " Kiwi    ",
        "----------------",
    };

    bool optionsState[] = {
        false,
        true,
        true,
        true,
        true,
        true,
        false,
    };

    int selectedOptions[] = {
        0,
        1,
        0,
        1,
        0,
        0,
        0,
    };

    checkListBox myCheckListBox;

    myCheckListBox.setOptions(options);
    myCheckListBox.setOptionsState(optionsState);
    myCheckListBox.setSelectedOptions(selectedOptions);
    myCheckListBox.setOptionsCount(7);

    myCheckListBox.onCallStart = myOnCallStart;
    myCheckListBox.onCallEnd = myOnCallEnd;
    myCheckListBox.onDraw = myOnDraw;

    bool doLoop = true;

    while (doLoop)
    {
        int r = myCheckListBox.call()[0];

        doLoop = false;
    }

    return EXIT_OK;
}


void myOnCallStart()
{
    cout << "Chiamata Iniziata!" << endl;
}


void myOnCallEnd()
{
    cout << "Chiamata Terminata!" << endl;
}


bool myOnDraw(int index, string option, bool state, bool selected, bool current)
{
    if (index == KIWI)
    {
        if (current)
        {
            if (selected)
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(60, 125, 60));
                cout << " ( * ) ";
            }
            else
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(75, 160, 80));
                cout << " (   ) ";
            }
        }
        else
        {
            if (selected)
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(50, 110, 50));
                cout << " ( * ) ";
            }
            else
            {
                cout << sFC(RGBCOLOR(50, 110, 50));
                cout << sBC(RGBCOLOR(12));
                cout << " (   ) ";
            }
        }

        cout << option;

        return false;
    }

    return true;
}
