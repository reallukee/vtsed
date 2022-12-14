//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    VTS2
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

        #define SGR2_DEFAULT            0x0000
        #define SGR2_BOLD               0x0001
        #define SGR2_FAINT              0x0002
        #define SGR2_ITALIC             0x0004
        #define SGR2_UNDERLINE          0x0008
        #define SGR2_DOUBLE_UNDERLINE   0x0010
        #define SGR2_BLINKING           0x0020
        #define SGR2_NEGATIVE           0x0040
        #define SGR2_HIDDEN             0x0080
        #define SGR2_STRIKEOUT          0x0100


        void VTSED_API setSgr(unsigned _sgr_, unsigned code);
        bool VTSED_API getSgr(unsigned _sgr_, unsigned code);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
