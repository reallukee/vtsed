# VTSEd

Migliora la tua Applicazione Console C++!

Questo README fa riferimento al progetto `vtsed.vcxproj`.

- [Regole](#regole)
- [Organizzazione](#organizzazione)
- [Compilazione](#compilazione)
- [Licenza](#licenza)

# Regole

- `<nome>.h` Intestazione di codice C.
- `<nome>.c` File di codice C.
- `<nome>.hpp` Intestazione che contiene codice C++.
- `<nome>.cpp` File che contiene codice C++.
- `<nome>.hxx` Intestazione che contiene codice C++/CLI.
- `<nome>.cxx` File che contiene codice C++/CLI.

# Organizzazione

- [`pch.hpp`](pch.hpp) Intestazioni precompilate.
- [`preprocessor.hpp`](preprocessor.hpp) Direttive preprocessore.
- [`resource.hpp`](resource.hpp) Risorse libreria.
- [`vtsed.hpp`](vtsed.hpp) Esposizione API.
- [`cmf.hpp`](cmf.hpp) Intestazione CMF.
- [`cmf.cpp`](cmf.cpp) Implementazione CMF.
- [`common.hpp`](common.hpp) Intestazione elementi comuni.
- [`common.cpp`](common.cpp) Implementazione elementi comuni.
- [`console.hpp`](console.hpp) Intestazione console.
- [`console.cpp`](console.cpp) Implementazione console.
- [`dcontrols.hpp`](dcontrols.hpp) Intestazione controlli dinamici.
- [`dcontrols.cpp`](dcontrols.cpp) Implementazione controlli dinamici.
- [`pinvoke.hpp`](pinvoke.hpp) Intestazione P/Invoke.
- [`pinvoke.cpp`](pinvoke.cpp) Implementazione P/Invoke.
- [`scontrols.hpp`](scontrols.hpp) Intestazione controlli statici.
- [`scontrols.cpp`](scontrols.cpp) Implementazione controlli statici.
- [`vts.hpp`](vts.hpp) Intestazione VTS.
- [`vts.cpp`](vts.cpp) Implementazione VTS.
- [`vts2.hpp`](vts2.hpp) Intestazione VTS2.
- [`vts2.cpp`](vts2.cpp) Implementazione VTS2.

# Compilazione

```
/!\ IMPORTANTE!

#define VTSED_LIBRARY

Decommentare la costante VTSED_LIBRARY o
definire la costante VTSED_LIBRARY nella
sezione "C/C++ > PREPROCESSORE" per
compilare questo HEADER con destinazione
Dynamic Link Library (DLL).

Se si sta utilizzando il progetto
vtsed.vcxproj la costante è già definita
nella sezione "C/C++ > PREPROCESSORE".

Quando definire VTSED_LIBARY?

1.  Si sta compilando VTSED come una
    Dynamic Link Library (DLL).
2.  Si sta compilando un progetto che
    utilizza direttamente il codice di
    VTSED.

Quando non definire VTSED_LIBRARY?

1.  Si sta compilando VTSED come una
    Static Library (LIB).
2.  Si sta compilando un progetto che
    utilizza indirettamente il codice
    di VTSED.
```

# Licenza

Questo progetto è sotto licenza [MIT](../LICENSE).
