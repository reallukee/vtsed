/*
    VTSEd

    Questo progetto è distribuito sotto licenza MIT.
    Questo progetto è disponibile su GitHub.

    Repository:     https://github.com/reallukee/vtsed/
    Descrizione:    VTS
    Autore:         Realluke (https://github.com/reallukee/)
    Versione:       1.0.0
*/

#pragma once

#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <windows.h>

using namespace std;

namespace vtsed
{
    // ##
    // ##   Structs
    // ##

    #pragma region Structs

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #ifndef RGBCOLOR_STRUCT // RGBCOLOR_STRUCT
    #define RGBCOLOR_STRUCT

    //
    //  RGBCOLOR
    //
    //  Rappresenta un colore a 24bit in formato RGB.
    //

    struct RGBCOLOR
    {
        short r = 0;
        short b = 0;
        short g = 0;

        // Costruttori Struttura.

        RGBCOLOR(short r, short g, short b);
        RGBCOLOR(short c);
        RGBCOLOR();

        // Metodi.

        string toString();
    };

    #endif  // RGBCOLOR_STRUCT


    RGBCOLOR rgbFrom(short r, short g, short b);
    RGBCOLOR rgbFrom(short c);


    #ifndef HEXCOLOR_STRUCT // HEXCOLOR_STRUCT
    #define HEXCOLOR_STRUCT

    //
    //  HEXCOLOR
    //
    //  Rappresenta un colore a 24bit in formato HEX.
    //

    struct HEXCOLOR
    {
        string r = "00";
        string g = "00";
        string b = "00";

        // Costruttori Struttura.

        HEXCOLOR(string r, string g, string b);
        HEXCOLOR(string c);
        HEXCOLOR();

        // Metodi.

        string toString();
    };


    HEXCOLOR hexFrom(string r, string g, string b);
    HEXCOLOR hexFrom(string c);

    #endif  // HEXCOLOR_STRUCT

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void initConsole();
    void dinitConsole();
    bool enableVTS();
    bool disableVTS();

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   CRT
    // ##

    #pragma region CRT

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    // string elaborateCrt(string str);
    // string delaborateCrt(string str);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Simple Cursor Positioning
    // ##

    #pragma region Simple Cursor Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void reverseCursorIndex();
    void saveCursor();
    void restoreCursor();

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Cursor Positioning
    // ##

    #pragma region Cursor Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void cursorUp(int n);
    void cursorDown(int n);
    void cursorRight(int n);
    void cursorLeft(int n);
    void cursorUpLine(int n);
    void cursorPreviousLine(int n);
    void cursorHorizontalAbs(int n);
    void cursorVerticalAbs(int n);
    void setCursorPositionCUP(int x, int y);
    void setCursorPositionHVP(int x, int y);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Cursor Visibility
    // ##

    #pragma region Cursor Visibility

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void cursorBlinking(bool value);
    void cursorVisible(bool value);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Cursor Shape
    // ##

    #pragma region Cursor Shape

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #define CURSOR_SHAPE_USER_SHAPE         0
    #define CURSOR_SHAPE_BLINKING_BLOCK     1
    #define CURSOR_SHAPE_STEADY_BLOCK       2
    #define CURSOR_SHAPE_BLINKING_UNDERLINE 3
    #define CURSOR_SHAPE_STEADY_UNDERLINE   4
    #define CURSOR_SHAPE_BLINKING_BAR       5
    #define CURSOR_SHAPE_STEADY_BAR         6


    void cursorShape(int c);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Viewport Positioning
    // ##

    #pragma region Viewport Positioning

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void scrollUp(int n);
    void scrollDown(int n);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Text Modification
    // ##

    #pragma region Text Modification

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #define TEXT_MODIFICATION_ERASE_FROM_CURRENT 0
    #define TEXT_MODIFICATION_ERASE_FROM_BEGIN   1
    #define TEXT_MODIFICATION_ERASE_ENTIRE       2


    void insertCharacter(int n);
    void deleteCharacter(int n);
    void eraseCharacter(int n);
    void insertLine(int n);
    void deleteLine(int n);
    void eraseInDisplay(int n);
    void eraseInLine(int n);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Screen Color
    // ##

    #pragma region Screen Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #define SCREEN_COLOR_BLACK        0     // Nero
    #define SCREEN_COLOR_DARKBLUE     1     // Blu Scuro
    #define SCREEN_COLOR_DARKGREEN    2     // Verde Scuro
    #define SCREEN_COLOR_DARKCYAN     3     // Ciano Scuro
    #define SCREEN_COLOR_DARKRED      4     // Rosso Scuro
    #define SCREEN_COLOR_DARKMAGENTA  5     // Magenta Scuro
    #define SCREEN_COLOR_DARKYELLOW   6     // Giallo Scuro
    #define SCREEN_COLOR_DARKGRAY     7     // Grigio Scuro
    #define SCREEN_COLOR_GRAY         8     // Grigio
    #define SCREEN_COLOR_BLUE         9     // Blu
    #define SCREEN_COLOR_GREEN        10    // Verde
    #define SCREEN_COLOR_CYAN         11    // Ciano
    #define SCREEN_COLOR_RED          12    // Rosso
    #define SCREEN_COLOR_MAGENTA      13    // Magenta
    #define SCREEN_COLOR_YELLOW       14    // Giallo
    #define SCREEN_COLOR_WHITE        15    // Bianco


