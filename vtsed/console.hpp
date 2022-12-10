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

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
#endif

using namespace std;

namespace vtsed
{
    extern "C++"
    {
        #if defined(_WIN32) || defined(_WIN64)

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

        #define BLACK        0     // Nero
        #define DARKBLUE     1     // Blu Scuro
        #define DARKGREEN    2     // Verde Scuro
        #define DARKCYAN     3     // Ciano Scuro
        #define DARKRED      4     // Rosso Scuro
        #define DARKMAGENTA  5     // Magenta Scuro
        #define DARKYELLOW   6     // Giallo Scuro
        #define DARKGRAY     7     // Grigio Scuro
        #define GRAY         8     // Grigio
        #define BLUE         9     // Blu
        #define GREEN        10    // Verde
        #define CYAN         11    // Ciano
        #define RED          12    // Rosso
        #define MAGENTA      13    // Magenta
        #define YELLOW       14    // Giallo
        #define WHITE        15    // Bianco


        void VTSED_API setForegroundColorWin32(int c);
        void VTSED_API setBackgroundColorWin32(int c);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion

        #endif
    }
}
