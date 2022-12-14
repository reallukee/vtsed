//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    CONSOLE
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

#if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64
    #include <conio.h>
    #include <windows.h>
#endif  // _WIN32 || _WIN64

using namespace std;

namespace vtsed
{
    extern "C++"
    {
        #if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64

        // ##
        // ##   Cursor
        // ##

        #pragma region Cursor

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API setCursorPosition(int x, int y);
        COORD VTSED_API getCursorPosition();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Write At
        // ##

        #pragma region Write At

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API writeAt(int x, int y, string str);
        void VTSED_API writeAt(int x, int y, char* str);
        void VTSED_API writeAtCenter(int y, string str);
        void VTSED_API writeAtCenter(int y, char* str);
        void VTSED_API writeAtRight(int y, string str);
        void VTSED_API writeAtRight(int y, char* str);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Color
        // ##

        #pragma region Color

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #define WIN32_BLACK         0   // Nero
        #define WIN32_DARKBLUE      1   // Blu Scuro
        #define WIN32_DARKGREEN     2   // Verde Scuro
        #define WIN32_DARKCYAN      3   // Ciano Scuro
        #define WIN32_DARKRED       4   // Rosso Scuro
        #define WIN32_DARKMAGENTA   5   // Magenta Scuro
        #define WIN32_DARKYELLOW    6   // Giallo Scuro
        #define WIN32_DARKGRAY      7   // Grigio Scuro
        #define WIN32_GRAY          8   // Grigio
        #define WIN32_BLUE          9   // Blu
        #define WIN32_GREEN         10  // Verde
        #define WIN32_CYAN          11  // Ciano
        #define WIN32_RED           12  // Rosso
        #define WIN32_MAGENTA       13  // Magenta
        #define WIN32_YELLOW        14  // Giallo
        #define WIN32_WHITE         15  // Bianco


        void VTSED_API setForegroundColorWin32(int c);
        void VTSED_API setBackgroundColorWin32(int c);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion

        #endif  // _WIN32 || _WIN64
    }
}
