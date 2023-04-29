//
//  VTSEd.NET (VTSEd per .NET)
//
//  Migliora la tua Applicazione Console C++!
//
//  Questo File fa Parte del Progetto VTSEd
//  ed è Distribuito sotto Licenza MIT.
//
//  GitHub:      https://github.com/reallukee/vtsed/
//  Autore:      Luca Pollicino
//  Descrizione: VTS
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma managed

#include "vts.hxx"

namespace VTSEd
{
    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    bool VTS::InitConsole()
    {
        return initConsole();
    }


    bool VTS::DinitConsole()
    {
        return dinitConsole();
    }


    bool VTS::EnableVTS()
    {
        return enableVTS();
    }


    bool VTS::DisableVTS()
    {
        return disableVTS();
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
