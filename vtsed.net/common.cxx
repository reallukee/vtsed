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

#include "common.hxx"

namespace VTSEd
{
    // ##
    // ##   Conversions
    // ##

    #pragma region Conversions

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    String^ DECToHEX(int DEC)
    {
        return gcnew String(decToHex(DEC).c_str());
    }


    int HEXToDEC(String^ HEX)
    {
        return hexToDec(marshal_as<std::string>(HEX));
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   RGBColor
    // ##

    #pragma region RGBColor

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    RGBColor::RGBColor(int R, int G, int B)
    {
        ptr = new vtsed::RGBCOLOR((short)R, (short)G, (short)B);
    }

    RGBColor::RGBColor(int C)
    {
        ptr = new vtsed::RGBCOLOR((short)C);
    }

    RGBColor::RGBColor()
    {
        ptr = new vtsed::RGBCOLOR();
    }

    RGBColor::~RGBColor()
    {
        delete ptr;
    }



    int RGBColor::R::get()
    {
        return ptr->r;
    }

    void RGBColor::R::set(int Value)
    {
        ptr->r = (short)Value;
    }



    int RGBColor::G::get()
    {
        return ptr->g;
    }

    void RGBColor::G::set(int Value)
    {
        ptr->g = (short)Value;
    }



    int RGBColor::B::get()
    {
        return ptr->b;
    }

    void RGBColor::B::set(int Value)
    {
        ptr->b = (short)Value;
    }



    String^ RGBColor::ToString()
    {
        return gcnew String(ptr->toString().c_str());
    }



    RGBColor^ RGBFrom(int R, int G, int B)
    {
        return gcnew RGBColor(R, G, B);
    }

    RGBColor^ RGBFrom(int C)
    {
        return gcnew RGBColor(C);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   HEXColor
    // ##

    #pragma region RgbColor

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    HEXColor::HEXColor(String^ R, String^ G, String^ B)
    {
        ptr = new vtsed::HEXCOLOR(
            marshal_as<std::string>(R),
            marshal_as<std::string>(G),
            marshal_as<std::string>(B)
        );
    }

    HEXColor::HEXColor(String^ C)
    {
        ptr = new vtsed::HEXCOLOR(
            marshal_as<std::string>(C)
        );
    }

    HEXColor::HEXColor()
    {
        ptr = new vtsed::HEXCOLOR();
    }

    HEXColor::~HEXColor()
    {
        delete ptr;
    }



    String^ HEXColor::R::get()
    {
        return gcnew String(ptr->r.c_str());
    }

    void HEXColor::R::set(String^ Value)
    {
        ptr->r = marshal_as<std::string>(Value);
    }



    String^ HEXColor::G::get()
    {
        return gcnew String(ptr->g.c_str());
    }

    void HEXColor::G::set(String^ Value)
    {
        ptr->g = marshal_as<std::string>(Value);
    }



    String^ HEXColor::B::get()
    {
        return gcnew String(ptr->b.c_str());
    }

    void HEXColor::B::set(String^ Value)
    {
        ptr->b = marshal_as<std::string>(Value);
    }



    String^ HEXColor::ToString()
    {
        return gcnew String(ptr->toString().c_str());
    }



    HEXColor^ HEXFrom(String^ R, String^ G, String^ B)
    {
        return gcnew HEXColor(R, G, B);
    }

    HEXColor^ HEXFrom(String^ C)
    {
        return gcnew HEXColor(C);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion



    RGBColor^ RGBFromHEX(HEXColor^ HEX)
    {
        return gcnew RGBColor(
            HEXToDEC(HEX->R),
            HEXToDEC(HEX->G),
            HEXToDEC(HEX->B)
        );
    }


    HEXColor^ HEXFromRGB(RGBColor^ RGB)
    {
        return gcnew HEXColor(
            DECToHEX(RGB->R),
            DECToHEX(RGB->G),
            DECToHEX(RGB->B)
        );
    }



    // ##
    // ##   Point
    // ##

    #pragma region Point

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    Point::Point(int X, int Y)
    {
        ptr = new vtsed::POINT(X, Y);
    }

    Point::Point(int C)
    {
        ptr = new vtsed::POINT(C);
    }

    Point::Point()
    {
        ptr = new vtsed::POINT();
    }

    Point::~Point()
    {
        delete ptr;
    }



    int Point::X::get()
    {
        return ptr->x;
    }

    void Point::X::set(int Value)
    {
        ptr->x = Value;
    }



    int Point::Y::get()
    {
        return ptr->y;
    }

    void Point::Y::set(int Value)
    {
        ptr->y = Value;
    }



    String^ Point::ToString()
    {
        return gcnew String(ptr->toString().c_str());
    }



    Point^ PointFrom(int X, int Y)
    {
        return gcnew Point(X, Y);
    }

    Point^ PointFrom(int C)
    {
        return gcnew Point(C);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Size
    // ##

    #pragma region Size

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    Size::Size(int Width, int Height)
    {
        ptr = new vtsed::SIZE(Width, Height);
    }

    Size::Size(int Dimension)
    {
        ptr = new vtsed::SIZE(Dimension);
    }

    Size::Size()
    {
        ptr = new vtsed::SIZE();
    }

    Size::~Size()
    {
        delete ptr;
    }



    int Size::Width::get()
    {
        return ptr->width;
    }

    void Size::Width::set(int Value)
    {
        ptr->width = Value;
    }



    int Size::Height::get()
    {
        return ptr->height;
    }

    void Size::Height::set(int Value)
    {
        ptr->height = Value;
    }



    String^ Size::ToString()
    {
        return gcnew String(ptr->toString().c_str());
    }



    Size^ SizeFrom(int Width, int Height)
    {
        return gcnew Size(Width, Height);
    }

    Size^ SizeFrom(int Dimension)
    {
        return gcnew Size(Dimension);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
