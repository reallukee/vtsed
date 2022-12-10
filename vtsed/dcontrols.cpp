//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    DYNAMIC CONTROL
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

#include "pch.hpp"

#include "dcontrols.hpp"

namespace vtsed
{
    #if defined(_WIN32) || defined(_WIN64)

    // ##
    // ##   Single Control
    // ##

    #pragma region Single Control

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void singleControl::setX(unsigned value)
    {
        x = value;
    }


    unsigned singleControl::getX()
    {
        return x;
    }


    void singleControl::setY(unsigned value)
    {
        y = value;
    }


    unsigned singleControl::getY()
    {
        return y;
    }


    void singleControl::setOptions(string* value)
    {
        options = value;
    }


    string* singleControl::getOptions()
    {
        return options;
    }


    void singleControl::setOptionsState(bool* value)
    {
        optionsState = value;
    }


    bool* singleControl::getOptionsState()
    {
        return optionsState;
    }


    void singleControl::setSelectedOption(int value)
    {
        selectedOptions[0] = value;
    }


    int singleControl::getSelectedOption()
    {
        return selectedOptions[0];
    }


    void singleControl::setCurrentOption(int value)
    {
        currentOption = value;
    }


    int singleControl::getCurrentOption()
    {
        return currentOption;
    }


    void singleControl::setOptionsCount(int value)
    {
        optionsCount = value;
    }


    int singleControl::getOptionsCount()
    {
        return optionsCount;
    }


    void singleControl::setOptionForeColor(RGBCOLOR value)
    {
        optionForeColor = value;
    }


    RGBCOLOR singleControl::getOptionForeColor()
    {
        return optionForeColor;
    }


    void singleControl::setOptionBackColor(RGBCOLOR value)
    {
        optionBackColor = value;
    }


    RGBCOLOR singleControl::getOptionBackColor()
    {
        return optionBackColor;
    }


    void singleControl::setSelectedOptionForeColor(RGBCOLOR value)
    {
        selectedOptionForeColor = value;
    }


    RGBCOLOR singleControl::getSelectedOptionForeColor()
    {
        return selectedOptionForeColor;
    }


    void singleControl::setSelectedOptionBackColor(RGBCOLOR value)
    {
        selectedOptionBackColor = value;
    }


    RGBCOLOR singleControl::getSelectedOptionBackColor()
    {
        return selectedOptionBackColor;
    }


    void singleControl::setCurrentOptionForeColor(RGBCOLOR value)
    {
        currentOptionForeColor = value;
    }


    RGBCOLOR singleControl::getCurrentOptionForeColor()
    {
        return currentOptionForeColor;
    }


    void singleControl::setCurrentOptionBackColor(RGBCOLOR value)
    {
        currentOptionBackColor = value;
    }


    RGBCOLOR singleControl::getCurrentOptionBackColor()
    {
        return currentOptionBackColor;
    }


    void singleControl::setDisabledOptionForeColor(RGBCOLOR value)
    {
        disabledOptionForeColor = value;
    }


    RGBCOLOR singleControl::getDisabledOptionForeColor()
    {
        return disabledOptionForeColor;
    }


    void singleControl::setDisabledOptionBackColor(RGBCOLOR value)
    {
        disabledOptionBackColor = value;
    }


    RGBCOLOR singleControl::getDisabledOptionBackColor()
    {
        return disabledOptionBackColor;
    }


    singleControl::singleControl()
    {
        x = defaultX;
        y = defaultY;
        options = NULL;
        optionsState = NULL;
        selectedOptions = new int[1];
        currentOption = 1;
        optionsCount = 0;
        optionForeColor = rgbFrom(240);
        optionBackColor = rgbFrom(12);
        selectedOptionForeColor = rgbFrom(65, 130, 115);
        selectedOptionBackColor = rgbFrom(40, 80, 70);
        currentOptionForeColor = rgbFrom(10, 70, 125);
        currentOptionBackColor = rgbFrom(35, 170, 240);
        disabledOptionForeColor = rgbFrom(120);
        disabledOptionBackColor = rgbFrom(12);
    }


