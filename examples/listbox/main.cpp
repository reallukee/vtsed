#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    string options[] = {
        "---------",
        " Play    ",
        " Options ",
        " About   ",
        "---------",
        " Quit    ",
        "---------",
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

    while (myListBox.call() != 5);

    return 0;
}
