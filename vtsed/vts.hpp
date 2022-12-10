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

#pragma once

//
// Esposizione.
//

#if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64
    #ifdef VTSED_LIBRARY   // VTSED_LIBRARY
        #define VTSED_API __declspec(dllexport)
    #else
        #define VTSED_API __declspec(dllimport)
    #endif  // VTSED_LIBRARY
#else
    #define VTSED_API
#endif  // _WIN32 || _WIN64

//
// Intestazioni Standard.
//

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

//
// Intestazioni Windows.
//

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

        #define CSI "0x1b[" // Sequenza CSI
        #define OSC "0x1b]" // Sequenza OSC
        #define ESC "0x1b"  // Carattere ESC
        #define ST  "0x5C"  // Carattere ST
        #define SP  "0x20"  // Carattere SP


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
        void VTSED_API setCursorPositionCUP();
        void VTSED_API setCursorPositionCUP(unsigned x, unsigned y);
        void VTSED_API setCursorPositionHVP();
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

        void VTSED_API scrollUp();
        void VTSED_API scrollUp(unsigned n);
        void VTSED_API scrollDown();
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


        void VTSED_API insertCharacter(unsigned n = 0);
        void VTSED_API deleteCharacter(unsigned n = 0);
        void VTSED_API eraseCharacter(unsigned n = 0);
        void VTSED_API insertLine(unsigned n = 0);
        void VTSED_API deleteLine(unsigned n = 0);
        void VTSED_API eraseInDisplay();
        void VTSED_API eraseInDisplay(unsigned n);
        void VTSED_API eraseInLine();
        void VTSED_API eraseInLine(unsigned n);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Link
        // ##

        #pragma region "Link"

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API link(string link, string text);

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


        void VTSED_API setScreenColor(int i, string r, string g, string b);
        void VTSED_API setScreenColor(int i, HEXCOLOR color);
        void VTSED_API setScreenColor(int i, string color);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Palette
        // ##

        #pragma region "Palette"

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API setPalette(const HEXCOLOR color[16]);
        void VTSED_API setPalette(const string color[16]);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Default Colors
        // ##

        #pragma region "Default Colors"

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API setDefaultForegroundColor(string r, string g, string b);
        void VTSED_API setDefaultForegroundColor(HEXCOLOR color);
        void VTSED_API setDefaultForegroundColor(string color);
        void VTSED_API setDefaultBackgroundColor(string r, string g, string b);
        void VTSED_API setDefaultBackgroundColor(HEXCOLOR color);
        void VTSED_API setDefaultBackgroundColor(string color);
        void VTSED_API setDefaultCursorColor(string r, string g, string b);
        void VTSED_API setDefaultCursorColor(HEXCOLOR color);
        void VTSED_API setDefaultCursorColor(string color);

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
        void VTSED_API cursorForewardsTab(int n = 1);
        void VTSED_API cursorBackwardsTab(int n = 1);
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

        void VTSED_API scrollingMargin();
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
