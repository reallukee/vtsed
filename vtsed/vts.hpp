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

#pragma once

//
//  /!\ IMPORTANTE!
//
//  #define VTSED_LIBRARY
//
//  De commentare la costante VTSED_LIBRARY o
//  definire la costante VTSED_LIBRARY nella
//  sezione "C/C++ > PREPROCESSORE" per
//  compilare questo HEADER con destinazione
//  Dynamic Link Library (DLL).
//
//  Quando definire VTSED_LIBARY?
//
//  1.  Si sta compilando VTSED come una
//      Dynamic Link Library (DLL).
//  2.  Si sta compilando un progetto che
//      utilizza direttamente il codice di
//      VTSED.
//
//  Quando non definire VTSED_LIBRARY?
// 
//  1.  Si sta compilando VTSED come una
//      Static Library (LIB).
//  2.  Si sta compilando un progetto che
//      utilizza indirettamente il codice
//      di VTSED.
//

#ifdef VTSED_LIBRARY   // VTSED_LIBRARY
#define VTSED_API __declspec(dllexport)
#else
#define VTSED_API __declspec(dllimport)
#endif  // VTSED_LIBRARY

// Standard.
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
// Solo Windows.
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
#endif

using namespace std;

#include "common.hpp"

namespace vtsed
{
    extern "C++"
    {
        // ##
        // ##   Basics
        // ##

        #pragma region Basics

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #if defined(_WIN32) || defined(_WIN64)

        bool VTSED_API initConsole();
        bool VTSED_API dinitConsole();
        bool VTSED_API enableVTS();
        bool VTSED_API disableVTS();

        #endif

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Simple Cursor Positioning
        // ##

        #pragma region Simple Cursor Positioning

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API reverseCursorIndex();
        void VTSED_API saveCursor();
        void VTSED_API restoreCursor();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Cursor Positioning
        // ##

        #pragma region Cursor Positioning

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API cursorUp(unsigned n = 0);
        void VTSED_API cursorDown(unsigned n = 0);
        void VTSED_API cursorRight(unsigned n = 0);
        void VTSED_API cursorLeft(unsigned n = 0);
        void VTSED_API cursorUpLine(unsigned n = 0);
        void VTSED_API cursorPreviousLine(unsigned n = 0);
        void VTSED_API cursorHorizontalAbs(unsigned n = 0);
        void VTSED_API cursorVerticalAbs(unsigned n = 0);
        void VTSED_API setCursorPositionCUP(unsigned x, unsigned y);
        void VTSED_API setCursorPositionHVP(unsigned x, unsigned y);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Cursor Visibility
        // ##

        #pragma region Cursor Visibility

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API cursorBlinking(bool value);
        void VTSED_API cursorVisible(bool value);

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


        void VTSED_API cursorShape(unsigned c);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Viewport Positioning
        // ##

        #pragma region Viewport Positioning

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API scrollUp(unsigned n);
        void VTSED_API scrollDown(unsigned n);

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


        void VTSED_API insertCharacter(unsigned n);
        void VTSED_API deleteCharacter(unsigned n);
        void VTSED_API eraseCharacter(unsigned n);
        void VTSED_API insertLine(unsigned n);
        void VTSED_API deleteLine(unsigned n);
        void VTSED_API eraseInDisplay(unsigned n);
        void VTSED_API eraseInLine(unsigned n);

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
        #define SCREEN_COLOR_DARKRED      1     // Rosso Scuro
        #define SCREEN_COLOR_DARKGREEN    2     // Verde Scuro
        #define SCREEN_COLOR_DARKYELLOW   3     // Giallo Scuro
        #define SCREEN_COLOR_DARKBLUE     4     // Blu Scuro
        #define SCREEN_COLOR_DARKMAGENTA  5     // Magenta Scuro
        #define SCREEN_COLOR_DARKCYAN     6     // Ciano Scuro
        #define SCREEN_COLOR_DARKGRAY     7     // Grigio Scuro
        #define SCREEN_COLOR_GRAY         8     // Grigio
        #define SCREEN_COLOR_RED          9     // Rosso
        #define SCREEN_COLOR_GREEN        10    // Verde
        #define SCREEN_COLOR_YELLOW       11    // Giallo
        #define SCREEN_COLOR_BLUE         12    // Blu
        #define SCREEN_COLOR_MAGENTA      13    // Magenta
        #define SCREEN_COLOR_CYAN         14    // Ciano
        #define SCREEN_COLOR_WHITE        15    // Bianco


        //
        //  Rappresenta una Raccolta di Colori a 16bit
        //  di Windows ConHost.
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
        //  di Windows Terminal.
        //

        const HEXCOLOR terminal[16] = {
            hexFrom("00", "00", "00"),
            hexFrom("C2", "36", "21"),
            hexFrom("25", "BC", "24"),
            hexFrom("AD", "AD", "27"),
            hexFrom("49", "2E", "E1"),
            hexFrom("D3", "38", "D3"),
            hexFrom("33", "BB", "C8"),
            hexFrom("CB", "CC", "CD"),
            hexFrom("81", "83", "83"),
            hexFrom("FC", "39", "1F"),
            hexFrom("31", "E7", "22"),
            hexFrom("EA", "EC", "23"),
            hexFrom("58", "33", "FF"),
            hexFrom("F9", "35", "F8"),
            hexFrom("14", "F0", "F0"),
            hexFrom("E9", "EB", "EB"),
        };


        //
        //  Rappresenta una Raccolta di Colori a 16bit
        //  Classici.
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
        //  Moderni.
        //

        const HEXCOLOR modterm[16] = {
            hexFrom("11", "11", "11"),  // Nero
            hexFrom("10", "30", "A0"),  // Blu
            hexFrom("3C", "5F", "46"),  // Verde
            hexFrom("00", "80", "80"),  // Ciano
            hexFrom("A5", "2D", "2D"),  // Rosso
            hexFrom("87", "0A", "7D"),  // Magenta
            hexFrom("FF", "C8", "20"),  // Giallo
            hexFrom("FF", "00", "FF"),  // Grigio
            hexFrom("E6", "E6", "E6"),  // Grigio Chiaro
            hexFrom("05", "55", "B4"),  // Blu Chiaro
            hexFrom("55", "96", "69"),  // Verde Chiaro
            hexFrom("3C", "BE", "BE"),  // Ciano Chiaro
            hexFrom("D8", "46", "46"),  // Rosso Chiaro
            hexFrom("C8", "32", "C8"),  // Magenta Chiaro
            hexFrom("FF", "D2", "46"),  // Giallo Chiaro
            hexFrom("FF", "FF", "FF"),  // Bianco
        };


        void VTSED_API setScreenColor(int i, string r, string g, string b);
        void VTSED_API setScreenColor(int i, HEXCOLOR color);
        void VTSED_API setScreenColor(const HEXCOLOR colors[16]);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Foreground Color
        // ##

        #pragma region Foreground Color

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        string VTSED_API setForegroundColor(int r, int g, int b);
        string VTSED_API setForegroundColor(RGBCOLOR color);
        string VTSED_API setForegroundColor(int c);
        string VTSED_API setForegroundColorById(int id);
        string VTSED_API sFC(int r, int g, int b);
        string VTSED_API sFC(RGBCOLOR color);
        string VTSED_API sFC(int c);
        string VTSED_API sFCById(int id);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Background Color
        // ##

        #pragma region Background Color

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        string VTSED_API setBackgroundColor(int r, int g, int b);
        string VTSED_API setBackgroundColor(RGBCOLOR color);
        string VTSED_API setBackgroundColor(int c);
        string VTSED_API setBackgroundColorById(int id);
        string VTSED_API sBC(int r, int g, int b);
        string VTSED_API sBC(RGBCOLOR color);
        string VTSED_API sBC(int c);
        string VTSED_API sBCById(int id);

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

        #define ESC                         "0x1b"  // Carattere ESC
        #define CSI                         "0x1b[" // Sequenza CSI
        #define OSC                         "0x1b]" // Sequenza OSC
        #define ST                          "0x5C"  // Carattere ST
        #define SP                          "0x20"  // Carattere SP

        //
        //  Text Style
        //

        #define SGR_DEFAULT                 0   // Default
        #define SGR_BOLD                    1   // Grassetto On
        #define SGR_NO_BOLD                 22  // Grassetto Off
        #define SGR_FAINT                   2   // Sottile On
        #define SGR_NO_FAINT                22  // Sottile Off
        #define SGR_ITALIC                  3   // Corsivo On
        #define SGR_NO_ITALIC               23  // Corsivo Off
        #define SGR_UNDERLINE               4   // Sottolineato On
        #define SGR_NO_UNDERLINE            24  // Sottolineato Off
        #define SGR_DOUBLE_UNDERLINE        21  // Doppia Sottolineatura On
        #define SGR_NO_DOUBLE_UNDERLINE     24  // Doppia Sottolineatura Off
        #define SGR_BLINKING                5   // Lampeggiamento On
        #define SGR_NO_BLINKING             25  // Lampeggiamento Off
        #define SGR_NEGATIVE                7   // Negativo On
        #define SGR_NO_NEGATIVE             27  // Negativo Off
        #define SGR_HIDDEN                  8   // Nascosto On
        #define SGR_NO_HIDDEN               28  // Nascosto Off
        #define SGR_STRIKEOUT               9   // Sbarrato On
        #define SGR_NO_STRIKEOUT            29  // Sbarrato Off

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


        string VTSED_API sgr(unsigned c);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Mode Changes
        // ##

        #pragma region Mode Changes

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API keypadApplicationMode(bool value);
        void VTSED_API cursorKeysApplicationMode(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Query State
        // ##

        #pragma region Query State

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API reportCursorPosition();
        void VTSED_API deviceAttributes();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Tabs
        // ##

        #pragma region Tabs

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API horizontalTab();
        void VTSED_API cursorHorizontalTab(int n);
        void VTSED_API cursorBackwardsTab(int n);
        void VTSED_API tabClearCurrentColumn();
        void VTSED_API tabClearAllColumns();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Designate Character
        // ##

        #pragma region Designate Character

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #define DC_BOTTOM_LEFT      0x6A    // ┘    j
        #define DC_TOP_LEFT         0x6B    // ┐    k
        #define DC_TOP_RIGHT        0x6C    // ┌    l
        #define DC_BOTTOM_RIGHT     0x6D    // └    m
        #define DC_CENTER           0x6E    // ┼    n
        #define DC_TOP              0x71    // ─    q
        #define DC_LEFT_CENTER      0x74    // ├    t
        #define DC_RIGHT_CENTER     0x75    // ┤    u
        #define DC_BOTTOM_CENTER    0x76    // ┴    v
        #define DC_TOP_CENTER       0x77    // ┬    w
        #define DC_LEFT             0x78    // │    x


        void VTSED_API designateCharacter(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Scrolling Margins
        // ##

        #pragma region Scrolling Margin

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API scrollingMargin(int t, int b);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Window Title
        // ##

        #pragma region Window Title

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API windowTitle(string value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Alternate Screen Buffer
        // ##

        #pragma region Alternate Screen Buffer

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API alternateScreenBuffer(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Window Width
        // ##

        #pragma region Window Width

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API windowWidth(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Soft Reset
        // ##

        #pragma region Soft Reset

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API softReset();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
