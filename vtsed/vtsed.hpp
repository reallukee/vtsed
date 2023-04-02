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
//  Descrizione: API EXPOSER
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#ifndef VTSED_API_EXPOSER   // VTSED_API_EXPOSER

#define VTSED_API_EXPOSER

#ifdef VTSED_LIBRARY  // VTSED_LIBRARY
#define MODE "LIBRARY"
#else
#define MODE "PROGRAM"
#endif  // ! VTSED_LIBRARY

#define VERSION "1.1.0"

#include "pinvoke.hpp"

#include "common.hpp"
#include "console.hpp"
#include "cmf.hpp"
#include "dcontrols.hpp"
#include "scontrols.hpp"
#include "vts.hpp"
#include "vts2.hpp"

#endif  // ! VTSED_API_EXPOSER
