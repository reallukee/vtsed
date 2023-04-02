//
//  VTSEd.NET (VTSEd per .NET)
//
//  Migliora la tua Applicazione Console C++!
//
//  Questo File fa Parte del Progetto VTSEd
//  ed è Distribuito sotto Licenza MIT.
//
//  GitHub:      https://github.com/reallukee/vtsed/
//  Autore:      Luca Pollicino
//  Descrizione: STATIC CONTROL
//  Versione:    1.1.0
//
//  Leggere README.md per Maggiori Informazioni.
//

#include "scontrols.hxx"

namespace VTSEd
{
    // ##
    // ##   GridRow
    // ##

    #pragma region GridRow

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    GridRow::GridRow()
    {
        ptr = new vtsed::GridRow();
    }

    GridRow::~GridRow()
    {
        delete ptr;
    }



    int GridRow::X::get()
    {
        return ptr->getX();
    }

    void GridRow::X::set(int Value)
    {
        ptr->setX(Value);
    }



    int GridRow::Y::get()
    {
        return ptr->getY();
    }

    void GridRow::Y::set(int Value)
    {
        ptr->setY(Value);
    }



    int GridRow::GetXSize()
    {
        return ptr->getXSize();
    }

    int GridRow::GetYSize()
    {
        return ptr->getYSize();
    }



    RGBColor^ GridRow::ForeColor::get()
    {
        return gcnew RGBColor(
            ptr->getForeColor().r,
            ptr->getForeColor().g,
            ptr->getForeColor().b
        );
    }

    void GridRow::ForeColor::set(RGBColor^ Value)
    {
        ptr->setForeColor(RGBCOLOR(Value->R, Value->G, Value->B));
    }



    RGBColor^ GridRow::BackColor::get()
    {
        return gcnew RGBColor(
            ptr->getBackColor().r,
            ptr->getBackColor().g,
            ptr->getBackColor().b
        );
    }

    void GridRow::BackColor::set(RGBColor^ Value)
    {
        ptr->setBackColor(RGBCOLOR(Value->R, Value->G, Value->B));
    }



    int GridRow::GetWidth()
    {
        return ptr->getWidth();
    }

    int GridRow::GetHeight()
    {
        return ptr->getHeight();
    }



    void GridRow::Draw()
    {
        ptr->draw();
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

    SbsGridRow::SbsGridRow()
    {
        ptr = new vtsed::SbsGridRow();
    }

    SbsGridRow::~SbsGridRow()
    {
        delete ptr;
    }



    void SbsGridRow::ResetDraw()
    {
        ptr->resetDraw();
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion


    // ##
    // ##   GridCol
    // ##

    #pragma region GridCol

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    GridCol::GridCol()
    {
        ptr = new vtsed::GridCol();
    }

    GridCol::~GridCol()
    {
        delete ptr;
    }



    int GridCol::X::get()
    {
        return ptr->getX();
    }

    void GridCol::X::set(int Value)
    {
        ptr->setX(Value);
    }



    int GridCol::Y::get()
    {
        return ptr->getY();
    }

    void GridCol::Y::set(int Value)
    {
        ptr->setY(Value);
    }



    int GridCol::GetXSize()
    {
        return ptr->getXSize();
    }

    int GridCol::GetYSize()
    {
        return ptr->getYSize();
    }



    RGBColor^ GridCol::ForeColor::get()
    {
        return gcnew RGBColor(
            ptr->getForeColor().r,
            ptr->getForeColor().g,
            ptr->getForeColor().b
        );
    }

    void GridCol::ForeColor::set(RGBColor^ Value)
    {
        ptr->setForeColor(RGBCOLOR(Value->R, Value->G, Value->B));
    }



    RGBColor^ GridCol::BackColor::get()
    {
        return gcnew RGBColor(
            ptr->getBackColor().r,
            ptr->getBackColor().g,
            ptr->getBackColor().b
        );
    }

    void GridCol::BackColor::set(RGBColor^ Value)
    {
        ptr->setBackColor(RGBCOLOR(Value->R, Value->G, Value->B));
    }



    int GridCol::GetWidth()
    {
        return ptr->getWidth();
    }

    int GridCol::GetHeight()
    {
        return ptr->getHeight();
    }



    void GridCol::Draw()
    {
        ptr->draw();
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

    SbsGridCol::SbsGridCol()
    {
        ptr = new vtsed::SbsGridCol();
    }

    SbsGridCol::~SbsGridCol()
    {
        delete ptr;
    }



    void SbsGridCol::ResetDraw()
    {
        ptr->resetDraw();
    }

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    #pragma endregion
}
