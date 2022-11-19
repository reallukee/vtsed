//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    DYNAMIC CONTROL
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//

#pragma once

//
//  /!\ IMPORTANTE!
//
//  #define VTSED_LIBRARY
//
//  De commentare la costante VTSED_LIBRARY o
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
        // ##   Single Control
        // ##

        #pragma region Single Control

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        class VTSED_API singleControl
        {

        private:

            short x = 4;
            short y = 2;
            string* options = NULL;
            bool* optionsState = NULL;
            int* selectedOptions = NULL;
            int currentOption = 1;
            int optionsCount = 0;
            RGBCOLOR optionForeColor = rgbFrom(240);
            RGBCOLOR optionBackColor = rgbFrom(12);
            RGBCOLOR selectedOptionForeColor = rgbFrom(65, 130, 115);
            RGBCOLOR selectedOptionBackColor = rgbFrom(40, 80, 70);
            RGBCOLOR currentOptionForeColor = rgbFrom(10, 70, 125);
            RGBCOLOR currentOptionBackColor = rgbFrom(35, 170, 240);
            RGBCOLOR disabledOptionForeColor = rgbFrom(120);
            RGBCOLOR disabledOptionBackColor = rgbFrom(12);

            int loop();

        public:

            singleControl();
            ~singleControl();

            void setX(int value);
            int getX();
            void setY(int value);
            int getY();
            void setOptions(string* value);
            string* getOptions();
            void setOptionsState(bool* value);
            bool* getOptionsState();
            void setSelectedOption(int value);
            int getSelectedOption();
            void setCurrentOption(int value);
            int getCurrentOption();
            void setOptionsCount(int value);
            int getOptionsCount();
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
            virtual void draw();
            void up();
            void down();
            void top();
            void bottom();

            void(*onCallStart)() = nullptr;
            void(*onCallEnd)() = nullptr;
            bool(*onDraw)(int index, string option, bool state, 
                bool selected, bool current) = nullptr;

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

        class VTSED_API listBox : public singleControl
        {

        private:

            char separator = '-';

        public:

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

        class multiControl
        {

        private:

            short x = 4;
            short y = 2;
            string* options = NULL;
            bool* optionsState = NULL;
            int* selectedOptions = NULL;
            int currentOption = 1;
            int optionsCount = 0;
            RGBCOLOR optionForeColor = rgbFrom(240);
            RGBCOLOR optionBackColor = rgbFrom(12);
            RGBCOLOR selectedOptionForeColor = rgbFrom(65, 130, 115);
            RGBCOLOR selectedOptionBackColor = rgbFrom(40, 80, 70);
            RGBCOLOR currentOptionForeColor = rgbFrom(10, 70, 125);
            RGBCOLOR currentOptionBackColor = rgbFrom(35, 170, 240);
            RGBCOLOR disabledOptionForeColor = rgbFrom(120);
            RGBCOLOR disabledOptionBackColor = rgbFrom(12);

            int* loop();

        public:

            multiControl();
            ~multiControl();

            void setX(int value);
            int getX();
            void setY(int value);
            int getY();
            void setOptions(string* value);
            string* getOptions();
            void setOptionsState(bool* value);
            bool* getOptionsState();
            void setSelectedOptions(int* value);
            int* getSelectedOptions();
            void setCurrentOption(int value);
            int getCurrentOption();
            void setOptionsCount(int value);
            int getOptionsCount();
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

            void(*onCallStart)() = nullptr;
            void(*onCallEnd)() = nullptr;
            bool(*onDraw)(int index, string option, bool state,
                bool selected, bool current) = nullptr;

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

        class checkListBox : public multiControl
        {

        private:

            char separator = '-';

        public:

            void setSeparator(char value);
            char getSeparator();

            void draw() override;

        };

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #pragma endregion

        #endif
    }
}
