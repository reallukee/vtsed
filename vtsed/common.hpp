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
//  Descrizione: COMMON
//               Questo Header Contiene le Definizioni
//               di Costanti, Metodi e Strutture Comuni.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#pragma once

#include "preprocessor.hpp" // Direttive.

#pragma endregion


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
            short r;
            short b;
            short g;

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
            string r;
            string g;
            string b;

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
            SIZE(short dimension);
            SIZE();

            // Metodi.
            string toString();
        };

        #endif  // SIZE_STRUCT


        SIZE VTSED_API SIZEFrom(short width, short height);
        SIZE VTSED_API SIZEFrom(short dimension);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
