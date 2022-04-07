#include "ansi.hpp"
#include "./../utils/utils.hpp"

void enableTerminalVirtualProcessing(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut , &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING; // 4 flag
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN; // 8 flag
    SetConsoleMode( handleOut , consoleMode );
}

void setCursorPosition(int x, int y){
    std::cout << "\x1b[" << y << ";" << x << "H";
}

void resetCursorPosition(){
    std::cout << "\x1b[" << getHPos(100) << ";" << 0 << "H";
}