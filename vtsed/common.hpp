//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    COMMON
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

#pragma once

//
// Esposizione.
//

#if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64
    #ifdef VTSED_LIBRARY   // VTSED_LIBRARY
        #define VTSED_API __declspec(dllexport)
    #else
        #define VTSED_API __declspec(dllimport)
    #endif  // VTSED_LIBRARY
#else
    #define VTSED_API
#endif  // _WIN32 || _WIN64

//
// Intestazioni Standard.
//

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

//
// Intestazioni Windows.
//

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
#endif

using namespace std;

namespace vtsed
{
    extern "C++"
    {
        // ##
        // ##   Conversions
        // ##

        #pragma region Conversions

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        string VTSED_API decToHex(unsigned dec);
        unsigned VTSED_API hexToDec(string hex);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


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

        struct VTSED_API RGBCOLOR
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


        RGBCOLOR VTSED_API rgbFrom(short r, short g, short b);
        RGBCOLOR VTSED_API rgbFrom(short c);

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

        struct VTSED_API HEXCOLOR
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


        HEXCOLOR VTSED_API hexFrom(string r, string g, string b);
        HEXCOLOR VTSED_API hexFrom(string c);

        #endif  // HEXCOLOR_STRUCT

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion



        RGBCOLOR VTSED_API rgbFromHex(HEXCOLOR hex);
        HEXCOLOR VTSED_API hexFromRgb(RGBCOLOR rgb);



        // ##
        // ##   POINT
        // ##

        #pragma region POINT

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #ifndef POINT_STRUCT // POINT_STRUCT
        #define POINT_STRUCT

        struct VTSED_API POINT
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


        POINT VTSED_API pointFrom(short x, short y);
        POINT VTSED_API pointFrom(short c);

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

        struct VTSED_API SIZE
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


        SIZE VTSED_API SIZEFrom(short width, short height);
        SIZE VTSED_API SIZEFrom(short size);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
