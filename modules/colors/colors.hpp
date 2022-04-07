#pragma once 
#include <windows.h>

// https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
// https://en.wikipedia.org/wiki/ANSI_escape_code#DOS_and_Windows

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN  0x0008

// colors

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"
#define COLOR_RESET "\x1b[0m"

// BGs

#define BG_RED "\x1b[41m"
#define BG_GREEN "\x1b[42m"
#define BG_YELLOW "\x1b[43m"
#define BG_BLUE "\x1b[44m"
#define BG_MAGENTA "\x1b[45m"
#define BG_CYAN "\x1b[46m"
#define BG_WHITE "\x1b[47m"
#define BG_RESET "\x1b[0m"

// other

#define STYLE_RESET "\x1b[0m"
#define STYLE_BOLD "\x1b[1m"
#define STYLE_DIM "\x1b[2m"
#define STYLE_RESETBRIGHTNESS "\x1b[22m"

// ~~~

/*
    Habilita el procesamiento virutal de la terminal (VT100) el cual tiene soporte ANSI
*/
void enableTerminalVirtualProcessing();

#include "colors.cpp"