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
//               Questo Header Contiene le Definizioni
//               Relative all'Utilizzo di VTSEd.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

//
//  NON MODIFICARE QUESTO FILE!
//

#pragma once

#ifndef VTSED_API_EXPOSER   // VTSED_API_EXPOSER

#define VTSED_API_EXPOSER

#ifndef VTSED_VERSION   // VTSED_VERSION
#define VTSED_VERSION "1.1.0"
#endif  // ! VTSED_VERSION

//  #include "pinvoke.hpp"

#include "common.hpp"
#include "console.hpp"
#include "cmf.hpp"
#include "dcontrols.hpp"
#include "scontrols.hpp"
#include "vts.hpp"
#include "vts2.hpp"

//
//  #define VTSED_LIBRARY
//
//  Decommentare la costante VTSED_LIBRARY o
//  definire la costante VTSED_LIBRARY nella
//  sezione "C/C++ > PREPROCESSORE" per
//  compilare questo HEADER con destinazione
//  Dynamic Link Library(DLL).
//
//  Se si sta utilizzando il progetto
//  vtsed.vcxproj la costante è già definita
//  nella sezione "C/C++ > PREPROCESSORE".
//
//  Quando definire VTSED_LIBARY ?
//
//  1.  Si sta compilando VTSED come una
//  Dynamic Link Library(DLL).
//  2.  Si sta compilando un progetto che
//  utilizza direttamente il codice di
//  VTSED.
//
//  Quando non definire VTSED_LIBRARY ?
//
//  1.  Si sta compilando VTSED come una
//  Static Library(LIB).
//  2.  Si sta compilando un progetto che
//  utilizza indirettamente il codice
//  di VTSED.
//

#ifdef VTSED_LIBRARY  // VTSED_LIBRARY
#define MODE "LIBRARY"
#else
#define MODE "PROGRAM"
#endif  // ! VTSED_LIBRARY

#endif  // ! VTSED_API_EXPOSER
