//
//  VTSEd
//
//  Migliora la tua Applicazione Console C++!
//
//  Questo File fa Parte del Progetto VTSEd
//  ed è Distribuito sotto Licenza MIT.
//
//  GitHub:      https://github.com/reallukee/vtsed/
//  Autore:      Luca Pollicino
//  Descrizione: DINAMIC CONTROL
//               Questo File Contiene le Implementazioni
//               Relative ai Controlli Dinamici.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#include "pch.hpp"          // Intestazioni Precompilate.

#include "dcontrols.hpp"    // Header di Riferimento.

#pragma endregion


namespace vtsed
{

#ifdef WIN  // WIN

    // ##
    // ##   Single Control
    // ##

    #pragma region Single Control

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void SingleControl::setX(unsigned value)
    {
        x = value;
    }

    unsigned SingleControl::getX()
    {
        return x;
    }

    void SingleControl::setY(unsigned value)
    {
        y = value;
    }

    unsigned SingleControl::getY()
    {
        return y;
    }



    void SingleControl::setOptions(string* value)
    {
        options = value;
    }

    string* SingleControl::getOptions()
    {
        return options;
    }

    void SingleControl::setOptionsState(bool* value)
    {
        optionsState = value;
    }

    bool* SingleControl::getOptionsState()
    {
        return optionsState;
    }

    void SingleControl::setSelectedOption(int value)
    {
        selectedOptions[0] = value;
    }

    int SingleControl::getSelectedOption()
    {
        return selectedOptions[0];
    }



    void SingleControl::setCurrentOption(int value)
    {
        currentOption = value;
    }

    int SingleControl::getCurrentOption()
    {
        return currentOption;
    }



    void SingleControl::setOptionsCount(int value)
    {
        optionsCount = value;
    }

    int SingleControl::getOptionsCount()
    {
        return optionsCount;
    }



    void SingleControl::setOptionForeColor(RGBCOLOR value)
    {
        optionForeColor = value;
    }

    RGBCOLOR SingleControl::getOptionForeColor()
    {
        return optionForeColor;
    }

    void SingleControl::setOptionBackColor(RGBCOLOR value)
    {
        optionBackColor = value;
    }

    RGBCOLOR SingleControl::getOptionBackColor()
    {
        return optionBackColor;
    }

    void SingleControl::setSelectedOptionForeColor(RGBCOLOR value)
    {
        selectedOptionForeColor = value;
    }

    RGBCOLOR SingleControl::getSelectedOptionForeColor()
    {
        return selectedOptionForeColor;
    }

    void SingleControl::setSelectedOptionBackColor(RGBCOLOR value)
    {
        selectedOptionBackColor = value;
    }

    RGBCOLOR SingleControl::getSelectedOptionBackColor()
    {
        return selectedOptionBackColor;
    }

    void SingleControl::setCurrentOptionForeColor(RGBCOLOR value)
    {
        currentOptionForeColor = value;
    }

    RGBCOLOR SingleControl::getCurrentOptionForeColor()
    {
        return currentOptionForeColor;
    }

    void SingleControl::setCurrentOptionBackColor(RGBCOLOR value)
    {
        currentOptionBackColor = value;
    }

    RGBCOLOR SingleControl::getCurrentOptionBackColor()
    {
        return currentOptionBackColor;
    }

    void SingleControl::setDisabledOptionForeColor(RGBCOLOR value)
    {
        disabledOptionForeColor = value;
    }

    RGBCOLOR SingleControl::getDisabledOptionForeColor()
    {
        return disabledOptionForeColor;
    }

    void SingleControl::setDisabledOptionBackColor(RGBCOLOR value)
    {
        disabledOptionBackColor = value;
    }

    RGBCOLOR SingleControl::getDisabledOptionBackColor()
    {
        return disabledOptionBackColor;
    }



    int SingleControl::firstIndex()
    {
        return 0;
    }

    int SingleControl::lastIndex()
    {
        return optionsCount - 1;
    }



    void SingleControl::setAllowInterruption(bool value)
    {
        allowInterruption = value;
    }

    bool SingleControl::getAllowInterruption()
    {
        return allowInterruption;
    }



