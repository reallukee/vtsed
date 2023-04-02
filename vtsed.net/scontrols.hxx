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
//  Descrizione: STATIC CONTROL
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#include "..\vtsed\scontrols.hpp"

#include <msclr\marshal_cppstd.h>

using namespace vtsed;

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

#include "common.hxx"

namespace VTSEd
{
    // ##
    // ##   GridRow
    // ##

    #pragma region GridRow

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    public ref class GridRow
    {

    private:

        vtsed::GridRow* ptr;

    public:

        GridRow();
        // GridRow(string* content[], int xSize, int ySize);
        ~GridRow();

        property int X
        {
            int get();
            void set(int Value);
        }

        property int Y
        {
            int get();
            void set(int Value);
        }

        // void setContent(string* content[], int xSize, int ySize);
        // string** getContent();

        int GetXSize();
        int GetYSize();

        property RGBColor^ ForeColor
        {
            RGBColor^ get();
            void set(RGBColor^ Value);
        }

        property RGBColor^ BackColor
        {
            RGBColor^ get();
            void set(RGBColor^ Value);
        }

        int GetWidth();
        int GetHeight();

        void Draw();

        // bool(*onDraw)(string content, int row) = defaultGridRowOnDraw;

    };

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SbsGridRow
    // ##

    #pragma region SbsGridRow

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    public ref class SbsGridRow : GridRow
    {

    private:

        vtsed::SbsGridRow* ptr;

    public:

        SbsGridRow();
        ~SbsGridRow();

        void ResetDraw();
        // void drawNext(string content[], int maxLen[], int xSize);

        // bool(*onDrawNext)(string content, int row) = defaultGridRowOnDraw;
        // void(*onResetDraw)() = NULL;

    };

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   GridCol
    // ##

    #pragma region GridCol

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    public ref class GridCol
    {

    private:

        vtsed::GridCol* ptr;

    public:

        GridCol();
        // GridCol(string* content[], int xSize, int ySize);
        ~GridCol();

        property int X
        {
            int get();
            void set(int Value);
        }

        property int Y
        {
            int get();
            void set(int Value);
        }

        // void setContent(string* content[], int xSize, int ySize);
        // string** getContent();

        int GetXSize();
        int GetYSize();

        property RGBColor^ ForeColor
        {
            RGBColor^ get();
            void set(RGBColor^ Value);
        }

        property RGBColor^ BackColor
        {
            RGBColor^ get();
            void set(RGBColor^ Value);
        }

        int GetWidth();
        int GetHeight();

        void Draw();

        // bool(*onDraw)(string content, int col) = defaultGridColOnDraw;

    };

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SbsGridCol
    // ##

    #pragma region SbsGridCol

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    public ref class SbsGridCol : GridCol
    {

    private:

        vtsed::SbsGridCol* ptr;

    public:

        SbsGridCol();
        ~SbsGridCol();

        void ResetDraw();
        // void drawNext(string content[], int maxLen[], int xSize);

        // bool(*onDrawNext)(string content, int col) = defaultGridColOnDraw;
        // void(*onResetDraw)() = NULL;

    };

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
