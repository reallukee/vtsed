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
//               Questo Header Contiene le Definizioni
//               Relative ai Controlli Statitici.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#pragma once

#include "preprocessor.hpp" // Direttive.
#include "common.hpp"       // Common.
#include "console.hpp"      // Console.
#include "vts.hpp"          // VTS.

namespace vtsed
{
    extern "C++"
    {
        // ##
        // ##   Grid Row
        // ##

        #pragma region Grid Row

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        bool VTSED_API defaultGridRowOnDraw(string content, int row);

        //
        //  DESCRIZIONE
        //  ===========
        //
        //  Rappresenta il controllo statico 'GridRow'.
        //
        //  IMPORTANTE! Non vengono effettuati controlli sui puntatori
        //  e non viene effettuato il disposing dei puntatori.
        //
        //  FUNZIONAMENTO
        //  =============
        //
        //  Rappresentazione schematica e riassuntiva del funzionamento
        //  del controllo.
        //
        //  * CALLER: Funzione chiamante (Esempio: 'main()').
        //
        //  +----------+     +--------+
        //  | * CALLER | --> | DRAW   |
        //  +----------+     |        |
        //                   ( onDraw )
        //                   +--------+
        //

        class VTSED_API GridRow
        {

        private:

            int* maxLen = nullptr;

            unsigned x;
            unsigned y;

            string** content = NULL;

            int ySize;
            int xSize;

            RGBCOLOR foreColor;
            RGBCOLOR backColor;

            void updateConfig();

            void gap(int currentLen, int maxLen, int currentCol);

        public:

            const unsigned DEFAULTX = 4;
            const unsigned DEFAULTY = 2;

            GridRow();
            GridRow(string* content[], int xSize, int ySize);
            ~GridRow();

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


        //
        //  DESCRIZIONE
        //  ===========
        //
        //  Rappresenta il controllo statico 'SbsGridRow'.
        //
        //  IMPORTANTE! Non vengono effettuati controlli sui puntatori
        //  e non viene effettuato il disposing dei puntatori.
        //
        //  FUNZIONAMENTO
        //  =============
        //
        //  Rappresentazione schematica e riassuntiva del funzionamento
        //  del controllo.
        //
        //  * CALLER: Funzione chiamante (Esempio: 'main()').
        //
        //  (*** Comportamento di 'GridRow' ***)
        //
        //  +----------+     +------------+
        //  | * CALLER | ~~> | DRAWNEXT   |
        //  +----------+     |            |
        //    \              ( onDrawNext )
        //    \              +------------+
        //    v
        //  +-------------+
        //  | RESETDRAW   |
        //  |             |
        //  ( onResetDraw )
        //  +-------------+
        //

        class SbsGridRow : private GridRow
        {

        private:

            int current;

        public:

            void resetDraw();
            void drawNext(string content[], int maxLen[], int xSize);

            bool(*onDrawNext)(string content, int row) = defaultGridRowOnDraw;
            void(*onResetDraw)() = NULL;

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

        //
        //  DESCRIZIONE
        //  ===========
        //
        //  Rappresenta il controllo statico 'GridCol'.
        //
        //  IMPORTANTE! Non vengono effettuati controlli sui puntatori
        //  e non viene effettuato il disposing dei puntatori.
        //
        //  FUNZIONAMENTO
        //  =============
        //
        //  Rappresentazione schematica e riassuntiva del funzionamento
        //  del controllo.
        //
        //  * CALLER: Funzione chiamante (Esempio: 'main()').
        //
        //  +----------+     +--------+
        //  | * CALLER | --> | DRAW   |
        //  +----------+     |        |
        //                   ( onDraw )
        //                   +--------+
        //

        class VTSED_API GridCol
        {

        private:

            int* maxLen = nullptr;

            unsigned x;
            unsigned y;

            string** content = NULL;

            int ySize;
            int xSize;

            RGBCOLOR foreColor;
            RGBCOLOR backColor;

            void updateConfig();
            
            void gap(int currentLen, int maxLen, int currentRow);

        public:

            const unsigned DEFAULTX = 4;
            const unsigned DEFAULTY = 2;

            GridCol();
            GridCol(string* content[], int xSize, int ySize);
            ~GridCol();

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


        //
        //  DESCRIZIONE
        //  ===========
        //
        //  Rappresenta il controllo statico 'SbsGridCol'.
        //
        //  IMPORTANTE! Non vengono effettuati controlli sui puntatori
        //  e non viene effettuato il disposing dei puntatori.
        //
        //  FUNZIONAMENTO
        //  =============
        //
        //  Rappresentazione schematica e riassuntiva del funzionamento
        //  del controllo.
        //
        //  * CALLER: Funzione chiamante (Esempio: 'main()').
        //
        //  (*** Comportamento di 'GridCol' ***)
        //
        //  +----------+     +------------+
        //  | * CALLER | ~~> | DRAWNEXT   |
        //  +----------+     |            |
        //    \              ( onDrawNext )
        //    \              +------------+
        //    v
        //  +-------------+
        //  | RESETDRAW   |
        //  |             |
        //  ( onResetDraw )
        //  +-------------+
        //

        class SbsGridCol : private GridCol
        {

        private:

            int current;

        public:

            void resetDraw();
            void drawNext(string content[], int maxLen[], int xSize);

            bool(*onDrawNext)(string content, int col) = defaultGridColOnDraw;
            void(*onResetDraw)() = NULL;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion
    }
}
