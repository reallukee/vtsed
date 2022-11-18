#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

#define PLAY    1
#define OPTIONS 2
#define ABOUT   3
#define QUIT    5

void myOnCallStart();
void myOnCallEnd();
bool myOnDraw(int index, string option, bool state, bool selected, bool current);

int main()
{
    string options[] = {
        "-------------",
        " (P) Play    ",
        " (O) Options ",
        " (A) About   ",
        "-------------",
        " (Q) Quit    ",
        "-------------",
    };

    bool optionsState[] = {
        false,
        true,
        true,
        true,
        false,
        true,
        false,
    };

    listBox myListBox;

    myListBox.setOptions(options);
    myListBox.setOptionsState(optionsState);
    myListBox.setSelectedOption(1);
    myListBox.setOptionsCount(7);
    myListBox.setX(4);
    myListBox.setY(8);

    myListBox.onCallStart = myOnCallStart;
    myListBox.onCallEnd = myOnCallEnd;
    myListBox.onDraw = myOnDraw;

    bool doLoop = true;

    while (doLoop)
    {
        int r = myListBox.call();

        if (r < -1)
        {
            setCursorPosition(4, 2);

            switch (r * -1)
            {
            case 'P':
            case 'p':
                cout << "(Shortcut) Play   ";
                break;

            case 'O':
            case 'o':
                cout << "(Shortcut) Options";
                break;

            case 'A':
            case 'a':
                cout << "(Shortcut) About  ";
                break;

            case 'Q':
            case 'q':
                doLoop = false;
                break;

            default:
                break;
            }
        }

        setCursorPosition(4, 2);

        switch (r)
        {
        case PLAY:
            cout << "Play              ";
            break;

        case OPTIONS:
            cout << "Options           ";
            break;

        case ABOUT:
            cout << "About             ";
            break;

        case QUIT:
            doLoop = false;
            break;

        default:
            break;
        }
    }

    return 0;
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
    if (index == QUIT)
    {
        if (current)
        {
            cout << sFC(RGBCOLOR(240));
            cout << sBC(RGBCOLOR(205, 55, 55));
        }
        else
        {
            cout << sFC(RGBCOLOR(205, 55, 55));
            cout << sBC(RGBCOLOR(12));
        }

        cout << option;

        return false;
    }

    return true;
}
