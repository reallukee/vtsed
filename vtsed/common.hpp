/*
    VTSEd

    Questo progetto è distribuito sotto licenza MIT.
    Questo progetto è disponibile su GitHub.

    Repository:     https://github.com/reallukee/vtsed/
    Descrizione:    COMMON
    Autore:         Realluke (https://github.com/reallukee/)
    Versione:       1.0.0
*/

#pragma once

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
#endif

using namespace std;

namespace vtsed
{
    // ##
    // ##   RGBCOLOR
    // ##

    #pragma region RGBCOLOR

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #ifndef RGBCOLOR_STRUCT // RGBCOLOR_STRUCT
    #define RGBCOLOR_STRUCT

    //
    //  RGBCOLOR
    //
    //  Rappresenta un colore a 24bit in formato RGB.
    //

    struct RGBCOLOR
    {
        short r = 0;
        short b = 0;
        short g = 0;

        // Costruttori Struttura.

        RGBCOLOR(short r, short g, short b);
        RGBCOLOR(short c);
        RGBCOLOR();

        // Metodi.

        string toString();
    };

    #endif  // RGBCOLOR_STRUCT


    RGBCOLOR rgbFrom(short r, short g, short b);
    RGBCOLOR rgbFrom(short c);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   HEXCOLOR
    // ##

    #pragma region HEXCOLOR

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #ifndef HEXCOLOR_STRUCT // HEXCOLOR_STRUCT
    #define HEXCOLOR_STRUCT

    //
    //  HEXCOLOR
    //
    //  Rappresenta un colore a 24bit in formato HEX.
    //

    struct HEXCOLOR
    {
        string r = "00";
        string g = "00";
        string b = "00";

        // Costruttori Struttura.

        HEXCOLOR(string r, string g, string b);
        HEXCOLOR(string c);
        HEXCOLOR();

        // Metodi.

        string toString();
    };


    HEXCOLOR hexFrom(string r, string g, string b);
    HEXCOLOR hexFrom(string c);

    #endif  // HEXCOLOR_STRUCT

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   POINT
    // ##

    #pragma region POINT

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #ifndef POINT_STRUCT // POINT_STRUCT
    #define POINT_STRUCT

    struct POINT
    {
        short x;
        short y;

        // Costruttori Struttura.
        POINT(short x, short y);
        POINT(short c);
        POINT();

        // Metodi.

        string toString();
    };

    #endif  // POINT_STRUCT


    POINT pointFrom(short x, short y);
    POINT pointFrom(short c);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SIZE
    // ##

    #pragma region SIZE

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #ifndef SIZE_STRUCT // SIZE_STRUCT
    #define SIZE_STRUCT

    struct SIZE
    {
        short width;
        short height;

        // Costruttori Struttura.
        SIZE(short width, short height);
        SIZE(short size);
        SIZE();

        // Metodi.

        string toString();
    };

    #endif  // SIZE_STRUCT


    SIZE SIZEFrom(short width, short height);
    SIZE SIZEFrom(short size);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
