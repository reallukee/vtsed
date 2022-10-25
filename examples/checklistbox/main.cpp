#include "..\..\vtsed\vtsed.hpp"

using namespace vtsed;

int main()
{
    string options[] = {
        "---------",
        " Apples  ",
        " Bananas ",
        " Oranges ",
        " Peaches ",
        " Kiwi    ",
        "---------",
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

    myCheckListBox.call();

    return 0;
}
