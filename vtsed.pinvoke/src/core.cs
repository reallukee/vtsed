//
//  VTSEd.PInvoke
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    Core
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

using System;
using System.Runtime.InteropServices;

namespace VTSEd.PInvoke
{
    internal class Core
    {
#if WIN
#if x64
#if Release
        public const string DLL = "vtsed-x64.dll";
#endif
#if Debug
        public const string DLL = "vtsed-d-x64.dll";
#endif
#endif

#if x86
#if Release
        public const string DLL = "vtsed-x86.dll";
#endif
#if Debug
        public const string DLL = "vtsed-d-x86.dll";
#endif
#endif
#endif

        public static void Main()
        {

        }
    }
}
