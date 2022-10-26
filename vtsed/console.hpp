/*
    VTSEd

    Questo progetto è distribuito sotto licenza MIT.
    Questo progetto è disponibile su GitHub.

    Repository:     https://github.com/reallukee/vtsed/
    Descrizione:    CONSOLE
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
    #if defined(_WIN32) || defined(_WIN64)

    // ##
    // ##   Cursor
    // ##

    #pragma region Cursor

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setCursorPosition(int x, int y);
    COORD getCursorPosition();

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Write At
    // ##

    #pragma region Write At

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void writeAt(int x, int y, string str);
    void writeAt(int x, int y, char* str);
    void writeAtCenter(int y, string str);
    void writeAtCenter(int y, char* str);
    void writeAtRight(int y, string str);
    void writeAtRight(int y, char* str);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Color
    // ##

    #pragma region Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #define BLACK        0     // Nero
    #define DARKBLUE     1     // Blu Scuro
    #define DARKGREEN    2     // Verde Scuro
    #define DARKCYAN     3     // Ciano Scuro
    #define DARKRED      4     // Rosso Scuro
    #define DARKMAGENTA  5     // Magenta Scuro
    #define DARKYELLOW   6     // Giallo Scuro
    #define DARKGRAY     7     // Grigio Scuro
    #define GRAY         8     // Grigio
    #define BLUE         9     // Blu
    #define GREEN        10    // Verde
    #define CYAN         11    // Ciano
    #define RED          12    // Rosso
    #define MAGENTA      13    // Magenta
    #define YELLOW       14    // Giallo
    #define WHITE        15    // Bianco


    void setForegroundColorWin32(int c);
    void setBackgroundColorWin32(int c);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion

    #endif
}