    singleControl::~singleControl()
    {
        // delete options;
        // delete optionsState;
        // delete selectedOptions;
    }


    int singleControl::call()
    {
        if (onCallStart != nullptr)
            onCallStart();

        cursorVisible(false);

        draw();

        int R = loop();

        cursorVisible(true);

        cout << sgr(SGR_DEFAULT);

        if (onCallEnd != nullptr)
            onCallEnd();

        return R;
    }


    void singleControl::up()
    {
        if (currentOption - 1 >= 0)
            currentOption--;
        else
            currentOption = optionsCount - 1;

        while (!optionsState[currentOption])
        {
            if (currentOption - 1 >= 0)
                currentOption--;
            else
                currentOption = optionsCount - 1;
        }
    }


    void singleControl::down()
    {
        if (currentOption + 1 <= optionsCount - 1)
            currentOption++;
        else
            currentOption = 0;

        while (!optionsState[currentOption])
        {
            if (currentOption + 1 <= optionsCount - 1)
                currentOption++;
            else
                currentOption = 0;
        }
    }


    void singleControl::top()
    {
        currentOption = 0;

        while (!optionsState[currentOption])
            currentOption++;
    }


    void singleControl::bottom()
    {
        currentOption = optionsCount - 1;

        while (!optionsState[currentOption])
            currentOption--;
    }


    int singleControl::loop()
    {
        bool doLoop = true;

        while (doLoop)
        {
            char key = _getch();

            if (key == '\xE0')
                key = _getch();

            switch (key)
            {
            case 72:
            case 'W':
            case 'w':
                up();
                selectedOptions[0] = currentOption;

                if (onSelectedChange != NULL)
                    onSelectedChange(selectedOptions[0]);

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 80:
            case 'S':
            case 's':
                down();
                selectedOptions[0] = currentOption;

                if (onSelectedChange != NULL)
                    onSelectedChange(selectedOptions[0]);

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 73:
            case 'T':
            case 't':
                top();
                selectedOptions[0] = currentOption;

                if (onSelectedChange != NULL)
                    onSelectedChange(selectedOptions[0]);

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 81:
            case 'B':
            case 'b':
                bottom();
                selectedOptions[0] = currentOption;

                if (onSelectedChange != NULL)
                    onSelectedChange(selectedOptions[0]);

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 28:
            case 'X':
            case 'x':
                doLoop = false;
                break;

            default:
                if (onUnknownCommand != NULL)
                    onUnknownCommand(key);

                return key * -1;
            }

            draw();
        }

        return selectedOptions[0];
    }


