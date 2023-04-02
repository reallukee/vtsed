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

#pragma once

#include "preprocessor.hpp" // Direttive.
#include "common.hpp"       // Common.
#include "dcontrols.hpp"    // Controlli Dinamici.
#include "scontrols.hpp"    // Controlli Statici.

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
        void VTSED_API disposeGridRow(GridRow* t);
        void VTSED_API newSbsGridRow(SbsGridRow* t);
        void VTSED_API disposeSbsGridRow(SbsGridRow* t);
        void VTSED_API newGridCol(GridCol* t);
        void VTSED_API disposeGridCol(GridCol* t);
        void VTSED_API newSbsGridCol(SbsGridCol* t);
        void VTSED_API disposeSbsGridCol(SbsGridCol* t);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
