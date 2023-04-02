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
//  Descrizione: PREPROCESSOR
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64

//
//  Esposizione API.
//

#ifdef VTSED_LIBRARY   // VTSED_LIBRARY

#ifndef VTSED_API   // VTSED_API
#define VTSED_API __declspec(dllexport)
#endif  // ! VTSED_API

#else

#ifndef VTSED_API   // VTSED_API
#define VTSED_API __declspec(dllimport)
#endif  // ! VTSED_API

#endif  // ! VTSED_LIBRARY

//
//  Windows.
//

#ifndef WIN // WIN
#define WIN
#endif  // ! WIN

#endif  // ! _WIN32 || _WIN64



#ifdef __unix__ // __unix__

//
//  Esposizione API.
//

#ifndef VTSED_API   // VTSED_API
#define VTSED_API
#endif  // ! VTSED_API

//
//  Linux.
//

#ifndef UNIX    // UNIX
#define UNIX
#endif  // ! UNIX

#endif  // ! __unix__



#ifdef __APPLE__    // __APPLE__

//
//  Esposizione API.
//

#ifndef VTSED_API   // VTSED_API
#define VTSED_API
#endif  // ! VTSED_API

//
//  MacOS.
//

#ifndef UNIX    // UNIX
#define UNIX
#endif  // ! UNIX

#endif  // ! __APPLE__

//
//  Intestazioni Standard.
//

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

//
//  Intestazioni Windows.
//

#ifdef WIN  // WIN

#include <conio.h>
#include <windows.h>

#endif  // ! WIN

//
//  Utilizzo Namespace.
//

using namespace std;
