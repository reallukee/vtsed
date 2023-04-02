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
//  Descrizione: STATIC CONTROL
//               Questo File Contiene le Implementazioni
//               Relative ai Controlli Statitici.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#include "pch.hpp"          // Intestazioni Precompilate.

#include "scontrols.hpp"    // Header di Riferimento.

#pragma endregion


namespace vtsed
{
    // ##
    // ##   Grid Row
    // ##

    #pragma region Grid Row

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    unsigned GridRow::getX()
    {
        return x;
    }

    void GridRow::setX(unsigned x)
    {
        this->x = x;
    }

    unsigned GridRow::getY()
    {
        return y;
    }

    void GridRow::setY(unsigned y)
    {
        this->y = y;
    }



    void GridRow::setContent(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        updateConfig();
    }

    string** GridRow::getContent()
    {
        return content;
    }



    int GridRow::getXSize()
    {
        return xSize;
    }

    int GridRow::getYSize()
    {
        return ySize;
    }



    void GridRow::setForeColor(RGBCOLOR foreColor)
    {
        this->foreColor = foreColor;
    }

    RGBCOLOR GridRow::getForeColor()
    {
        return foreColor;
    }

    void GridRow::setBackColor(RGBCOLOR backColor)
    {
        this->backColor = backColor;
    }

    RGBCOLOR GridRow::getBackColor()
    {
        return backColor;
    }



    GridRow::GridRow()
    {
        this->content = NULL;
        this->xSize = -1;
        this->ySize = -1;
        this->x = DEFAULTX;
        this->y = DEFAULTY;
        this->foreColor = rgbFrom(240);
        this->backColor = rgbFrom(12);
    }

    GridRow::GridRow(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        this->x = DEFAULTX;
        this->y = DEFAULTY;
        this->foreColor = rgbFrom(240);
        this->backColor = rgbFrom(12);
        updateConfig();
    }

    GridRow::~GridRow()
    {
        // delete[] content;
        delete maxLen;
    }



    void GridRow::updateConfig()
    {
        delete maxLen;
     
        maxLen = new int[xSize];

        for (int i = 0; i < xSize; i++)
        {
            int t = 0;

            for (int j = 0; j < ySize; j++)
                if ((int)content[j][i].size() > t)
                    t = (int)content[j][i].size();

            maxLen[i] = t;
        }
    }



    void GridRow::gap(int currentLen, int maxLen, int currentRow)
    {
        for (int i = currentLen; i < maxLen; i++)
            cout << " ";

        if (currentRow != xSize - 1)
            cout << " ";
    }



    void GridRow::draw()
    {
        for (int j = 0; j < ySize; j++)
        {
            setCursorPosition(x, y + j);

            for (int i = 0; i < xSize; i++)
            {
                bool d = true;

                if (onDraw != NULL)
                    d = onDraw(content[j][i], j);

                if (d)
                    cout << sFC(foreColor) << sBC(backColor) << content[j][i];

                gap((int)content[j][i].size(), maxLen[i], (int)i);
            }
        }
    }



    int GridRow::getWidth()
    {
        int t = xSize - 1;

        for (int i = 0; i < xSize; i++)
            t += maxLen[i];

        return t;
    }

    int GridRow::getHeight()
    {
        return ySize;
    }



