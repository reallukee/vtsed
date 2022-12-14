//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    VTS
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

#include "pch.hpp"

#include "vts.hpp"

namespace vtsed
{
    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64

    bool initConsole()
    {
        if (!enableVTS())
            return false;

        sgr(SGR_DEFAULT);
        return true;
    }


    bool dinitConsole()
    {
        if (!enableVTS())
            return false;

        sgr(SGR_DEFAULT);
        return true;
    }


    bool enableVTS()
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE)
            return false;

        // Ottengo la modalità della console.
        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode))
            return false;

        // Imposto la modalità della console.
        dwMode |= 0x0004 | 0x0008;
        if (!SetConsoleMode(hOut, dwMode))
            return false;

        return true;
    }


    bool disableVTS()
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE)
            return false;

        // Ottengo la modalità della console.
        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode))
            return false;

        // Imposto la modalità della console.
        dwMode &= ~0x0004 & ~0x0008;
        if (!SetConsoleMode(hOut, dwMode))
            return false;

        return true;
    }

    #endif  // _WIN32 || _WIN64

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Simple Cursor Positioning
    // ##

    #pragma region Simple Cursor Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void reverseCursorIndex()
    {
        cout << "\x1b[M";
    }


    void saveCursor()
    {
        cout << "\x1b[7";
    }


    void restoreCursor()
    {
        cout << "\x1b[8";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion

    
    // ##
    // ##   Cursor Positioning
    // ##

    #pragma region Cursor Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void cursorUp(unsigned n)
    {
        cout << "\x1b[" << n << "A";
    }


    void cursorDown(unsigned n)
    {
        cout << "\x1b[" << n << "B";
    }


    void cursorRight(unsigned n)
    {
        cout << "\x1b[" << n << "C";
    }


    void cursorLeft(unsigned n)
    {
        cout << "\x1b[" << n << "D";
    }


    void cursorUpLine(unsigned n)
    {
        cout << "\x1b[" << n << "E";
    }


    void cursorPreviousLine(unsigned n)
    {
        cout << "\x1b[" << n << "F";
    }


    void cursorHorizontalAbs(unsigned n)
    {
        cout << "\x1b[" << n << "G";
    }


    void cursorVerticalAbs(unsigned n)
    {
        cout << "\x1b[" << n << "d";
    }


    void VTSED_API setCursorPositionCUP()
    {
        cout << "\x1b[;H";
    }


    void setCursorPositionCUP(unsigned x, unsigned y)
    {
        cout << "\x1b[" << y << ";" << x << "H";
    }


    void VTSED_API setCursorPositionHVP()
    {
        cout << "\x1b[;f";
    }


    void setCursorPositionHVP(unsigned x, unsigned y)
    {
        cout << "\x1b[" << y << ";" << x << "f";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Cursor Visibility
    // ##

    #pragma region Cursor Visibility

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void cursorBlinking(bool value)
    {
        if (value)
            cout << "\x1b[?12h";
        else
            cout << "\x1b[?12l";
    }


    void cursorVisible(bool value)
    {
        if (value)
            cout << "\x1b[?25h";
        else
            cout << "\x1b[?25l";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Cursor Shape
    // ##

    #pragma region Cursor Shape

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void cursorShape(unsigned c)
    {
        if (c >= 0 && c <= 6)
            cout << "\x1b[" << c << "\x20q";
        else
            cout << "";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Viewport Positioning
    // ##

    #pragma region Viewport Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void scrollUp()
    {
        cout << "\x1b[S";
    }


    void scrollUp(unsigned n)
    {
        cout << "\x1b[" << n << "S";
    }


    void scrollDown()
    {
        cout << "\x1b[T";
    }


    void scrollDown(unsigned n)
    {
        cout << "\x1b[" << n << "T";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Text Modification
    // ##

    #pragma region Text Modification

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void insertCharacter(unsigned n)
    {
        cout << "\x1b[" << n << "@";
    }


    void deleteCharacter(unsigned n)
    {
        cout << "\x1b[" << n << "P";
    }


    void eraseCharacter(unsigned n)
    {
        cout << "\x1b[" << n << "X";
    }


    void insertLine(unsigned n)
    {
        cout << "\x1b[" << n << "L";
    }


    void deleteLine(unsigned n)
    {
        cout << "\x1b[" << n << "M";
    }


    void eraseInDisplay()
    {
        cout << "\x1b[J";
    }


    void eraseInDisplay(unsigned n)
    {
        if (n >= 0 && n <= 2)
            cout << "\x1b[" << n << "J";
    }


    void eraseInLine()
    {
        cout << "\x1b[K";
    }


    void eraseInLine(unsigned n)
    {
        if (n >= 0 && n <= 2)
            cout << "\x1b[" << n << "K";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Link
    // ##

    #pragma region "Link"

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void link(string link, string text)
    {
        cout << "\x1b]8;;" << link << "\x1b\\" << text << "\x1b]8;;\x1b\\";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Screen Color
    // ##

    #pragma region Screen Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setScreenColor(int i, string r, string g, string b)
    {
        if (i >= 0 && i <= 255)
            cout << "\x1b]4;" << i << ";rgb:" << r << "/" << g << "/" << b << "\x1b\x5c";
    }


    void setScreenColor(int i, HEXCOLOR color)
    {
        if (i >= 0 && i <= 255)
            cout << "\x1b]4;" << i << ";rgb:" << color.r << "/" << color.g << "/" << color.b << "\x1b\x5c";
    }


    void setScreenColor(int i, string color)
    {
        if (i >= 0 && i <= 255)
            cout << "\x1b]4;" << i << ";" << color << "\x1b\x5c";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Palette
    // ##

    #pragma region "Palette"

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setPalette(const HEXCOLOR color[16])
    {
        for (int i = 0; i < 16; i++)
            setScreenColor(i, color[i]);
    }


    void setPalette(const string color[16])
    {
        for (int i = 0; i < 16; i++)
            setScreenColor(i, color[i]);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Default Colors
    // ##

    #pragma region "Default Colors"

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setDefaultForegroundColor(string r, string g, string b)
    {
        cout << "\x1b]10;rgb:" << r << "/" << g << "/" << b << "\x1b\\";
    }


    void setDefaultForegroundColor(HEXCOLOR color)
    {
        setDefaultForegroundColor(color.r, color.g, color.b);
    }


    void setDefaultForegroundColor(string color)
    {
        cout << "\x1b]10;" << color << "\x1b\\";
    }


    void setDefaultBackgroundColor(string r, string g, string b)
    {
        cout << "\x1b]11;rgb:" << r << "/" << g << "/" << b << "\x1b\\";
    }


    void setDefaultBackgroundColor(HEXCOLOR color)
    {
        setDefaultBackgroundColor(color.r, color.g, color.b);
    }


    void setDefaultBackgroundColor(string color)
    {
        cout << "\x1b]11;" << color << "\x1b\\";
    }


    void setDefaultCursorColor(string r, string g, string b)
    {
        cout << "\x1b]12;rgb:" << r << "/" << g << "/" << b << "\x1b\\";
    }


    void setDefaultCursorColor(HEXCOLOR color)
    {
        setDefaultCursorColor(color.r, color.g, color.b);
    }


    void setDefaultCursorColor(string color)
    {
        cout << "\x1b]12;" << color << "\x1b\\";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Foreground Color
    // ##

    #pragma region Foreground Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string setForegroundColor(int r, int g, int b)
    {
        // Le componenti non possono essere negative.
        if (r < 0 || g < 0 || b < 0)
            return "";

        // Le componenti non possono essere maggiori di 255.
        if (r > 255 || g > 255 || b > 255)
            return "";

        stringstream t;
        t << "\x1b[38;2;" << r << ";" << g << ";" << b << "m";
        return t.str();
    }


    string setForegroundColor(RGBCOLOR color)
    {
        return setForegroundColor(color.r, color.g, color.b);
    }


    string setForegroundColorById(int id)
    {
        // L'ID non può essere negativo e maggiore di 256.
        if (id < 0 || id > 255)
            return "";

        stringstream t;
        t << "\x1b[38;5;" << id << "m";
        return t.str();
    }


    string sFC(int r, int g, int b)
    {
        return setForegroundColor(r, g, b);
    }


    string sFC(RGBCOLOR color)
    {
        return setForegroundColor(color.r, color.g, color.b);
    }


    string sFCById(int id)
    {
        return setForegroundColorById(id);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Background Color
    // ##

    #pragma region Background Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string setBackgroundColor(int r, int g, int b)
    {
        // Le componenti non possono essere negative.
        if (r < 0 || g < 0 || b < 0)
            return "";

        // Le componenti non possono essere maggiori di 255.
        if (r > 255 || g > 255 || b > 255)
            return "";

        stringstream t;
        t << "\x1b[48;2;" << r << ";" << g << ";" << b << "m";
        return t.str();
    }


    string setBackgroundColor(RGBCOLOR color)
    {
        return setBackgroundColor(color.r, color.g, color.b);
    }


    string setBackgroundColorById(int id)
    {
        // L'ID non può essere negativo e maggiore di 256.
        if (id < 0 || id > 255)
            return "";

        stringstream t;
        t << "\x1b[48;5;" << id << "m";
        return t.str();
    }


    string sBC(int r, int g, int b)
    {
        return setBackgroundColor(r, g, b);
    }


    string sBC(RGBCOLOR color)
    {
        return setBackgroundColor(color.r, color.g, color.b);
    }


    string sBCById(int id)
    {
        return setBackgroundColorById(id);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SGR
    // ##

    #pragma region SGR

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string sgr(unsigned c)
    {
        stringstream t;
        t << "\x1b[" << c << "m";
        return t.str();
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Mode Changes
    // ##

    #pragma region Mode Changes

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void keypadApplicationMode(bool value)
    {
        if (value)
            cout << "\x1b=";
        else
            cout << "\x1b>";
    }


    void cursorKeysApplicationMode(bool value)
    {
        if (value)
            cout << "\x1b[?1h";
        else
            cout << "\x1b[?1l";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Query State
    // ##

    #pragma region Query State

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void reportCursorPosition()
    {
        cout << "\x1b[6n";
    }


    void deviceAttributes()
    {
        cout << "\x1b[0c";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Tabs
    // ##

    #pragma region Tabs

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void horizontalTab()
    {
        cout << "\x1bH";
    }


    void cursorForwardsTab(int n)
    {
        cout << "\x1b[" << n << "I";
    }


    void cursorBackwardsTab(int n)
    {
        cout << "\x1b[" << n << "Z";
    }


    void tabClearCurrentColumn()
    {
        cout << "\x1b[0g";
    }


    void tabClearAllColumns()
    {
        cout << "\x1b[3g";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Designate Character
    // ##

    #pragma region Designate Character

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void designateCharacter(bool value)
    {
        if (value)
            cout << "\x1b(0";
        else
            cout << "\x1b(B";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Scrolling Margins
    // ##

    #pragma region Scrolling Margin

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void VTSED_API scrollingMargin()
    {
        cout << "\x1b[;r";
    }


    void scrollingMargin(int t, int b)
    {
        cout << "\x1b[" << t << ";" << b << "r";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Window Title
    // ##

    #pragma region Window Title

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void windowTitle(string value)
    {
        if (value.size() < 256)
            cout << "\x1b]0;" << value << "\x5C";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Alternate Screen Buffer
    // ##

    #pragma region Alternate Screen Buffer

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void alternateScreenBuffer(bool value)
    {
        if (value)
            cout << "\x1b[?1049h";
        else
            cout << "\x1b[?1049l";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Window Width
    // ##

    #pragma region Window Width

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void windowWidth(bool value)
    {
        if (value)
            cout << "\x1b[?3h";
        else
            cout << "\x1b[?3l";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Soft Reset
    // ##

    #pragma region Soft Reset

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void softReset()
    {
        cout << "\x1b[!p";
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
