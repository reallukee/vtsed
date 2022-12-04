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

#pragma once

//
//  /!\ IMPORTANTE!
//
//  #define VTSED_LIBRARY
//
//  Decommentare la costante VTSED_LIBRARY o
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
