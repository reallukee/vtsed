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
