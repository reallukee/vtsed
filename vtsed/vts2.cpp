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

#include "pch.hpp"

#include "vts2.hpp"

namespace vtsed
{
    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setSgr(unsigned sgr, unsigned code)
    {
        if (getSgr(sgr, code))
            sgr -= code;
        else
            sgr += code;
    }


    bool getSgr(unsigned sgr, unsigned code)
    {
        if (((sgr >> 8) & 1) == 1)
            return true;
        else
            return false;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
