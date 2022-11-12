using System;
using System.Runtime.InteropServices;

namespace VTSEd
{
    public class VTS
    {
        // ##
        // ##   Basics
        // ##

        #region Basics

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern bool initConsole();


        [DllImport(Core.DLL)]
        public static extern bool dinitConsole();


        [DllImport(Core.DLL)]
        public static extern bool enableVTS();


        [DllImport(Core.DLL)]
        public static extern bool disableVTS();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Simple Cursor Positioning
        // ##

        #region Simple Cursor Positioning

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void reverseCursorIndex();


        [DllImport(Core.DLL)]
        public static extern void saveCursor();


        [DllImport(Core.DLL)]
        public static extern void restoreCursor();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Cursor Positioning
        // ##

        #region Cursor Positioning

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void cursorUp(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorDown(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorRight(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorLeft(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorUpLine(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorPreviousLine(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorHorizontalAbs(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorVerticalAbs(int n);


        [DllImport(Core.DLL)]
        public static extern void setCursorPositionCUP(int x, int y);


        [DllImport(Core.DLL)]
        public static extern void setCursorPositionHVP(int x, int y);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Cursor Visibility
        // ##

        #region Cursor Visibility

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void cursorBlinking(bool value);


        [DllImport(Core.DLL)]
        public static extern void cursorVisible(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Cursor Shape
        // ##

        #region Cursor Shape

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        public const int CURSOR_SHAPE_USER_SHAPE           = 0;
        public const int CURSOR_SHAPE_BLINKING_BLOCK       = 1;
        public const int CURSOR_SHAPE_STEADY_BLOCK         = 2;
        public const int CURSOR_SHAPE_BLINKING_UNDERLINE   = 3;
        public const int CURSOR_SHAPE_STEADY_UNDERLINE     = 4;
        public const int CURSOR_SHAPE_BLINKING_BAR         = 5;
        public const int CURSOR_SHAPE_STEADY_BAR           = 6;


        [DllImport(Core.DLL)]
        public static extern void cursorShape(int c);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Viewport Positioning
        // ##

        #region Viewport Positioning

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void scrollUp(int n);


        [DllImport(Core.DLL)]
        public static extern void scrollDown(int n);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Text Modification
        // ##

        #region Text Modification

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        public const int TEXT_MODIFICATION_ERASE_FROM_CURRENT  = 0;
        public const int TEXT_MODIFICATION_ERASE_FROM_BEGIN    = 1;
        public const int TEXT_MODIFICATION_ERASE_ENTIRE        = 2;


        [DllImport(Core.DLL)]
        public static extern void insertCharacter(int n);


        [DllImport(Core.DLL)]
        public static extern void deleteCharacter(int n);


        [DllImport(Core.DLL)]
        public static extern void eraseCharacter(int n);


        [DllImport(Core.DLL)]
        public static extern void insertLine(int n);


        [DllImport(Core.DLL)]
        public static extern void deleteLine(int n);


        [DllImport(Core.DLL)]
        public static extern void eraseInDisplay(int n);


        [DllImport(Core.DLL)]
        public static extern void eraseInLine(int n);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Mode Changes
        // ##

        #region Mode Changes

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void keypadApplicationMode(bool value);


        [DllImport(Core.DLL)]
        public static extern void cursorKeysApplicationMode(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Query State
        // ##

        #region Query State

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void reportCursorPosition();


        [DllImport(Core.DLL)]
        public static extern void deviceAttributes();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Tabs
        // ##

        #region Tabs

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void horizontalTab();


        [DllImport(Core.DLL)]
        public static extern void cursorHorizontalTab(int n);


        [DllImport(Core.DLL)]
        public static extern void cursorBackwardsTab(int n);


        [DllImport(Core.DLL)]
        public static extern void tabClearCurrentColumn();


        [DllImport(Core.DLL)]
        public static extern void tabClearAllColumns();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Designate Character
        // ##

        #region Designate Character

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        public const char DC_BOTTOM_LEFT   ='\x6A';    // ┘    j
        public const char DC_TOP_LEFT      = '\x6B';    // ┐    k
        public const char DC_TOP_RIGHT     = '\x6C';    // ┌    l
        public const char DC_BOTTOM_RIGHT  = '\x6D';    // └    m
        public const char DC_CENTER        = '\x6E';    // ┼    n
        public const char DC_TOP           = '\x71';    // ─    q
        public const char DC_LEFT_CENTER   = '\x74';    // ├    t
        public const char DC_RIGHT_CENTER  = '\x75';    // ┤    u
        public const char DC_BOTTOM_CENTER = '\x76';    // ┴    v
        public const char DC_TOP_CENTER    = '\x77';    // ┬    w
        public const char DC_LEFT          = '\x78';    // │    x


        [DllImport(Core.DLL)]
        public static extern void designateCharacter(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Scrolling Margins
        // ##

        #region Scrolling Margin

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////
        ///
        [DllImport(Core.DLL)]
        public static extern void scrollingMargin(int t, int b);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Alternate Screen Buffer
        // ##

        #region Alternate Screen Buffer

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void alternateScreenBuffer(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Window Width
        // ##

        #region Window Width

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void windowWidth(bool value);

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion


        // ##
        // ##   Soft Reset
        // ##

        #region Soft Reset

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        [DllImport(Core.DLL)]
        public static extern void softReset();

        //////////////////////////////////////////////////
        //////////////////////////////////////////////////

        #endregion
    }
}
