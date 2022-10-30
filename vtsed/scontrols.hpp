/*
    VTSEd

    Questo progetto è distribuito sotto licenza MIT.
    Questo progetto è disponibile su GitHub.

    Repository:     https://github.com/reallukee/vtsed/
    Descrizione:    STATIC CONTROLS
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

#include "common.hpp"
#include "console.hpp"
#include "vts.hpp"

namespace vtsed
{
    #if defined(_WIN32) || defined(_WIN64)

    // ##
    // ##   Box
    // ##

    #pragma region Box

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void box(string* content, int ysize, string title, int x, int y);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    
    #pragma endregion


    // ##
    // ##   Table
    // ##

    #pragma region Table

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void table(string* content[], int ysize, int xsize, int x, int y);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    
    #pragma endregion

    #endif
}
