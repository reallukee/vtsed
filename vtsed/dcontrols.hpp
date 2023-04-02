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
//  Descrizione: DINAMIC CONTROL
//               Questo Header Contiene le Definizioni
//               Relative ai Controlli Dinamici.
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

#ifdef WIN // WIN

        // ##
        // ##   Single Control
        // ##

        #pragma region Single Control

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        //
        //  DESCRIZIONE
        //  ===========
        //
        //  Rappresenta la classe base 'SingleControl' che permette la
        //  creazione di un controllo dinamico a restituzione singola.
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
        //  +----------+
        //  | * CALLER |
        //  +----------+
        //    ^
        //    |
        //  +-------------+     +------------------+     +--------+
        //  | CALL        | <-> | LOOP             | --> | DRAW   |
        //  |             |     |                  |     |        |
        //  ( onCallStart )     ( onSelectedChange )     ( onDraw )
        //  ( onCallEnd   )     ( onCurrentChange  )     +--------+
        //  +-------------+     ( onKnownCommand   )
        //                      ( onUnknownCommand )
        //                      +------------------+
        //                        |
        //                        v
        //  +--------------------------+
        //  | UP, DOWN, TOP, BOTTOM... |
        //  +--------------------------+
        //

        class VTSED_API SingleControl
        {

        private:

            unsigned short x;
            unsigned short y;

            int optionsCount;

            string* options = NULL;
            bool* optionsState = NULL;
            int* selectedOptions = NULL;

            int currentOption;

            bool allowInterruption;

            RGBCOLOR optionForeColor;
            RGBCOLOR optionBackColor;
            RGBCOLOR selectedOptionForeColor;
            RGBCOLOR selectedOptionBackColor;
            RGBCOLOR currentOptionForeColor;
            RGBCOLOR currentOptionBackColor;
            RGBCOLOR disabledOptionForeColor;
            RGBCOLOR disabledOptionBackColor;

            int loop();

        public:

            const int UPCOMMAND             = 72;
            const int DOWNCOMMAND           = 80;
            const int TOPCOMMAND            = 73;
            const int BOTTOMCOMMAND         = 81;
            const int ENDCALLCOMMAND        = 28;
            const int INTERRUPTCALLCOMMAND  = 27;
            const int INTERRUPTIONCODE      = -123;

            const unsigned DEFAULTX = 4;
            const unsigned DEFAULTY = 2;

            SingleControl();
            ~SingleControl();

            void setX(unsigned value);
            unsigned getX();
            void setY(unsigned value);
            unsigned getY();

            void setOptionsCount(int value);
            int getOptionsCount();

            void setOptions(string* value);
            string* getOptions();
            void setOptionsState(bool* value);
            bool* getOptionsState();
            void setSelectedOption(int value);
            int getSelectedOption();

            void setCurrentOption(int value);
            int getCurrentOption();

            int firstIndex();
            int lastIndex();

            void setAllowInterruption(bool value);
            bool getAllowInterruption();

            void setOptionForeColor(RGBCOLOR value);
            RGBCOLOR getOptionForeColor();
            void setOptionBackColor(RGBCOLOR value);
            RGBCOLOR getOptionBackColor();
            void setSelectedOptionForeColor(RGBCOLOR value);
            RGBCOLOR getSelectedOptionForeColor();
            void setSelectedOptionBackColor(RGBCOLOR value);
            RGBCOLOR getSelectedOptionBackColor();
            void setCurrentOptionForeColor(RGBCOLOR value);
            RGBCOLOR getCurrentOptionForeColor();
            void setCurrentOptionBackColor(RGBCOLOR value);
            RGBCOLOR getCurrentOptionBackColor();
            void setDisabledOptionForeColor(RGBCOLOR value);
            RGBCOLOR getDisabledOptionForeColor();
            void setDisabledOptionBackColor(RGBCOLOR value);
            RGBCOLOR getDisabledOptionBackColor();

            int call();
            virtual void draw() = 0;
            void up();
            void down();
            void top();
            void bottom();

            void(*onCallStart)() = NULL;
            void(*onCallEnd)() = NULL;
            void(*onSelectedChange)(int selected) = NULL;
            void(*onCurrentChange)(int current) = NULL;
            void(*onKnownCommand)(char command) = NULL;
            void(*onUnknownCommand)(char command) = NULL;
            bool(*onDraw)(int index, string option, bool state,
                bool selected, bool current) = NULL;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   List Box
        // ##

        #pragma region List Box

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        class VTSED_API ListBox : public SingleControl
        {

        private:

            char separator;

        public:

            ListBox();

            void setSeparator(char value);
            char getSeparator();

            void draw() override;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Multi Control
        // ##

        #pragma region Multi Control

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        //
        //  DESCRIZIONE
        //  ===========
        //
        //  Rappresenta la classe base 'MultiControl' che permette la
        //  creazione di un controllo dinamico a restituzione multipla.
        //
        //  FUNZIONAMENTO
        //  =============
        //
        //  Rappresentazione schematica e riassuntiva del funzionamento
        //  del controllo.
        //
        //  * CALLER: Funzione chiamante (Esempio: 'main()').
        //
        //  +----------+
        //  | * CALLER |
        //  +----------+
        //    ^
        //    |
        //  +-------------+     +------------------+     +--------+
        //  | CALL        | <-> | LOOP             | --> | DRAW   |
        //  |             |     |                  |     |        |
        //  ( onCallStart )     ( onSelectedChange )     ( onDraw )
        //  ( onCallEnd   )     ( onCurrentChange  )     +--------+
        //  +-------------+     ( onKnownCommand   )
        //                      ( onUnknownCommand )
        //                      +------------------+
        //                        |
        //                        v
        //  +--------------------------+
        //  | UP, DOWN, TOP, BOTTOM... |
        //  +--------------------------+
        //

        class VTSED_API MultiControl
        {

        private:

            unsigned x;
            unsigned y;

            int optionsCount;

            string* options = NULL;
            bool* optionsState = NULL;
            int* selectedOptions = NULL;

            int currentOption;

            bool allowInterruption;

            RGBCOLOR optionForeColor;
            RGBCOLOR optionBackColor;
            RGBCOLOR selectedOptionForeColor;
            RGBCOLOR selectedOptionBackColor;
            RGBCOLOR currentOptionForeColor;
            RGBCOLOR currentOptionBackColor;
            RGBCOLOR disabledOptionForeColor;
            RGBCOLOR disabledOptionBackColor;

            int* loop();

        public:
            
            const int UPCOMMAND = 72;
            const int DOWNCOMMAND = 80;
            const int TOPCOMMAND = 73;
            const int BOTTOMCOMMAND = 81;
            const int ENDCALLCOMMAND = 28;
            const int INTERRUPTCALLCOMMAND = 27;
            const int INTERRUPTIONCODE = -123;

            const unsigned DEFAULTX = 4;
            const unsigned DEFAULTY = 2;

            MultiControl();
            ~MultiControl();

            void setX(unsigned value);
            unsigned getX();
            void setY(unsigned value);
            unsigned getY();

            void setOptionsCount(int value);
            int getOptionsCount();

            void setOptions(string* value);
            string* getOptions();
            void setOptionsState(bool* value);
            bool* getOptionsState();
            void setSelectedOptions(int* value);
            int* getSelectedOptions();

            void setCurrentOption(int value);
            int getCurrentOption();

            int firstIndex();
            int lastIndex();

            void setAllowInterruption(bool value);
            bool getAllowInterruption();

            void setOptionForeColor(RGBCOLOR value);
            RGBCOLOR getOptionForeColor();

            void setOptionBackColor(RGBCOLOR value);
            RGBCOLOR getOptionBackColor();

            void setSelectedOptionForeColor(RGBCOLOR value);
            RGBCOLOR getSelectedOptionForeColor();

            void setSelectedOptionBackColor(RGBCOLOR value);
            RGBCOLOR getSelectedOptionBackColor();

            void setCurrentOptionForeColor(RGBCOLOR value);
            RGBCOLOR getCurrentOptionForeColor();

            void setCurrentOptionBackColor(RGBCOLOR value);
            RGBCOLOR getCurrentOptionBackColor();

            void setDisabledOptionForeColor(RGBCOLOR value);
            RGBCOLOR getDisabledOptionForeColor();

            void setDisabledOptionBackColor(RGBCOLOR value);
            RGBCOLOR getDisabledOptionBackColor();

            int* call();
            virtual void draw();
            void up();
            void down();
            void top();
            void bottom();

            void(*onCallStart)() = NULL;
            void(*onCallEnd)() = NULL;
            void(*onSelectedChange)(int selected) = NULL;
            void(*onCurrentChange)(int current) = NULL;
            void(*onKnownCommand)(char command) = NULL;
            void(*onUnknownCommand)(char command) = NULL;
            bool(*onDraw)(int index, string option, bool state,
                bool selected, bool current) = NULL;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion


        // ##
        // ##   Check List Box
        // ##

        #pragma region Check List Box

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        class VTSED_API CheckListBox : public MultiControl
        {

        private:

            char separator;

        public:

            CheckListBox();

            void setSeparator(char value);
            char getSeparator();

            void draw() override;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion

#endif  // ! WIN

    }
}
