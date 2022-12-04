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

#pragma once

//
//  /!\ IMPORTANTE!
//
//  #define VTSED_LIBRARY
//
//  Decommentare la costante VTSED_LIBRARY o
//  definire la costante VTSED_LIBRARY nella
//  sezione "C/C++ > PREPROCESSORE" per
//  compilare questo HEADER con destinazione
//  Dynamic Link Library (DLL).
//
//  Quando definire VTSED_LIBARY?
//
//  1.  Si sta compilando VTSED come una
//      Dynamic Link Library (DLL).
//  2.  Si sta compilando un progetto che
//      utilizza direttamente il codice di
//      VTSED.
//
//  Quando non definire VTSED_LIBRARY?
// 
//  1.  Si sta compilando VTSED come una
//      Static Library (LIB).
//  2.  Si sta compilando un progetto che
//      utilizza indirettamente il codice
//      di VTSED.
//

#ifdef VTSED_LIBRARY   // VTSED_LIBRARY
#define VTSED_API __declspec(dllexport)
#else
#define VTSED_API __declspec(dllimport)
#endif  // VTSED_LIBRARY

// Standard.
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
// Solo Windows.
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
    extern "C++"
    {
        #if defined(_WIN32) || defined(_WIN64)

        // ##
        // ##   Grid Row
        // ##

        #pragma region Grid Row

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        bool VTSED_API defaultGridRowOnDraw(string content, int row);

        class VTSED_API gridRow
        {

        private:

            int* maxLen = nullptr;

            unsigned x = defaultX;
            unsigned y = defaultY;
            string** content = NULL;
            int ySize = -1;
            int xSize = -1;
            RGBCOLOR foreColor = rgbFrom(240);
            RGBCOLOR backColor = rgbFrom(12);

            void updateConfig();
            void gap(int currentLen, int maxLen, int currentCol);

        public:

            const unsigned defaultX = 4;
            const unsigned defaultY = 2;

            gridRow();
            gridRow(string* content[], int xSize, int ySize);

            ~gridRow();

            void setX(unsigned x);
            unsigned getX();

            void setY(unsigned y);
            unsigned getY();

            void setContent(string* content[], int xSize, int ySize);
            string** getContent();

            int getXSize();

            int getYSize();

            void setForeColor(RGBCOLOR foreColor);
            RGBCOLOR getForeColor();

            void setBackColor(RGBCOLOR backColor);
            RGBCOLOR getBackColor();

            int getWidth();

            int getHeight();

            void draw();

            bool(*onDraw)(string content, int row) = defaultGridRowOnDraw;

        };


        class sbsGridRow : private gridRow
        {

        private:

            int current;

        public:

            void resetDraw();
            void drawNext(string content[], int maxLen[], int xSize);

            bool(*onDrawNext)(string content, int row) = defaultGridRowOnDraw;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Grid Col
        // ##

        #pragma region Grid Col

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        bool VTSED_API defaultGridColOnDraw(string content, int col);

        class VTSED_API gridCol
        {

        private:

            int* maxLen = nullptr;

            unsigned x = defaultX;
            unsigned y = defaultY;
            string** content = NULL;
            int ySize = -1;
            int xSize = -1;
            RGBCOLOR foreColor = rgbFrom(240);
            RGBCOLOR backColor = rgbFrom(12);

            void updateConfig();
            void gap(int currentLen, int maxLen, int currentCol);

        public:

            const unsigned defaultX = 4;
            const unsigned defaultY = 2;

            gridCol();
            gridCol(string* content[], int xSize, int ySize);

            ~gridCol();

            void setX(unsigned x);
            unsigned getX();

            void setY(unsigned y);
            unsigned getY();

            void setContent(string* content[], int xSize, int ySize);
            string** getContent();

            int getXSize();

            int getYSize();

            void setForeColor(RGBCOLOR foreColor);
            RGBCOLOR getForeColor();

            void setBackColor(RGBCOLOR backColor);
            RGBCOLOR getBackColor();

            int getWidth();

            int getHeight();

            void draw();

            bool(*onDraw)(string content, int col) = defaultGridColOnDraw;

        };


        class sbsGridCol : private gridCol
        {

        private:

            int current;

        public:

            void resetDraw();
            void drawNext(string content[], int maxLen[], int xSize);

            bool(*onDrawNext)(string content, int col) = defaultGridColOnDraw;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion

        #endif
    }
}
