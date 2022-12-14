//
//  VTSEd
//
//  Migliora la tua Applicazione Console!
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/vtsed/
//  Descrizione:    CONSOLE
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//
//  Leggere README.md per maggiori informazioni.
//

#include "pch.hpp"

#include "console.hpp"

namespace vtsed
{
    #if defined(_WIN32) || defined(_WIN64)  // _WIN32 || _WIN64

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
        setCursorPosition((csbi.dwSize.X - (int)str.size()) / 2, y);
        cout << str;
    }


    void writeAtCenter(int y, char* str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition((csbi.dwSize.X - (int)strlen(str)) / 2, y);
        cout << str;
    }


    void writeAtRight(int y, string str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition(csbi.dwSize.X - (int)str.size(), y);
        cout << str;
    }


    void writeAtRight(int y, char* str)
    {
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition(csbi.dwSize.X - (int)strlen(str), y);
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

    #endif  // _WIN32 || _WIN64
}
