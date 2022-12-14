//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    CMF
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
#include "console.hpp"
#include "vts.hpp"

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

        string VTSED_API elaborateCmf(string str);
        string VTSED_API delaborateCmf(string str);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
