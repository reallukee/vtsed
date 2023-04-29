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
//  Descrizione: VTS
//               Questo Header Contiene le Implementazioni
//               Relative a VTS.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#include "pch.hpp"  // Intestazioni Precompilate.

#include "vts.hpp"  // Header di Riferimento.

#pragma endregion


namespace vtsed
{
    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    bool initConsole()
    {
        if (!enableVTS())
        {
            return false;
        }

        sgr(SGR_DEFAULT);
        return true;
    }


    bool dinitConsole()
    {
        if (!enableVTS())
        {
            return false;
        }

        sgr(SGR_DEFAULT);
        return true;
    }


    bool enableVTS()
    {
        // Solo su Windows è necessario abilitare
        // le VTS tramite la modifica del comportamento
        // della sessione corrente del terminale.

#ifdef WIN  // WIN

        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        if (hOut == INVALID_HANDLE_VALUE)
        {
            return false;
        }

        // Ottengo la modalità della console.
        DWORD dwMode = 0;

        if (!GetConsoleMode(hOut, &dwMode))
        {
            return false;
        }

        // Imposto la modalità della console.
        dwMode |= 0x0004 | 0x0008;

        if (!SetConsoleMode(hOut, dwMode))
        {
            return false;
        }

#endif  // ! WIN

        return true;
    }


