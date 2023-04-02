//
//  VTSEd.PInvoke
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    VTS
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

using System;
using System.Runtime.InteropServices;

namespace VTSEd.PInvoke
{
    public static class VTS
    {
        [DllImport(Core.DLL, EntryPoint = "?initConsole@vtsed@@YA_NXZ")]
        private static extern bool initConsole();
        public static bool InitConsole() => initConsole();


        [DllImport(Core.DLL, EntryPoint = "?dinitConsole@vtsed@@YA_NXZ")]
        private static extern bool dinitConsole();
        public static bool DinitConsole() => dinitConsole();


        [DllImport(Core.DLL, EntryPoint = "?enableVTS@vtsed@@YA_NXZ")]
        private static extern bool enableVTS();
        public static bool EnableVTS() => enableVTS();


        [DllImport(Core.DLL, EntryPoint = "?disableVTS@vtsed@@YA_NXZ")]
        private static extern bool disableVTS();
        public static bool DisableVTS() => disableVTS();
    }
}