    //
    //  Rappresenta una Raccolta di Colori a 16bit
    //  di Windows ConHost
    //

    const HEXCOLOR conhost[16] = {
        hexFrom("12", "12", "12"),
        hexFrom("C5", "0F", "1F"),
        hexFrom("13", "A1", "0E"),
        hexFrom("C1", "9C", "00"),
        hexFrom("00", "37", "DA"),
        hexFrom("88", "17", "98"),
        hexFrom("3A", "96", "DD"),
        hexFrom("CC", "CC", "CC"),
        hexFrom("76", "76", "76"),
        hexFrom("E7", "48", "56"),
        hexFrom("16", "C6", "0C"),
        hexFrom("F9", "F1", "A5"),
        hexFrom("3B", "78", "FF"),
        hexFrom("B4", "00", "9E"),
        hexFrom("61", "D6", "D6"),
        hexFrom("F2", "F2", "F2"),
    };


    //
    //  Rappresenta una Raccolta di Colori a 16bit
    //  Classici
    //

    const HEXCOLOR classic[16] = {
        hexFrom("00", "00", "00"),
        hexFrom("00", "00", "80"),
        hexFrom("00", "80", "00"),
        hexFrom("00", "80", "80"),
        hexFrom("80", "00", "00"),
        hexFrom("80", "00", "80"),
        hexFrom("80", "80", "00"),
        hexFrom("56", "56", "56"),
        hexFrom("AA", "AA", "AA"),
        hexFrom("55", "55", "FF"),
        hexFrom("55", "FF", "55"),
        hexFrom("55", "FF", "FF"),
        hexFrom("FF", "55", "55"),
        hexFrom("FF", "55", "FF"),
        hexFrom("FF", "FF", "55"),
        hexFrom("FF", "FF", "FF"),
    };


    //
    //  Rappresenta una Raccolta di Colori a 16bit
    //  Moderni
    //

    const HEXCOLOR modterm[16] = {
        hexFrom("11", "11", "11"),
        hexFrom("00", "16", "64"),
        hexFrom("20", "40", "32"),
        hexFrom("00", "80", "80"),
        hexFrom("A0", "20", "20"),
        hexFrom("A0", "20", "A0"),
        hexFrom("FF", "C8", "20"),
        hexFrom("20", "20", "20"),
        hexFrom("E6", "E6", "E6"),
        hexFrom("10", "30", "A0"),
        hexFrom("40", "80", "64"),
        hexFrom("3C", "BE", "BE"),
        hexFrom("D8", "46", "46"),
        hexFrom("C8", "4B", "C8"),
        hexFrom("FF", "D2", "46"),
        hexFrom("FF", "FF", "FF"),
    };


    void setScreenColor(int i, string r, string g, string b);
    void setScreenColor(int i, HEXCOLOR color);
    void setScreenColor(const HEXCOLOR colors[16]);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Foreground Color
    // ##

    #pragma region Foreground Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string setForegroundColor(int r, int g, int b);
    string setForegroundColor(RGBCOLOR color);
    string setForegroundColor(int c);
    string setForegroundColorById(int id);
    string sFC(int r, int g, int b);
    string sFC(RGBCOLOR color);
    string sFC(int c);
    string sFCById(int id);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Background Color
    // ##

    #pragma region Background Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string setBackgroundColor(int r, int g, int b);
    string setBackgroundColor(RGBCOLOR color);
    string setBackgroundColor(int c);
    string setBackgroundColorById(int id);
    string sBC(int r, int g, int b);
    string sBC(RGBCOLOR color);
    string sBC(int c);
    string sBCById(int id);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SGR
    // ##

    #pragma region SGR

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    //
    //  Generic
    //

    #define ESC                         0x1b    // Carattere ESC
    #define CSI                         0x1b[   // Sequenza CSI
    #define OSC                         0x1b]   // Sequenza OSC
    #define ST                          0x5C    // Carattere ST
    #define SP                          0x20    // Carattere SP

    //
    //  Text Style
    //

