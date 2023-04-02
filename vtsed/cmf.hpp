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
//  Descrizione: CMF
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#include "preprocessor.hpp" // Direttive.
#include "common.hpp"       // Common.
#include "console.hpp"      // Console.
#include "vts.hpp"          // VTS.

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
