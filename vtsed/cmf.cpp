//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    CMF
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//

#include "pch.h"

#include "cmf.hpp"

namespace vtsed
{
    // ##
    // ##   Basics
    // ##

    #pragma region Basics

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    string elaborateCmf(string str)
    {
        const int dim = 17;

        string vts[dim][2] = {
            { "$$b", "\x1b[1m" },
            { "!!b", "\x1b[22m" },
            { "$$f", "\x1b[2m" },
            { "!!f", "\x1b[22m" },
            { "$$i", "\x1b[3m"},
            { "!!i", "\x1b[23m" },
            { "$$u", "\x1b[4m" },
            { "!!u", "\x1b[24m" },
            { "$$k", "\x1b[5m" },
            { "!!k", "\x1b[25m" },
            { "$$v", "\x1b[7m" },
            { "!!v", "\x1b[27m" },
            { "$$h", "\x1b[8m" },
            { "!!h", "\x1b[28m" },
            { "$$s", "\x1b[9m" },
            { "!!s", "\x1b[29m" },
            { "$$0", "\x1b[0m" }
        };

        for (int i = 0; i < dim; i++)
        {
            long long pos = 0;

            string og = vts[i][0];
            string fn = vts[i][1];

            while (pos += fn.length())
            {
                pos = str.find(og, pos);

                if (pos == std::string::npos)
                    break;

                str.replace(pos, og.length(), fn);
            }
        }

        return str;
    }


    string delaborateCmf(string str)
    {
        const int dim = 17;

        string vts[dim][2] = {
            { "\x1b[1m", "$$b"},
            { "\x1b[22m", "!!b"},
            { "\x1b[2m", "$$f"},
            { "\x1b[22m", "!!f"},
            { "\x1b[3m", "$$i"},
            { "\x1b[23m", "!!i"},
            { "\x1b[4m", "$$u"},
            { "\x1b[24m", "!!u"},
            { "\x1b[5m", "$$k"},
            { "\x1b[25m", "!!k"},
            { "\x1b[7m", "$$v"},
            { "\x1b[27m", "!!v"},
            { "\x1b[8m", "$$h"},
            { "\x1b[28m", "!!h"},
            { "\x1b[9m", "$$s"},
            { "\x1b[29m", "!!s"},
            { "\x1b[0m", "$$0"}
        };

        for (int i = 0; i < dim; i++)
        {
            long long pos = 0;

            string og = vts[i][0];
            string fn = vts[i][1];

            while (pos += fn.length())
            {
                pos = str.find(og, pos);

                if (pos == std::string::npos)
                {
                    break;
                }

                str.replace(pos, og.length(), fn);
            }
        }

        return str;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
