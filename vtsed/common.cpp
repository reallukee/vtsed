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

#include "pch.hpp"

#include "common.hpp"

namespace vtsed
{
    // ##
    // ##   Conversions
    // ##

    #pragma region Conversions

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string decToHex(unsigned dec)
    {
        string hex = "";

        while (dec != 0)
        {
            int t = dec % 16;

            if (t > 9)
                hex = (char)(65 + t - 10) + hex;
            else
                hex = to_string(t) + hex;

            dec = dec / 16;
        }

        return hex;
    }


    unsigned hexToDec(string hex)
    {
        unsigned dec = 0;

        for (int i = 0; i < hex.size(); i++)
        {
            int t = hex[i];

            if (t > 64)
                t = (unsigned)(t - 55);
            else
                t = (unsigned)(t - 48);

            dec += t * pow(16, i);
        }

        return dec;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   RGBCOLOR
    // ##

    #pragma region RGBCOLOR

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    RGBCOLOR::RGBCOLOR(short r, short g, short b)
    {
        this->r = r;
        this->g = g;
        this->b = b;

        if (r < 0 || r > 255)
            this->r = 0;

        if (g < 0 || g > 255)
            this->g = 0;

        if (b < 0 || b > 255)
            this->b = 0;
    }


    RGBCOLOR::RGBCOLOR(short c)
    {
        this->r = c;
        this->g = c;
        this->b = c;

        if (c < 0 || r > 255)
        {
            this->r = 0;
            this->g = 0;
            this->b = 0;
        }
    }


    RGBCOLOR::RGBCOLOR()
    {
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }


    string RGBCOLOR::toString()
    {
        stringstream t;
        t << "rgb(" << r << ", " << g << ", " << b << ")";
        return t.str();
    }


    RGBCOLOR rgbFrom(short r, short g, short b)
    {
        return RGBCOLOR(r, g, b);
    }


    RGBCOLOR rgbFrom(short c)
    {
        return RGBCOLOR(c, c, c);
    }


    RGBCOLOR rgbFromHex(HEXCOLOR hex)
    {
        return rgbFrom(hexToDec(hex.r), hexToDec(hex.g), hexToDec(hex.b));
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   HEXCOLOR
    // ##

    #pragma region HEXCOLOR

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    HEXCOLOR::HEXCOLOR(string r, string g, string b)
    {
        this->r = r;
        this->g = g;
        this->b = b;

        if (r.size() != 2)
            this->r = "00";

        if (g.size() != 2)
            this->g = "00";

        if (b.size() != 2)
            this->b = "00";
    }


    HEXCOLOR::HEXCOLOR(string c)
    {
        this->r = c;
        this->g = c;
        this->b = c;

        if (c.size() != 2)
        {
            this->r = "00";
            this->g = "00";
            this->b = "00";
        }
    }


    HEXCOLOR::HEXCOLOR()
    {
        this->r = "00";
        this->g = "00";
        this->b = "00";
    }


    string HEXCOLOR::toString()
    {
        stringstream t;
        t << "#" << r << g << b;
        return t.str();
    }


    HEXCOLOR hexFrom(string r, string g, string b)
    {
        return HEXCOLOR(r, g, b);
    }


    HEXCOLOR hexFrom(string c)
    {
        return HEXCOLOR(c, c, c);
    }


    HEXCOLOR hexFromRgb(RGBCOLOR rgb)
    {
        return hexFrom(decToHex(rgb.r), decToHex(rgb.g), decToHex(rgb.b));
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   POINT
    // ##

    #pragma region POINT

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    POINT::POINT(short x, short y)
    {
        this->x = x;
        this->y = y;
    }


    POINT::POINT(short c)
    {
        this->x = c;
        this->y = c;
    }


    POINT::POINT()
    {
        this->x = 0;
        this->y = 0;
    }


    string POINT::toString()
    {
        stringstream t;
        t << "(" << x << "," << y << ")";
        return t.str();
    }


    POINT pointFrom(short x, short y)
    {
        return POINT(x, y);
    }


    POINT pointFrom(short c)
    {
        return POINT(c);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SIZE
    // ##

    #pragma region SIZE

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    SIZE::SIZE(short width, short height)
    {
        this->width = width;
        this->height = height;
    }


    SIZE::SIZE(short size)
    {
        this->width = size;
        this->height = size;
    }


    SIZE::SIZE()
    {
        this->width = 0;
        this->height = 0;
    }


    string SIZE::toString()
    {
        stringstream t;
        t << "(" << width << "," << height << ")";
        return t.str();
    }


    SIZE SIZEFrom(short width, short height)
    {
        return SIZE(width, height);
    }


    SIZE SIZEFrom(short size)
    {
        return SIZE(size);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
