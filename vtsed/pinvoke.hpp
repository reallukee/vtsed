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
//               Questo Header Contiene le Definizioni
//               Relative al P/Invoke.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#pragma once

#include "preprocessor.hpp" // Direttive.
#include "common.hpp"       // Common.
#include "dcontrols.hpp"    // Controlli Dinamici.
#include "scontrols.hpp"    // Controlli Statici.

#pragma endregion


namespace vtsed
{
    extern "C++"
    {
        // ##
        // ##   P/Invoke
        // ##

        #pragma region P Invoke

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        void VTSED_API newGridRow(GridRow* t);
        void VTSED_API deleteGridRow(GridRow* t);
        void VTSED_API newSbsGridRow(SbsGridRow* t);
        void VTSED_API deleteSbsGridRow(SbsGridRow* t);
        void VTSED_API newGridCol(GridCol* t);
        void VTSED_API deleteGridCol(GridCol* t);
        void VTSED_API newSbsGridCol(SbsGridCol* t);
        void VTSED_API deleteSbsGridCol(SbsGridCol* t);
        void VTSED_API newListBox(ListBox* t);
        void VTSED_API deleteListBox(ListBox* t);
        void VTSED_API newCheckListBox(CheckListBox* t);
        void VTSED_API deleteCheckListBox(CheckListBox* t);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
