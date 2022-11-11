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
    }
}