    bool disableVTS()
    {
        // Solo su Windows è necessario disabilitare
        // le VTS tramite la modifica del comportamento
        // della sessione corrente del terminale.

#ifdef WIN  // WIN

        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        if (hOut == INVALID_HANDLE_VALUE)
        {
            return false;
        }

        // Ottengo la modalità della console.
        DWORD dwMode = 0;

        if (!GetConsoleMode(hOut, &dwMode))
        {
            return false;
        }

        // Imposto la modalità della console.
        dwMode &= ~0x0004 & ~0x0008;

        if (!SetConsoleMode(hOut, dwMode))
        {
            return false;
        }

#endif  // ! WIN

        return true;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Simple Cursor Positioning
    // ##

    #pragma region Simple Cursor Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string reverseCursorIndex()
    {
        return "\x1b[M";
    }


    void _reverseCursorIndex()
    {
        cout << reverseCursorIndex();
    }


    string saveCursor()
    {
        return "\x1b[7";
    }


    void _saveCursor()
    {
        cout << saveCursor();
    }


    string restoreCursor()
    {
        return "\x1b[8";
    }


    void _restoreCursor()
    {
        cout << restoreCursor();
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

    string cursorUp(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "A";
        return ss.str();
    }


    void _cursorUp(unsigned n)
    {
        cout << cursorUp(n);
    }


    string cursorDown(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "B";
        return ss.str();
    }


    void _cursorDown(unsigned n)
    {
        cout << cursorDown(n);
    }


    string cursorRight(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "C";
        return ss.str();
    }


    void _cursorRight(unsigned n)
    {
        cout << cursorRight(n);
    }


    string cursorLeft(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "D";
        return ss.str();
    }


    void _cursorLeft(unsigned n)
    {
        cout << cursorLeft(n);
    }


    string cursorUpLine(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "E";
        return ss.str();
    }


    void _cursorUpLine(unsigned n)
    {
        cout << cursorUpLine(n);
    }


    string cursorPreviousLine(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "F";
        return ss.str();
    }


    void _cursorPreviousLine(unsigned n)
    {
        cout << cursorPreviousLine(n);
    }


    string cursorHorizontalAbs(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "G";
        return ss.str();
    }


    void _cursorHorizontalAbs(unsigned n)
    {
        cout << cursorHorizontalAbs(n);
    }


    string cursorVerticalAbs(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "d";
        return ss.str();
    }


    void _cursorVerticalAbs(unsigned n)
    {
        cout << cursorVerticalAbs(n);
    }


    string setCursorPositionCUP(unsigned x, unsigned y)
    {
        stringstream ss;
        ss << "\x1b[" << y << ";" << x << "H";
        return ss.str();
    }


    void _setCursorPositionCUP(unsigned x, unsigned y)
    {
        cout << setCursorPositionCUP(x, y);
    }


    string setCursorPositionCUP()
    {
        return "\x1b[;H";
    }


    void _setCursorPositionCUP()
    {
        cout << setCursorPositionCUP();
    }


    string setCursorPositionHVP(unsigned x, unsigned y)
    {
        stringstream ss;
        ss << "\x1b[" << y << ";" << x << "f";
        return ss.str();
    }


    void _setCursorPositionHVP(unsigned x, unsigned y)
    {
        cout << setCursorPositionHVP(x, y);
    }


    string setCursorPositionHVP()
    {
        return "\x1b[;f";
    }


    void _setCursorPositionHVP()
    {
        cout << setCursorPositionHVP();
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

    string cursorBlinking(bool value)
    {
        if (value)
        {
            return "\x1b[?12h";
        }
        else
        {
            return "\x1b[?12l";
        }
    }


    void _cursorBlinking(bool value)
    {
        cout << cursorBlinking(value);
    }


    string cursorVisible(bool value)
    {
        if (value)
        {
            return "\x1b[?25h";
        }
        else
        {
            return "\x1b[?25l";
        }
    }


    void _cursorVisible(bool value)
    {
        cout << cursorVisible(value);
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

    string cursorShape(unsigned c)
    {
        stringstream ss;

        if (c >= 0 && c <= 6)
        {
            ss << "\x1b[" << c << "\x20q";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _cursorShape(unsigned c)
    {
        cout << cursorShape(c);
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

    string scrollUp(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "S";
        return ss.str();
    }


    void _scrollUp(unsigned n)
    {
        cout << scrollUp(n);
    }


    string scrollUp()
    {
        return "\x1b[S";
    }


    void _scrollUp()
    {
        cout << scrollUp();
    }


    string scrollDown(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "T";
        return ss.str();
    }


    void _scrollDown(unsigned n)
    {
        cout << scrollDown(n);
    }


    string scrollDown()
    {
        return "\x1b[T";
    }


    void _scrollDown()
    {
        cout << scrollDown();
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

    string insertCharacter(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "@";
        return ss.str();
    }


    void _insertCharacter(unsigned n)
    {
        cout << insertCharacter(n);
    }


    string deleteCharacter(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "X";
        return ss.str();
    }


    void _deleteCharacter(unsigned n)
    {
        cout << deleteCharacter(n);
    }


    string eraseCharacter(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "X";
        return ss.str();
    }


    void _eraseCharacter(unsigned n)
    {
        cout << eraseCharacter(n);
    }


    string insertLine(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "L";
        return ss.str();
    }


    void _insertLine(unsigned n)
    {
        cout << "\x1b[" << n << "L";
    }


    string deleteLine(unsigned n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "M";
        return ss.str();
    }


    void _deleteLine(unsigned n)
    {
        cout << deleteLine(n);
    }


    string eraseInDisplay(unsigned n)
    {
        stringstream ss;

        if (n >= 0 && n <= 2)
        {
            ss << "\x1b[" << n << "J";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _eraseInDisplay(unsigned n)
    {
        cout << eraseInDisplay(n);
    }


    string eraseInDisplay()
    {
        return "\x1b[J";
    }


    void _eraseInDisplay()
    {
        cout << eraseInDisplay();
    }


    string eraseInLine(unsigned n)
    {
        stringstream ss;

        if (n >= 0 && n <= 2)
        {
            ss << "\x1b[" << n << "K";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _eraseInLine(unsigned n)
    {
        cout << eraseInLine(n);
    }


    string eraseInLine()
    {
        return "\x1b[K";
    }


    void _eraseInLine()
    {
        cout << eraseInLine();
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

    string link(string url, string text)
    {
        stringstream ss;
        ss << "\x1b]8;;" << url << "\x1b\\" << text << "\x1b]8;;\x1b\\";
        return ss.str();
    }


    void _link(string url, string text)
    {
        cout << link(url, text);
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

    string setScreenColor(int i, string r, string g, string b)
    {
        stringstream ss;

        if (i >= 0 && i <= 255)
        {
            ss << "\x1b]4;" << i << ";rgb:" << r << "/" << g << "/" << b << "\x1b\x5c";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _setScreenColor(int i, string r, string g, string b)
    {
        cout << setScreenColor(i, r, g, b);
    }


    string setScreenColor(int i, HEXCOLOR color)
    {
        stringstream ss;

        if (i >= 0 && i <= 255)
        {
            ss << "\x1b]4;" << i << ";rgb:" << color.r << "/" << color.g << "/" << color.b << "\x1b\x5c";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _setScreenColor(int i, HEXCOLOR color)
    {
        cout << setScreenColor(i, color);
    }


    string setScreenColor(int i, string color)
    {
        stringstream ss;

        if (i >= 0 && i <= 255)
        {
            ss << "\x1b]4;" << i << ";" << color << "\x1b\x5c";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _setScreenColor(int i, string color)
    {
        cout << setScreenColor(i, color);
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

    string setPalette(const HEXCOLOR color[16])
    {
        stringstream ss;

        for (int i = 0; i < 16; i++)
        {
            ss << setScreenColor(i, color[i]);
        }

        return ss.str();
    }


    void _setPalette(const HEXCOLOR color[16])
    {
        for (int i = 0; i < 16; i++)
        {
            _setScreenColor(i, color[i]);
        }
    }


    string setPalette(const string color[16])
    {
        stringstream ss;

        for (int i = 0; i < 16; i++)
        {
            ss << setScreenColor(i, color[i]);
        }

        return ss.str();
    }


    void _setPalette(const string color[16])
    {
        for (int i = 0; i < 16; i++)
        {
            _setScreenColor(i, color[i]);
        }
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

    string setDefaultForegroundColor(string r, string g, string b)
    {
        stringstream ss;
        ss << "\x1b]10;rgb:" << r << "/" << g << "/" << b << "\x1b\\";
        return ss.str();
    }


    void _setDefaultForegroundColor(string r, string g, string b)
    {
        cout << setDefaultForegroundColor(r, g, b);
    }


    string setDefaultForegroundColor(HEXCOLOR color)
    {
        return setDefaultForegroundColor(color.r, color.g, color.b);
    }


    void _setDefaultForegroundColor(HEXCOLOR color)
    {
        _setDefaultForegroundColor(color.r, color.g, color.b);
    }


    string setDefaultForegroundColor(string color)
    {
        stringstream ss;
        ss << "\x1b]10;" << color << "\x1b\\";
        return ss.str();
    }


    void _setDefaultForegroundColor(string color)
    {
        cout << setDefaultForegroundColor(color);
    }


    string setDefaultBackgroundColor(string r, string g, string b)
    {
        stringstream ss;
        ss << "\x1b]11;rgb:" << r << "/" << g << "/" << b << "\x1b\\";
        return ss.str();
    }


    void _setDefaultBackgroundColor(string r, string g, string b)
    {
        cout << setDefaultBackgroundColor(r, g, b);
    }


    string setDefaultBackgroundColor(HEXCOLOR color)
    {
        return setDefaultBackgroundColor(color.r, color.g, color.b);
    }


    void _setDefaultBackgroundColor(HEXCOLOR color)
    {
        _setDefaultBackgroundColor(color.r, color.g, color.b);
    }


    string setDefaultBackgroundColor(string color)
    {
        stringstream ss;
        ss << "\x1b]11;" << color << "\x1b\\";
        return ss.str();
    }


    void _setDefaultBackgroundColor(string color)
    {
        cout << setDefaultBackgroundColor(color);
    }


    string setDefaultCursorColor(string r, string g, string b)
    {
        stringstream ss;
        ss << "\x1b]12;rgb:" << r << "/" << g << "/" << b << "\x1b\\";
        return ss.str();
    }


    void _setDefaultCursorColor(string r, string g, string b)
    {
        cout << setDefaultCursorColor(r, g, b);
    }


    string setDefaultCursorColor(HEXCOLOR color)
    {
        return setDefaultCursorColor(color.r, color.g, color.b);
    }


    void _setDefaultCursorColor(HEXCOLOR color)
    {
        _setDefaultCursorColor(color.r, color.g, color.b);
    }


    string setDefaultCursorColor(string color)
    {
        stringstream ss;
        ss << "\x1b]12;" << color << "\x1b\\";
        return ss.str();
    }


    void _setDefaultCursorColor(string color)
    {
        cout << setDefaultCursorColor(color);
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
        {
            return "";
        }

        // Le componenti non possono essere maggiori di 255.
        if (r > 255 || g > 255 || b > 255)
        {
            return "";
        }

        stringstream ss;
        ss << "\x1b[38;2;" << r << ";" << g << ";" << b << "m";
        return ss.str();
    }


    void _setForegroundColor(int r, int g, int b)
    {
        cout << setForegroundColor(r, g, b);
    }


    string setForegroundColor(RGBCOLOR color)
    {
        return setForegroundColor(color.r, color.g, color.b);
    }


    void _setForegroundColor(RGBCOLOR color)
    {
        cout << setForegroundColor(color);
    }


    string setForegroundColorById(int id)
    {
        // L'ID non può essere negativo e maggiore di 256.
        if (id < 0 || id > 255)
        {
            return "";
        }

        stringstream ss;
        ss << "\x1b[38;5;" << id << "m";
        return ss.str();
    }


    void _setForegroundColorById(int id)
    {
        cout << setForegroundColorById(id);
    }


    string sFC(int r, int g, int b)
    {
        return setForegroundColor(r, g, b);
    }


    void _sFC(int r, int g, int b)
    {
        cout << sFC(r, g, b);
    }


    string sFC(RGBCOLOR color)
    {
        return setForegroundColor(color.r, color.g, color.b);
    }


    void _sFC(RGBCOLOR color)
    {
        cout << sFC(color);
    }


    string sFCById(int id)
    {
        return setForegroundColorById(id);
    }


    void _sFCById(int id)
    {
        cout << sFCById(id);
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
        {
            return "";
        }

        // Le componenti non possono essere maggiori di 255.
        if (r > 255 || g > 255 || b > 255)
        {
            return "";
        }

        stringstream ss;
        ss << "\x1b[48;2;" << r << ";" << g << ";" << b << "m";
        return ss.str();
    }


    void _setBackgroundColor(int r, int g, int b)
    {
        cout << setBackgroundColor(r, g, b);
    }


    string setBackgroundColor(RGBCOLOR color)
    {
        return setBackgroundColor(color.r, color.g, color.b);
    }


    void _setBackgroundColor(RGBCOLOR color)
    {
        cout << setBackgroundColor(color);
    }


    string setBackgroundColorById(int id)
    {
        // L'ID non può essere negativo e maggiore di 256.
        if (id < 0 || id > 255)
        {
            return "";
        }

        stringstream ss;
        ss << "\x1b[48;5;" << id << "m";
        return ss.str();
    }


    void _setBackgroundColorById(int id)
    {
        cout << setBackgroundColorById(id);
    }


    string sBC(int r, int g, int b)
    {
        return setBackgroundColor(r, g, b);
    }


    void _sBC(int r, int g, int b)
    {
        cout << sBC(r, g, b);
    }


    string sBC(RGBCOLOR color)
    {
        return setBackgroundColor(color.r, color.g, color.b);
    }


    void _sBC(RGBCOLOR color)
    {
        cout << sBC(color);
    }


    string sBCById(int id)
    {
        return setBackgroundColorById(id);
    }


    void _sBCById(int id)
    {
        cout << sBCById(id);
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
        stringstream ss;
        ss << "\x1b[" << c << "m";
        return ss.str();
    }


    void _sgr(unsigned c)
    {
        cout << sgr(c);
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

    string keypadApplicationMode(bool value)
    {
        if (value)
        {
            return "\x1b=";
        }
        else
        {
            return "\x1b>";
        }
    }


    void _keypadApplicationMode(bool value)
    {
        cout << keypadApplicationMode(value);
    }


    string cursorKeysApplicationMode(bool value)
    {
        if (value)
        {
            return "\x1b[?1h";
        }
        else
        {
            return "\x1b[?1l";
        }
    }


    void _cursorKeysApplicationMode(bool value)
    {
        cout << cursorKeysApplicationMode(value);
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

    string reportCursorPosition()
    {
        return "\x1v[6n";
    }


    void _reportCursorPosition()
    {
        cout << reportCursorPosition();
    }


    string deviceAttributes()
    {
        return "\x1b[0c";
    }


    void _deviceAttributes()
    {
        cout << deviceAttributes();
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

    string horizontalTab()
    {
        return "\x1bH";
    }


    void _horizontalTab()
    {
        cout << horizontalTab();
    }


    string cursorForewardsTab(int n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "I";
        return ss.str();
    }


    void _cursorForewardsTab(int n)
    {
        cout << cursorForewardsTab(n);
    }


    string cursorBackwardsTab(int n)
    {
        stringstream ss;
        ss << "\x1b[" << n << "Z";
        return ss.str();
    }


    void _cursorBackwardsTab(int n)
    {
        cout << cursorBackwardsTab(n);
    }


    string tabClearCurrentColumn()
    {
        return "\x1b[0g";
    }


    void _tabClearCurrentColumn()
    {
        cout << tabClearCurrentColumn();
    }


    string tabClearAllColumns()
    {
        return "\x1b[3g";
    }


    void _tabClearAllColumns()
    {
        cout << tabClearAllColumns();
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

    string designateCharacter(bool value)
    {
        if (value)
        {
            return "\x1b(0";
        }
        else
        {
            return "\x1b(B";
        }
    }


    void _designateCharacter(bool value)
    {
        cout << designateCharacter(value);
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

    string scrollingMargin(int t, int b)
    {
        stringstream ss;
        ss << "\x1b[" << t << ";" << b << "r";
        return ss.str();
    }


    void _scrollingMargin(int t, int b)
    {
        cout << scrollingMargin(t, b);
    }


    string scrollingMargin()
    {
        return "\x1b[;r";
    }


    void _scrollingMargin()
    {
        cout << scrollingMargin();
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

    string windowTitle(string value)
    {
        stringstream ss;

        if (value.size() < 256)
        {
            ss << "\x1b]0;" << value << "\x5c";
        }
        else
        {
            ss << "";
        }

        return ss.str();
    }


    void _windowTitle(string value)
    {
        if (value.size() < 256)
        {
            cout << "\x1b]0;" << value << "\x5c";
        }
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

    string alternateScreenBuffer(bool value)
    {
        if (value)
        {
            return "\x1b[?1049h";
        }
        else
        {
            return "\x1b[?1049l";
        }
    }


    void _alternateScreenBuffer(bool value)
    {
        cout << alternateScreenBuffer(value);
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

    string windowWidth(bool value)
    {
        if (value)
        {
            return "\x1b[?3h";
        }
        else
        {
            return "\x1b[?3l";
        }
    }


    void _windowWidth(bool value)
    {
        cout << windowWidth(value);
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

    string softReset()
    {
        return "\x1b[!p";
    }


    void _softReset()
    {
        cout << softReset();
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
