/*
    VTSEd

    Questo progetto è distribuito sotto licenza MIT.
    Questo progetto è disponibile su GitHub.

    Repository:     https://github.com/reallukee/vtsed/
    Descrizione:    CONSOLE
    Autore:         Realluke (https://github.com/reallukee/)
    Versione:       1.0.0
*/

#include "pch.h"

#include "console.hpp"

namespace vtsed
{
    // ##
    // ##   Cursor
    // ##

    #pragma region Cursor

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setCursorPosition(int x, int y)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        // Imposto la posizione del cursore.
        SetConsoleCursorPosition(hOut, COORD{ (short)x, (short)y });
    }


    COORD getCursorPosition()
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        // Ottengo la posizione del cursore.
        return COORD{ csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Write At
    // ##

    #pragma region Write At

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void writeAt(int x, int y, string str)
    {
        setCursorPosition(x, y);
        cout << str;
    }


    void writeAt(int x, int y, char* str)
    {
        setCursorPosition(x, y);
        cout << str;
    }


    void writeAtCenter(int y, string str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition((csbi.dwSize.X - str.size()) / 2, y);
        cout << str;
    }


    void writeAtCenter(int y, char* str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition((csbi.dwSize.X - strlen(str)) / 2, y);
        cout << str;
    }


    void writeAtRight(int y, string str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition(csbi.dwSize.X - str.size(), y);
        cout << str;
    }


    void writeAtRight(int y, char* str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition(csbi.dwSize.X - strlen(str), y);
        cout << str;
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   Color
    // ##

    #pragma region Color

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    void setForegroundColorWin32(int c)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbiInfo);
        SetConsoleTextAttribute(hOut, c);
    }


    void setBackgroundColorWin32(int c)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbiInfo);
        SetConsoleTextAttribute(hOut, c * 16);
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
