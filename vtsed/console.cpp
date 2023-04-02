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
//  Descrizione: CONSOLE
//               Questo File Contiene le Implementazioni
//               Relative ai Controlli Statitici.
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//


// Costanti e Direttive per il Preprocessore.

#pragma region Header

#include "pch.hpp"      // Intestazioni Precompilate.

#include "console.hpp"  // Header di Riferimento.

#pragma endregion


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
#ifdef WIN // WIN
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        // Imposto la posizione del cursore.
        SetConsoleCursorPosition(hOut, COORD{ (short)x, (short)y });
#endif  // ! WIN

#ifdef UNIX // UNIX
        setCursorPositionCUP(x, y);
#endif  // ! UNIX
    }


#ifdef WIN  // WIN
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
#endif  // ! WIN


#ifdef UNIX // UNIX
    void* getCursorPosition()
    {
        return NULL;
    }
#endif  // ! UNIX
    

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


    void writeAtCenter(int y, string str)
    {
#ifdef WIN  // WIN
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition((csbi.dwSize.X - (int)str.size()) / 2, y);
        cout << str;
#endif  // ! WIN
    }


    void writeAtRight(int y, string str)
    {
#ifdef WIN  // WIN
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbi);
        setCursorPosition(csbi.dwSize.X - (int)str.size(), y);
        cout << str;
#endif  // ! WIN
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
#ifdef WIN // WIN
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbiInfo);
        SetConsoleTextAttribute(hOut, c);
#endif  // ! WIN
    }


    void setBackgroundColorWin32(int c)
    {
#ifdef WIN // WIN
        // Ottengo l'output standard.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
        // Ottengo le informazioni del buffer dello screen.
        GetConsoleScreenBufferInfo(hOut, &csbiInfo);
        SetConsoleTextAttribute(hOut, c * 16);
#endif  // ! WIN
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
