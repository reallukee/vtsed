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
//  Descrizione: P/INVOKE
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#include "pch.hpp"      // Intestazioni Precompilate.

#include "pinvoke.hpp"  // Header di Riferimento.

#pragma endregion


namespace vtsed
{
    // ##
    // ##   P/Invoke
    // ##

    #pragma region P/Invoke

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void newGridRow(GridRow* t)
    {
        t = new GridRow();
    }


    void disposeGridRow(GridRow* t)
    {
        delete t;
    }


    void newSbsGridRow(SbsGridRow* t)
    {
        t = new SbsGridRow();
    }


    void disposeSbsGridRow(SbsGridRow* t)
    {
        delete t;
    }


    void newGridCol(GridCol* t)
    {
        t = new GridCol();
    }


    void disposeGridCol(GridCol* t)
    {
        delete t;
    }


    void newSbsGridCol(SbsGridCol* t)
    {
        t = new SbsGridCol();
    }


    void disposeSbsGridCol(SbsGridCol* t)
    {
        delete t;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
