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
//               Questo Header Contiene le Implementazioni
//               Relative a VTS2.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#include "pch.hpp"  // Intestazioni Precompilate.

#include "vts2.hpp" // Header di Riferimento.

#pragma endregion


namespace vtsed
{
    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setSGR(unsigned sgr, unsigned code)
    {
        if (getSGR(sgr, code))
        {
            sgr -= code;
        }
        else
        {
            sgr += code;

            switch (code)
            {
            case SGR2_DEFAULT:
                cout << "\x1b[0m";
                break;

            default:
                break;
            }
        }
    }


    bool getSGR(unsigned sgr, unsigned code)
    {
        if (((sgr >> 8) & 1) == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