    bool defaultGridRowOnDraw(string content, int row)
    {
        if (row == 0)
        {
            cout << sFC(RGBCOLOR(240));
            cout << sBC(RGBCOLOR(0, 128, 128));
        }
        else
        {
            if (row % 2 == 0)
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(150));
            }
            else
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(100));
            }
        }

        cout << content;

        return false;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SbsGridRow
    // ##

    #pragma region SbsGridRow

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void SbsGridRow::resetDraw()
    {
        current = 0;

        if (onResetDraw != NULL)
            onResetDraw();
    }

    void SbsGridRow::drawNext(string content[], int maxLen[], int xSize)
    {
        setCursorPosition(getX(), getY() + current);

        for (int i = 0; i < xSize; i++)
        {
            bool d = true;

            if (onDrawNext != NULL)
                d = onDrawNext(content[i], current);

            if (d)
                cout << sFC(getForeColor()) << sBC(getBackColor()) << content[i];

            for (int j = (int)content[i].size(); j < maxLen[i]; j++)
                cout << " ";

            if (i != xSize - 1)
                cout << " ";
        }

        current++;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Grid Col
    // ##

    #pragma region Grid Col

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    unsigned GridCol::getX()
    {
        return x;
    }

    void GridCol::setX(unsigned x)
    {
        this->x = x;
    }

    unsigned GridCol::getY()
    {
        return y;
    }

    void GridCol::setY(unsigned y)
    {
        this->y = y;
    }



    void GridCol::setContent(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        updateConfig();
    }

    string** GridCol::getContent()
    {
        return content;
    }



    int GridCol::getXSize()
    {
        return xSize;
    }

    int GridCol::getYSize()
    {
        return ySize;
    }



    void GridCol::setForeColor(RGBCOLOR foreColor)
    {
        this->foreColor = foreColor;
    }

    RGBCOLOR GridCol::getForeColor()
    {
        return foreColor;
    }

    void GridCol::setBackColor(RGBCOLOR backColor)
    {
        this->backColor = backColor;
    }

    RGBCOLOR GridCol::getBackColor()
    {
        return backColor;
    }



    GridCol::GridCol()
    {
        this->content = NULL;
        this->xSize = -1;
        this->ySize = -1;
        this->x = DEFAULTX;
        this->y = DEFAULTY;
        this->foreColor = rgbFrom(240);
        this->backColor = rgbFrom(12);
    }

    GridCol::GridCol(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        this->x = DEFAULTX;
        this->y = DEFAULTY;
        this->foreColor = rgbFrom(240);
        this->backColor = rgbFrom(12);
        updateConfig();
    }

    GridCol::~GridCol()
    {
        // delete[] content;
        delete maxLen;
    }



    void GridCol::updateConfig()
    {
        delete maxLen;

        maxLen = new int[xSize];

        for (int i = 0; i < xSize; i++)
        {
            int t = 0;

            for (int j = 0; j < ySize; j++)
                if ((int)content[j][i].size() > t)
                    t = (int)content[j][i].size();

            maxLen[i] = t;
        }
    }



    void GridCol::gap(int currentLen, int maxLen, int currentCol)
    {
        for (int i = currentLen; i < maxLen; i++)
            cout << " ";

        if (currentCol != xSize - 1)
            cout << " ";
    }



    void GridCol::draw()
    {
        for (int j = 0; j < ySize; j++)
        {
            setCursorPosition(x, y + j);

            for (int i = 0; i < xSize; i++)
            {
                bool d = true;

                if (onDraw != NULL)
                    d = onDraw(content[j][i], i);

                if (d)
                    cout << sFC(foreColor) << sBC(backColor) << content[j][i];

                gap((int)content[j][i].size(), maxLen[i], (int)i);
            }
        }
    }



    int GridCol::getWidth()
    {
        int t = xSize - 1;

        for (int i = 0; i < xSize; i++)
            t += maxLen[i];

        return t;
    }

    int GridCol::getHeight()
    {
        return ySize;
    }



    bool defaultGridColOnDraw(string content, int col)
    {
        if (col == 0)
        {
            cout << sFC(RGBCOLOR(240));
            cout << sBC(RGBCOLOR(0, 128, 128));
        }
        else
        {
            if (col % 2 == 0)
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(150));
            }
            else
            {
                cout << sFC(RGBCOLOR(240));
                cout << sBC(RGBCOLOR(100));
            }
        }

        cout << content;

        return false;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   SbsGridCol
    // ##

    #pragma region SbsGridCol

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void SbsGridCol::resetDraw()
    {
        current = 0;

        if (onResetDraw != NULL)
            onResetDraw();
    }

    void SbsGridCol::drawNext(string content[], int maxLen[], int xSize)
    {
        setCursorPosition(getX(), getY() + current);

        for (int i = 0; i < xSize; i++)
        {
            bool d = true;

            if (onDrawNext != NULL)
                d = onDrawNext(content[i], i);

            if (d)
                cout << sFC(getForeColor()) << sBC(getBackColor()) << content[i];

            for (int j = (int)content[i].size(); j < maxLen[i]; j++)
                cout << " ";

            if (i != xSize - 1)
                cout << " ";
        }

        current++;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