    SingleControl::SingleControl()
    {
        x = DEFAULTX;
        y = DEFAULTY;

        optionsCount = 0;

        options = NULL;
        optionsState = NULL;
        selectedOptions = new int[1];

        currentOption = 1;

        allowInterruption = false;

        optionForeColor = rgbFrom(240);
        optionBackColor = rgbFrom(12);
        selectedOptionForeColor = rgbFrom(65, 130, 115);
        selectedOptionBackColor = rgbFrom(40, 80, 70);
        currentOptionForeColor = rgbFrom(10, 70, 125);
        currentOptionBackColor = rgbFrom(35, 170, 240);
        disabledOptionForeColor = rgbFrom(120);
        disabledOptionBackColor = rgbFrom(12);
    }

    SingleControl::~SingleControl()
    {
        // delete options;
        // delete optionsState;
        // delete selectedOptions;
    }



    int SingleControl::call()
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

    void SingleControl::up()
    {
        if (optionsCount <= 0)
            return;

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

    void SingleControl::down()
    {
        if (optionsCount <= 0)
            return;

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

    void SingleControl::top()
    {
        if (optionsCount <= 0)
            return;

        currentOption = 0;

        while (!optionsState[currentOption])
            currentOption++;
    }

    void SingleControl::bottom()
    {
        if (optionsCount <= 0)
            return;

        currentOption = optionsCount - 1;

        while (!optionsState[currentOption])
            currentOption--;
    }

    int SingleControl::loop()
    {
        bool doLoop = true;

        char key;

        while (doLoop)
        {
            key = _getch();

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

            case 74:
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

            case 27:
            case 'Q':
            case 'q':
                if (allowInterruption)
                    doLoop = false;

                break;

            default:
                if (onUnknownCommand != NULL)
                    onUnknownCommand(key);

                if (allowInterruption)
                    return key * -1;

                break;
            }

            if (onKnownCommand != NULL)
                onKnownCommand(key);

            draw();
        }

        if (key == INTERRUPTCALLCOMMAND)
            return INTERRUPTIONCODE;
        
        return selectedOptions[0];
    }

    void SingleControl::draw()
    {
        cout << ":)";
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

    ListBox::ListBox()
    {
        separator = '-';
    }



    void ListBox::setSeparator(char value)
    {
        separator = value;
    }

    char ListBox::getSeparator()
    {
        return separator;
    }



    void ListBox::draw()
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

    void MultiControl::setX(unsigned value)
    {
        x = value;
    }

    unsigned MultiControl::getX()
    {
        return x;
    }

    void MultiControl::setY(unsigned value)
    {
        y = value;
    }

    unsigned MultiControl::getY()
    {
        return y;
    }



    void MultiControl::setOptions(string* value)
    {
        options = value;
    }

    string* MultiControl::getOptions()
    {
        return options;
    }

    void MultiControl::setOptionsState(bool* value)
    {
        optionsState = value;
    }

    bool* MultiControl::getOptionsState()
    {
        return optionsState;
    }

    void MultiControl::setSelectedOptions(int* value)
    {
        selectedOptions = value;
    }

    int* MultiControl::getSelectedOptions()
    {
        return selectedOptions;
    }



    void MultiControl::setCurrentOption(int value)
    {
        currentOption = value;
    }

    int MultiControl::getCurrentOption()
    {
        return currentOption;
    }



    void MultiControl::setOptionsCount(int value)
    {
        optionsCount = value;
    }

    int MultiControl::getOptionsCount()
    {
        return optionsCount;
    }



    void MultiControl::setOptionForeColor(RGBCOLOR value)
    {
        optionForeColor = value;
    }

    RGBCOLOR MultiControl::getOptionForeColor()
    {
        return optionForeColor;
    }

    void MultiControl::setOptionBackColor(RGBCOLOR value)
    {
        optionBackColor = value;
    }

    RGBCOLOR MultiControl::getOptionBackColor()
    {
        return optionBackColor;
    }

    void MultiControl::setSelectedOptionForeColor(RGBCOLOR value)
    {
        selectedOptionForeColor = value;
    }

    RGBCOLOR MultiControl::getSelectedOptionForeColor()
    {
        return selectedOptionForeColor;
    }

    void MultiControl::setSelectedOptionBackColor(RGBCOLOR value)
    {
        selectedOptionBackColor = value;
    }

    RGBCOLOR MultiControl::getSelectedOptionBackColor()
    {
        return selectedOptionBackColor;
    }

    void MultiControl::setCurrentOptionForeColor(RGBCOLOR value)
    {
        currentOptionForeColor = value;
    }

    RGBCOLOR MultiControl::getCurrentOptionForeColor()
    {
        return currentOptionForeColor;
    }

    void MultiControl::setCurrentOptionBackColor(RGBCOLOR value)
    {
        currentOptionBackColor = value;
    }

    RGBCOLOR MultiControl::getCurrentOptionBackColor()
    {
        return currentOptionBackColor;
    }

    void MultiControl::setDisabledOptionForeColor(RGBCOLOR value)
    {
        disabledOptionForeColor = value;
    }

    RGBCOLOR MultiControl::getDisabledOptionForeColor()
    {
        return disabledOptionForeColor;
    }

    void MultiControl::setDisabledOptionBackColor(RGBCOLOR value)
    {
        disabledOptionBackColor = value;
    }

    RGBCOLOR MultiControl::getDisabledOptionBackColor()
    {
        return disabledOptionBackColor;
    }



    int MultiControl::firstIndex()
    {
        return 0;
    }

    int MultiControl::lastIndex()
    {
        return optionsCount - 1;
    }



    void MultiControl::setAllowInterruption(bool value)
    {
        allowInterruption = value;
    }

    bool MultiControl::getAllowInterruption()
    {
        return allowInterruption;
    }



    MultiControl::MultiControl()
    {
        x = DEFAULTX;
        y = DEFAULTY;

        optionsCount = 0;

        options = NULL;
        optionsState = NULL;
        selectedOptions = new int[1];

        currentOption = 1;

        allowInterruption = false;

        optionForeColor = rgbFrom(240);
        optionBackColor = rgbFrom(12);
        selectedOptionForeColor = rgbFrom(65, 130, 115);
        selectedOptionBackColor = rgbFrom(40, 80, 70);
        currentOptionForeColor = rgbFrom(10, 70, 125);
        currentOptionBackColor = rgbFrom(35, 170, 240);
        disabledOptionForeColor = rgbFrom(120);
        disabledOptionBackColor = rgbFrom(12);
    }

    MultiControl::~MultiControl()
    {
        // delete options;
        // delete optionsState;
        // delete selectedOptions;
    }



    int* MultiControl::call()
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

    void MultiControl::up()
    {
        if (optionsCount <= 0)
            return;

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

    void MultiControl::down()
    {
        if (optionsCount <= 0)
            return;

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

    void MultiControl::top()
    {
        if (optionsCount <= 0)
            return;

        currentOption = 0;

        while (!optionsState[currentOption])
            currentOption++;
    }

    void MultiControl::bottom()
    {
        if (optionsCount <= 0)
            return;

        currentOption = optionsCount - 1;

        while (!optionsState[currentOption])
            currentOption--;
    }

    int* MultiControl::loop()
    {
        bool doLoop = true;

        char key;

        while (doLoop)
        {
            key = _getch();

            if (key == '\xE0')
                key = _getch();

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

            case 74:
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

            case 27:
            case 'Q':
            case 'q':
                if (allowInterruption)
                    doLoop = false;

            default:
                if (onUnknownCommand != NULL)
                    onUnknownCommand(key);

                if (allowInterruption)
                    return new int { key * -1 };

                break;
            }

            if (onKnownCommand != NULL)
                onKnownCommand(key);

            draw();
        }

        if (key == INTERRUPTCALLCOMMAND)
            return new int[1] { INTERRUPTIONCODE };

        return selectedOptions;
    }

    void MultiControl::draw()
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

    CheckListBox::CheckListBox()
    {
        separator = '-';
    }



    void CheckListBox::setSeparator(char value)
    {
        separator = value;
    }

    char CheckListBox::getSeparator()
    {
        return separator;
    }



    void CheckListBox::draw()
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

#endif  // ! WIN

}
