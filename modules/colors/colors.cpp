#include "colors.hpp"

void enableTerminalVirtualProcessing(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut , &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING; // 4 flag
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN; // 8 flag
    SetConsoleMode( handleOut , consoleMode );
}