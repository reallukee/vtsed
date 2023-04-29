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
//  Descrizione: CONSOLE
//               Questo Header Contiene le Definizioni
//               Relative alla Console.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#pragma once

#include "preprocessor.hpp" // Direttive.
#include "vts.hpp"          // VTS.

#pragma endregion


namespace vtsed
{
    extern "C++"
    {
        // ##
        // ##   Cursor
        // ##

        #pragma region Cursor

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API setCursorPosition(int x, int y);

#ifdef WIN  // WIN
        COORD VTSED_API getCursorPosition();
#endif  // ! WIN

#ifdef UNIX // UNIX
        void* VTSED_API getCursorPosition();
#endif  // ! UNIX

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
        void VTSED_API writeAtCenter(int y, string str);
        void VTSED_API writeAtRight(int y, string str);

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
    }
}
