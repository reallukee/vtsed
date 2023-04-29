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

#pragma once


#include "..\vtsed\vts.hpp"

using namespace vtsed;


#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;


#pragma managed

using namespace System;
using namespace System::Runtime::InteropServices;

namespace VTSEd
{
    static ref class VTS
    {

    public:

        // ##
        // ##   Basics
        // ##

        #pragma region Basics

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #define ESC "\x1b"  // Carattere ESC
        #define ST  "\x5C"  // Carattere ST
        #define SP  "\x20"  // Carattere SP
        #define CSI "\x1b[" // Sequenza CSI
        #define OSC "\x1b]" // Sequenza OSC


        bool InitConsole();
        bool DinitConsole();
        bool EnableVTS();
        bool DisableVTS();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    };
}
