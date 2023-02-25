//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    API EXPOSER
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

#pragma once

#ifndef VTSED_API_EXPOSER   // VTSED_API_EXPOSER
    #define VTSED_API_EXPOSER

    #ifdef VTSED_LIBRARY  // VTSED_LIBRARY
        #define MODE "LIBRARY"
    #else
        #define MODE "PROGRAM"
#endif  // VTSED_LIBRARY

#define VERSION "1.0.0"

#include "common.hpp"
#include "console.hpp"
#include "cmf.hpp"
#include "dcontrols.hpp"
#include "scontrols.hpp"
#include "vts.hpp"
#include "vts2.hpp"

#endif  // VTSED_API_EXPOSER
