[Documentazione](../DOCS.md)

# VTS

Virtual Terminal Sequences.



<!--

    Informazioni

-->

# Informazioni

| Nome                    | Sorgente  |
| :---------------------- | :-------: |
| Intestazione Nativa     | `vts.hpp` |
| Implementazione Nativa  | `vts.cpp` |
| Intestazione Wrapper    | `vts.hxx` |
| Implementazione Wrapper | `vts.cxx` |



<!--

    Indice

-->

# Indice

- [Metodi](#metodi)
- [Costanti](#costanti)



<!--

    Metodi

-->

# Metodi

- (`bool`) `initConsole()`
- (`bool`) `dinitConsole()`
- (`bool`) `enableVTS()`
- (`bool`) `disableVTS()`
- (`void`) `reverseCursorIndex()`
- (`void`) `saveCursor()`
- (`void`) `restoreCursor()`
- (`void`) `cursorUp(unsigned)`
- (`void`) `cursorDown(unsigned)`
- (`void`) `cursorRight(unsigned)`
- (`void`) `cursorLeft(unsigned)`
- (`void`) `cursorUpLine(unsigned)`
- (`void`) `cursorPreviousLine(unsigned)`
- (`void`) `cursorHorizontalAbs(unsigned)`
- (`void`) `cursorVerticalAbs(unsigned)`
- (`void`) `setCursorPositionCUP(unsigned, unsigned)`
- (`void`) `setCursorPositionCUP()`
- (`void`) `setCursorPositionHVP(unsigned, unsigned)`
- (`void`) `setCursorPositionHVP()`
- (`void`) `cursorBlinking(bool)`
- (`void`) `cursorVisible(bool)`
- (`void`) `cursorShape(unsigned)`
- (`void`) `scrollUp(unsigned)`
- (`void`) `scrollUp()`
- (`void`) `scrollDown(unsigned)`
- (`void`) `scrollDown()`
- (`void`) `insertCharacter(unsigned)`
- (`void`) `deleteCharacter(unsigned)`
- (`void`) `eraseCharacter(unsigned)`
- (`void`) `insertLine(unsigned)`
- (`void`) `deleteLine(unsigned)`
- (`void`) `eraseInDisplay(unsigned)`
- (`void`) `eraseInDisplay()`
- (`void`) `eraseInLine(unsigned)`
- (`void`) `eraseInLine()`
- (`void`) `link(string, string)`





<!--

    Costanti

-->

# Costanti

- `CSI`
- `OSC`
- `ESC`
- `ST`
- `SP`
- `CURSOR_SHAPE_USER_SHAPE`
- `CURSOR_SHAPE_BLINKING_BLOCK`
- `CURSOR_SHAPE_STEADY_BLOCK`
- `CURSOR_SHAPE_BLINKING_UNDERLINE`
- `CURSOR_SHAPE_STEADY_UNDERLINE`
- `CURSOR_SHAPE_BLINKING_BAR`
- `CURSOR_SHAPE_STEADY_BAR`
- `TEXT_MODIFICATION_ERASE_FROM_CURRENT`
- `TEXT_MODIFICATION_ERASE_FROM_BEGIN`
- `TEXT_MODIFICATION_ERASE_ENTIRE`




---

[Documentazione](../DOCS.md)