    void singleControl::draw()
    {
        cout << ":)" << endl;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   List Box
    // ##
    
    #pragma region List Box

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    listBox::listBox()
    {
        separator = '-';
    }


    void listBox::setSeparator(char value)
    {
        separator = value;
    }


    char listBox::getSeparator()
    {
        return separator;
    }


    void listBox::draw()
    {
        for (int i = 0; i < getOptionsCount(); i++)
        {
            bool d = true;

            setCursorPosition(getX(), getY() + i);

            if (onDraw != nullptr)
                d = onDraw(i,
                    getOptions()[i],
                    getOptionsState()[i],
                    (i == getCurrentOption()), 
                    (i == getSelectedOption()));

            if (d)
            {
                if (getOptionsState()[i])
                {
                    if (i == getSelectedOption())
                    {
                        if (i == getCurrentOption())
                        {
                            cout << sFC(getCurrentOptionForeColor());
                            cout << sBC(getCurrentOptionBackColor());
                        }
                        else
                        {
                            cout << sFC(getSelectedOptionForeColor());
                            cout << sBC(getSelectedOptionBackColor());
                        }
                    }
                    else if (i == getCurrentOption())
                    {
                        cout << sFC(getCurrentOptionForeColor());
                        cout << sBC(getCurrentOptionBackColor());
                    }
                    else
                    {
                        cout << sFC(getOptionForeColor());
                        cout << sBC(getOptionBackColor());
                    }
                }
                else
                {
                    cout << sFC(getDisabledOptionForeColor());
                    cout << sBC(getDisabledOptionBackColor());
                }

                cout << getOptions()[i];
            }
        }
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Single Control
    // ##

    #pragma region Single Control

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void multiControl::setX(unsigned value)
    {
        x = value;
    }


    unsigned multiControl::getX()
    {
        return x;
    }


    void multiControl::setY(unsigned value)
    {
        y = value;
    }


    unsigned multiControl::getY()
    {
        return y;
    }


    void multiControl::setOptions(string* value)
    {
        options = value;
    }


    string* multiControl::getOptions()
    {
        return options;
    }


    void multiControl::setOptionsState(bool* value)
    {
        optionsState = value;
    }


    bool* multiControl::getOptionsState()
    {
        return optionsState;
    }


    void multiControl::setSelectedOptions(int* value)
    {
        selectedOptions = value;
    }


    int* multiControl::getSelectedOptions()
    {
        return selectedOptions;
    }


    void multiControl::setCurrentOption(int value)
    {
        currentOption = value;
    }


    int multiControl::getCurrentOption()
    {
        return currentOption;
    }


    void multiControl::setOptionsCount(int value)
    {
        optionsCount = value;
    }


    int multiControl::getOptionsCount()
    {
        return optionsCount;
    }


    void multiControl::setOptionForeColor(RGBCOLOR value)
    {
        optionForeColor = value;
    }


    RGBCOLOR multiControl::getOptionForeColor()
    {
        return optionForeColor;
    }


    void multiControl::setOptionBackColor(RGBCOLOR value)
    {
        optionBackColor = value;
    }


    RGBCOLOR multiControl::getOptionBackColor()
    {
        return optionBackColor;
    }


    void multiControl::setSelectedOptionForeColor(RGBCOLOR value)
    {
        selectedOptionForeColor = value;
    }


    RGBCOLOR multiControl::getSelectedOptionForeColor()
    {
        return selectedOptionForeColor;
    }


    void multiControl::setSelectedOptionBackColor(RGBCOLOR value)
    {
        selectedOptionBackColor = value;
    }


    RGBCOLOR multiControl::getSelectedOptionBackColor()
    {
        return selectedOptionBackColor;
    }


    void multiControl::setCurrentOptionForeColor(RGBCOLOR value)
    {
        currentOptionForeColor = value;
    }


    RGBCOLOR multiControl::getCurrentOptionForeColor()
    {
        return currentOptionForeColor;
    }


    void multiControl::setCurrentOptionBackColor(RGBCOLOR value)
    {
        currentOptionBackColor = value;
    }


    RGBCOLOR multiControl::getCurrentOptionBackColor()
    {
        return currentOptionBackColor;
    }


    void multiControl::setDisabledOptionForeColor(RGBCOLOR value)
    {
        disabledOptionForeColor = value;
    }


    RGBCOLOR multiControl::getDisabledOptionForeColor()
    {
        return disabledOptionForeColor;
    }


    void multiControl::setDisabledOptionBackColor(RGBCOLOR value)
    {
        disabledOptionBackColor = value;
    }


    RGBCOLOR multiControl::getDisabledOptionBackColor()
    {
        return disabledOptionBackColor;
    }


    multiControl::multiControl()
    {
        x = defaultX;
        y = defaultY;
        options = NULL;
        optionsState = NULL;
        selectedOptions = new int[1];
        currentOption = 1;
        optionsCount = 0;
        optionForeColor = rgbFrom(240);
        optionBackColor = rgbFrom(12);
        selectedOptionForeColor = rgbFrom(65, 130, 115);
        selectedOptionBackColor = rgbFrom(40, 80, 70);
        currentOptionForeColor = rgbFrom(10, 70, 125);
        currentOptionBackColor = rgbFrom(35, 170, 240);
        disabledOptionForeColor = rgbFrom(120);
        disabledOptionBackColor = rgbFrom(12);
    }


    multiControl::~multiControl()
    {
        // delete options;
        // delete optionsState;
        // delete selectedOptions;
    }


    int* multiControl::call()
    {
        if (onCallStart != nullptr)
            onCallStart();

        cursorVisible(false);

        draw();

        int* R = loop();

        cursorVisible(true);

        cout << sgr(SGR_DEFAULT);

        if (onCallEnd != nullptr)
            onCallEnd();

        return R;
    }


    void multiControl::up()
    {
        if (currentOption - 1 >= 0)
            currentOption--;
        else
            currentOption = optionsCount - 1;

        while (!optionsState[currentOption])
        {
            if (currentOption - 1 >= 0)
                currentOption--;
            else
                currentOption = optionsCount - 1;
        }
    }


    void multiControl::down()
    {
        if (currentOption + 1 <= optionsCount - 1)
            currentOption++;
        else
            currentOption = 0;

        while (!optionsState[currentOption])
        {
            if (currentOption + 1 <= optionsCount - 1)
                currentOption++;
            else
                currentOption = 0;
        }
    }


    void multiControl::top()
    {
        currentOption = 0;

        while (!optionsState[currentOption])
            currentOption++;
    }


    void multiControl::bottom()
    {
        currentOption = optionsCount - 1;

        while (!optionsState[currentOption])
            currentOption--;
    }


    int* multiControl::loop()
    {
        bool doLoop = true;

        while (doLoop)
        {
            char key = _getch();

            if (key == '\xE0')
            {
                key = _getch();
            }

            switch (key)
            {
            case 72:
            case 'W':
            case 'w':
                up();

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 80:
            case 'S':
            case 's':
                down();

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 73:
            case 'T':
            case 't':
                top();

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 81:
            case 'B':
            case 'b':
                bottom();

                if (onCurrentChange != NULL)
                    onCurrentChange(currentOption);

                break;

            case 75:
            case 'A':
            case 'a':
                selectedOptions[currentOption] = false;

                if (onSelectedChange != NULL)
                    onSelectedChange(selectedOptions[0]);

                break;

            case 77:
            case 'D':
            case 'd':
                selectedOptions[currentOption] = true;

                if (onSelectedChange != NULL)
                    onSelectedChange(selectedOptions[0]);

                break;

            case 28:
            case 'X':
            case 'x':
                doLoop = false;
                break;

            default:
                if (onUnknownCommand != NULL)
                    onUnknownCommand(key);

                return new int { key * -1 };
            }

            draw();
        }

        return selectedOptions;
    }


    void multiControl::draw()
    {
        cout << ":)";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Check List Box
    // ##

    #pragma region Check List Box

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    checkListBox::checkListBox()
    {
        separator = '-';
    }


    void checkListBox::setSeparator(char value)
    {
        separator = value;
    }


    char checkListBox::getSeparator()
    {
        return separator;
    }


    void checkListBox::draw()
    {
        for (int i = 0; i < getOptionsCount(); i++)
        {
            bool d = true;

            setCursorPosition(getX(), getY() + i);

            if (onDraw != nullptr)
                d = onDraw(i,
                    getOptions()[i],
                    getOptionsState()[i],
                    getSelectedOptions()[i],
                    (i == getCurrentOption()));

            if (d)
            {
                if (getOptionsState()[i])
                {
                    if (getSelectedOptions()[i])
                    {
                        if (i == getCurrentOption())
                        {
                            cout << sFC(getCurrentOptionForeColor());
                            cout << sBC(getCurrentOptionBackColor());
                        }
                        else
                        {
                            cout << sFC(getSelectedOptionForeColor());
                            cout << sBC(getSelectedOptionBackColor());
                        }
                    }
                    else if (i == getCurrentOption())
                    {
                        cout << sFC(getCurrentOptionForeColor());
                        cout << sBC(getCurrentOptionBackColor());
                    }
                    else
                    {
                        cout << sFC(getOptionForeColor());
                        cout << sBC(getOptionBackColor());
                    }
                }
                else
                {
                    cout << sFC(getDisabledOptionForeColor());
                    cout << sBC(getDisabledOptionBackColor());
                }

                if (getOptions()[i][0] != separator)
                {
                    if (getSelectedOptions()[i])
                    {
                        cout << " ( * ) ";
                    }
                    else
                    {
                        cout << " (   ) ";
                    }
                }

                cout << getOptions()[i];
            }       
        }
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion

    #endif
}
