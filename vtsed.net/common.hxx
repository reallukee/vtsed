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
//  Descrizione: COMMON
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#include "..\vtsed\common.hpp"

#include <msclr\marshal_cppstd.h>

using namespace vtsed;

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

namespace VTSEd
{
    // ##
    // ##   Conversions
    // ##

    #pragma region Conversions

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    String^ DECToHEX(int DEC);
    int HEXToDEC(String^ HEX);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   RGBColor
    // ##

    #pragma region RGBColor

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    //
    //  Wrapper di RGBCOLOR.
    //

    public ref struct RGBColor
    {

    private:

        vtsed::RGBCOLOR* ptr;

    public:

        RGBColor(int R, int G, int B);
        RGBColor(int C);
        RGBColor();
        ~RGBColor();

        property int R
        {
            int get();
            void set(int Value);
        }

        property int G
        {
            int get();
            void set(int Value);
        }

        property int B
        {
            int get();
            void set(int Value);
        }

        String^ ToString() override;

    };


    RGBColor^ RGBFrom(int R, int G, int B);
    RGBColor^ RGBFrom(int C);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   HEXColor
    // ##

    #pragma region HEXColor

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    //
    //  Wrapper di HEXColor.
    //

    public ref struct HEXColor
    {

    private:

        vtsed::HEXCOLOR* ptr;

    public:

        HEXColor(String^ R, String^ G, String^ B);
        HEXColor(String^ C);
        HEXColor();
        ~HEXColor();

        property String^ R
        {
            String^ get();
            void set(String^ Value);
        }

        property String^ G
        {
            String^ get();
            void set(String^ Value);
        }

        property String^ B
        {
            String^ get();
            void set(String^ Value);
        }

        String^ ToString() override;

    };


    HEXColor^ HEXFrom(String^ R, String^ G, String^ B);
    HEXColor^ HEXFrom(String^ C);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion



    RGBColor^ RGBFromHEX(HEXColor^ HEX);
    HEXColor^ HEXFromRGB(RGBColor^ RGB);



    // ##
    // ##   Point
    // ##

    #pragma region Point

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    //
    //  Wrapper di POINT.
    //

    public ref struct Point
    {

    private:

        vtsed::POINT* ptr;

    public:

        Point(int X, int Y);
        Point(int C);
        Point();
        ~Point();

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

        String^ ToString() override;

    };


    Point^ PointFrom(int X, int Y);
    Point^ PointFrom(int C);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Size
    // ##

    #pragma region Size

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    //
    //  Wrapper di SIZE.
    //

    public ref struct Size
    {

    private:

        vtsed::SIZE* ptr;

    public:

        Size(int Width, int Height);
        Size(int Dimension);
        Size();
        ~Size();

        property int Width
        {
            int get();
            void set(int Value);
        }

        property int Height
        {
            int get();
            void set(int Height);
        }

        String^ ToString() override;

    };


    Size^ SizeFrom(int Width, int Height);
    Size^ SizeFrom(int Dimension);

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
