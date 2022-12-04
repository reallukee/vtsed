//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    STATIC CONTROL
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//

#include "pch.h"

#include "scontrols.hpp"

namespace vtsed
{
    #if defined(_WIN32) || defined(_WIN64)

    // ##
    // ##   Grid Row
    // ##

    #pragma region Grid Row

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    unsigned gridRow::getX()
    {
        return x;
    }


    void gridRow::setX(unsigned x)
    {
        this->x = x;
    }


    unsigned gridRow::getY()
    {
        return y;
    }


    void gridRow::setY(unsigned y)
    {
        this->y = y;
    }


    void gridRow::setContent(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        updateConfig();
    }


    string** gridRow::getContent()
    {
        return content;
    }


    int gridRow::getXSize()
    {
        return xSize;
    }


    int gridRow::getYSize()
    {
        return ySize;
    }


    void gridRow::setForeColor(RGBCOLOR foreColor)
    {
        this->foreColor = foreColor;
    }


    RGBCOLOR gridRow::getForeColor()
    {
        return foreColor;
    }


    void gridRow::setBackColor(RGBCOLOR backColor)
    {
        this->backColor = backColor;
    }


    RGBCOLOR gridRow::getBackColor()
    {
        return backColor;
    }


    gridRow::gridRow()
    {
        this->content = NULL;
        this->xSize = -1;
        this->ySize = -1;
        this->x = defaultX;
        this->y = defaultY;
    }


    gridRow::gridRow(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        updateConfig();
    }


    gridRow::~gridRow()
    {
        // delete[] content;
        delete maxLen;
    }


    void gridRow::updateConfig()
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


    void gridRow::gap(int currentLen, int maxLen, int currentCol)
    {
        for (int i = currentLen; i < maxLen; i++)
            cout << " ";

        if (currentCol != xSize - 1)
            cout << " ";
    }


    void gridRow::draw()
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


    int gridRow::getWidth()
    {
        int t = xSize - 1;

        for (int i = 0; i < xSize; i++)
            t += maxLen[i];

        return t;
    }


    int gridRow::getHeight()
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


    void sbsGridRow::resetDraw()
    {
        current = 0;
    }


    void sbsGridRow::drawNext(string content[], int maxLen[], int xSize)
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

    unsigned gridCol::getX()
    {
        return x;
    }


    void gridCol::setX(unsigned x)
    {
        this->x = x;
    }


    unsigned gridCol::getY()
    {
        return y;
    }


    void gridCol::setY(unsigned y)
    {
        this->y = y;
    }


    void gridCol::setContent(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        updateConfig();
    }


    string** gridCol::getContent()
    {
        return content;
    }


    int gridCol::getXSize()
    {
        return xSize;
    }


    int gridCol::getYSize()
    {
        return ySize;
    }


    void gridCol::setForeColor(RGBCOLOR foreColor)
    {
        this->foreColor = foreColor;
    }


    RGBCOLOR gridCol::getForeColor()
    {
        return foreColor;
    }


    void gridCol::setBackColor(RGBCOLOR backColor)
    {
        this->backColor = backColor;
    }


    RGBCOLOR gridCol::getBackColor()
    {
        return backColor;
    }


    gridCol::gridCol()
    {
        this->content = NULL;
        this->xSize = -1;
        this->ySize = -1;
        this->x = defaultX;
        this->y = defaultY;
    }


    gridCol::gridCol(string* content[], int xSize, int ySize)
    {
        this->content = content;
        this->xSize = xSize;
        this->ySize = ySize;
        updateConfig();
    }


    gridCol::~gridCol()
    {
        // delete[] content;
        delete maxLen;
    }


    void gridCol::updateConfig()
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


    void gridCol::gap(int currentLen, int maxLen, int currentCol)
    {
        for (int i = currentLen; i < maxLen; i++)
            cout << " ";

        if (currentCol != xSize - 1)
            cout << " ";
    }


    void gridCol::draw()
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


    int gridCol::getWidth()
    {
        int t = xSize - 1;

        for (int i = 0; i < xSize; i++)
            t += maxLen[i];

        return t;
    }


    int gridCol::getHeight()
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


    void sbsGridCol::resetDraw()
    {
        current = 0;
    }


    void sbsGridCol::drawNext(string content[], int maxLen[], int xSize)
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

    #endif
}