    #define SGR_DEFAULT                 0   // Default
    #define SGR_BOLD_ON                 1   // Grassetto On
    #define SGR_BOLD_OFF                22  // Grassetto Off
    #define SGR_FAINT_ON                2   // Sottile On
    #define SGR_FAINT_OFF               22  // Sottile Off
    #define SGR_ITALIC_ON               3   // Corsivo On
    #define SGR_ITALIC_OFF              23  // Corsivo Off
    #define SGR_UNDERLINE_ON            4   // Sottolineato On
    #define SGR_UNDERLINE_OFF           24  // Sottolineato Off
    #define SGR_DOUBLE_UNDERLINE_ON     21  // Doppia Sottolineatura On
    #define SGR_DOUBLE_UNDERLINE_OFF    24  // Doppia Sottolineatura Off
    #define SGR_BLINKING_ON             5   // Lampeggiamento On
    #define SGR_BLINKING_OFF            25  // Lampeggiamento Off
    #define SGR_NEGATIVE_ON             7   // Negativo On
    #define SGR_NEGATIVE_OFF            27  // Negativo Off
    #define SGR_HIDDEN_ON               8   // Nascosto On
    #define SGR_HIDDEN_OFF              28  // Nascosto Off
    #define SGR_STRIKEOUT_ON            9   // Sbarrato On
    #define SGR_STRIKEOUT_OFF           29  // Sbarrato Off

    //
    //  8 Bit Colors
    //

    #define SGR_FG_BLACK                30  // Nero Primo Piano
    #define SGR_FG_RED                  31  // Rosso Primo Piano
    #define SGR_FG_GREEN                32  // Verde Primo Piano
    #define SGR_FG_YELLOW               33  // Giallo Primo Piano
    #define SGR_FG_BLUE                 34  // Blu Primo Piano
    #define SGR_FG_MAGENTA              35  // Magenta Primo Piano
    #define SGR_FG_CYAN                 36  // Ciano Primo Piano
    #define SGR_FG_WHITE                37  // Biano Primo Piano
    #define SGR_FG_DEFAULT              39  // Default Primo Piano
    #define SGR_BK_BLACK                40  // Nero Sfondo
    #define SGR_BK_RED                  41  // Rosso Sfondo
    #define SGR_BK_GREEN                42  // Verde Sfondo
    #define SGR_BK_YELLOW               43  // Giallo Sfondo
    #define SGR_BK_BLUE                 44  // Blu Sfondo
    #define SGR_BK_MAGENTA              45  // Magenta Sfondo
    #define SGR_BK_CYAN                 46  // Ciano Sfondo
    #define SGR_BK_WHITE                47  // Biano Sfondo
    #define SGR_BK_DEFAULT              49  // Default Sfondo

    //
    //  16 Bit Colors
    //

    #define SGR_FG_BRIGHT_BLACK         90  // Nero Primo Piano Luminoso
    #define SGR_FG_BRIGHT_RED           91  // Rosso Primo Piano Luminoso
    #define SGR_FG_BRIGHT_GREEN         92  // Verde Primo Piano Luminoso
    #define SGR_FG_BRIGHT_YELLOW        93  // Giallo Primo Piano Luminoso
    #define SGR_FG_BRIGHT_BLUE          94  // Blue Primo Piano Luminoso
    #define SGR_FG_BRIGHT_MAGENTA       95  // Magenta Primo Piano Luminoso
    #define SGR_FG_BRIGHT_CYAN          96  // Ciano Primo Piano Luminoso
    #define SGR_FG_BRIGHT_WHITE         97  // Bianco Primo Piano Luminoso
    #define SGR_BK_BRIGHT_BLACK         100 // Nero Sfondo Luminoso
    #define SGR_BK_BRIGHT_RED           101 // Rosso Sfondo Luminoso
    #define SGR_BK_BRIGHT_GREEN         102 // Verde Sfondo Luminoso
    #define SGR_BK_BRIGHT_YELLOW        103 // Giallo Sfondo Luminoso
    #define SGR_BK_BRIGHT_BLUE          104 // Blu Sfondo Luminoso
    #define SGR_BK_BRIGHT_MAGENTA       105 // Magenta Sfondo Luminoso
    #define SGR_BK_BRIGHT_CYAN          106 // Ciano Sfondo Luminoso
    #define SGR_BK_BRIGHT_WHITE         107 // Bianco Sfondo Luminoso


    string sgr(unsigned c);
    
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Mode Changes
    // ##

    #pragma region Mode Changes

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void keypadApplicationMode(bool value);
    void cursorKeysApplicationMode(bool value);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Designate Character
    // ##

    #pragma region Designate Character

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #define DC_BOTTOM_LEFT      0x6A    // ┘
    #define DC_TOP_LEFT         0x6B    // ┐
    #define DC_TOP_RIGHT        0x6C    // ┌
    #define DC_BOTTOM_RIGHT     0x6D    // └
    #define DC_CENTER           0x6E    // ┼
    #define DC_TOP              0x71    // ─
    #define DC_LEFT_CENTER      0x74    // ├
    #define DC_RIGHT_CENTER     0x75    // ┤
    #define DC_BOTTOM_CENTER    0x76    // ┴
    #define DC_TOP_CENTER       0x77    // ┬
    #define DC_LEFT             0x78    // │


    void designateCharacter(bool value);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Window Title
    // ##

    #pragma region Window Title

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void windowTitle(string value);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Alternate Screen Buffer
    // ##

    #pragma region Alternate Screen Buffer

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void alternateScreenBuffer(bool value);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Window Width
    // ##

    #pragma region Window Width

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void windowWidth(bool value);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Soft Reset
    // ##

    #pragma region Soft Reset

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void softReset();

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
