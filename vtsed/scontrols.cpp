/*
    VTSEd

    Questo progetto è distribuito sotto licenza MIT.
    Questo progetto è disponibile su GitHub.

    Repository:     https://github.com/reallukee/vtsed/
    Descrizione:    STATIC CONTROLS
    Autore:         Realluke (https://github.com/reallukee/)
    Versione:       1.0.0
*/

#include "pch.h"

#include "scontrols.hpp"

namespace vtsed
{
    #if defined(_WIN32) || defined(_WIN64)

    // ##
    // ##   Box
    // ##

    #pragma region Box

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void box(string* content, int ysize, string title, int x, int y)
    {
        designateCharacter(true);

        int maxLenght = title.size();

        for (int i = 0; i < ysize; i++)
            if (content[i].size() > maxLenght)
                maxLenght = content[i].size();

        setCursorPosition(x, y);

        for (int j = 0; j < maxLenght - title.size() + 3; j++)
        {
            if (j == 0)
            {
                cout << "lq";
                designateCharacter(false);
                cout << title;
                designateCharacter(true);
            }
            else if (j == maxLenght - title.size() + 2)
                cout << "k";
            else
                cout << "q";
        }

        for (int i = 0; i < ysize; i++)
        {
            setCursorPosition(x, y + 1 + i);

            cout << "x ";
            designateCharacter(false);
            cout << content[i];
            designateCharacter(true);

            for (int j = content[i].size(); j < maxLenght + 2; j++)
            {
                if (j == maxLenght + 1)
                    cout << "x";
                else
                    cout << " ";
            }
        }

        setCursorPosition(x, y + 1 + ysize);

        for (int j = 0; j < maxLenght + 4; j++)
        {
            if (j == 0)
                cout << "m";
            else if (j == maxLenght + 3)
                cout << "j";
            else
                cout << "q";
        }

        designateCharacter(false);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Table
    // ##

    #pragma region Table

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void table(string* content[], int ysize, int xsize, int x, int y)
    {
        designateCharacter(true);

        int* maxColWidth = new int[xsize];

        for (int j = 0; j < ysize; j++)
            for (int i = 0; i < xsize; i++)
                maxColWidth[j, i] = 0;

        for (int j = 0; j < ysize; j++)
            for (int i = 0; i < xsize; i++)
                if (maxColWidth[i] < content[j][i].size())
                    maxColWidth[i] = content[j][i].size();

        for (int j = 0; j < ysize; j++)
        {
            setCursorPosition(x, y + j * 2);
            
            if (j == 0)
            {
                for (int i = 0; i < xsize; i++)
                {
                    if (i == 0)
                        cout << "l";

                    for (int z = 0; z < maxColWidth[i] + 2; z++)
                        cout << "q";

                    if (i == xsize - 1)
                        cout << "k";
                    else
                        cout << "w";
                }
            }

            setCursorPosition(x, y + j * 2 + 1);

            for (int i = 0; i < xsize; i++)
            {
                cout << "x ";
                designateCharacter(false);
                cout << content[j][i] << " ";
                designateCharacter(true);

                for (int z = content[j][i].size(); z < maxColWidth[i]; z++)
                    cout << " ";

                if (i == xsize - 1)
                    cout << "x";
            }

            setCursorPosition(x, y + j * 2 + 2);

            for (int i = 0; i < xsize; i++)
            {
                if (j == ysize - 1)
                {
                    if (i == 0)
                        cout << "m";
                }
                else
                {
                    if (i == 0)
                        cout << "t";
                }

                for (int z = 0; z < maxColWidth[i] + 2; z++)
                    cout << "q";

                if (j == ysize - 1)
                {
                    if (i == xsize - 1)
                        cout << "j";
                    else
                        cout << "v";
                }
                else
                {
                    if (i == xsize - 1)
                        cout << "u";
                    else
                        cout << "n";
                }
            }
        }

        designateCharacter(false);

        delete[] maxColWidth;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion

    #endif
}
