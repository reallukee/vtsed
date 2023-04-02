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
//  Descrizione: VTS2
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#include "preprocessor.hpp" // Direttive.
#include "common.hpp"       // Common.

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


        void VTSED_API setSgr(unsigned sgr, unsigned code);
        bool VTSED_API getSgr(unsigned sgr, unsigned code);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
