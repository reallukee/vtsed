#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

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
        case 1:
            cout << "Play              ";
            break;

        case 2:
            cout << "Options           ";
            break;

        case 3:
            cout << "About             ";
            break;

        case 5:
            doLoop = false;
            break;

        default:
            break;
        }
    }

    return 0;
}
