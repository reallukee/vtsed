using System;
using System.Runtime.InteropServices;

namespace VTSEd
{
    internal class Core
    {
    #if RELEASE
    #if X64
        public const string DLL = "vtsed-x64.dll";
    #else
        public const string DLL = "vtsed-x86.dll";
    #endif
    #endif


    #if DEBUG
    #if X64
        public const string DLL = "vtsed-d-x64.dll";
    #else
        public const string DLL = "vtsed-d-x86.dll";
    #endif
    #endif
    }
}
