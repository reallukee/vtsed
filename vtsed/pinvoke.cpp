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
//               Questo Header Contiene le Implementazioni
//               Relative al P/Invoke.
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


    void deleteGridRow(GridRow* t)
    {
        delete t;
    }


    void newSbsGridRow(SbsGridRow* t)
    {
        t = new SbsGridRow();
    }


    void deleteSbsGridRow(SbsGridRow* t)
    {
        delete t;
    }


    void newGridCol(GridCol* t)
    {
        t = new GridCol();
    }


    void deleteGridCol(GridCol* t)
    {
        delete t;
    }


    void newSbsGridCol(SbsGridCol* t)
    {
        t = new SbsGridCol();
    }


    void deleteSbsGridCol(SbsGridCol* t)
    {
        delete t;
    }


    void newListBox(ListBox* t)
    {
        t = new ListBox();
    }


    void deleteListBox(ListBox* t)
    {
        delete t;
    }


    void newCheckListBox(CheckListBox* t)
    {
        t = new CheckListBox();
    }


    void deleteCheckListBox(CheckListBox* t)
    {
        delete t;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
