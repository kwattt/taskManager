#include "utils.hpp"

int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getWindowHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int getWPos(int percentage){
    return (percentage * getWindowWidth()) / 100;
}

int getHPos(int percentage){
    return (percentage * getWindowHeight()) / 100;
}

const char* getIColor(int i){
    switch(i){
        case 0:
            return BG_BLUE;
        case 1:
            return BG_GREEN;
        case 2:
            return BG_RED;
        case 3:
            return BG_YELLOW;
        case 4:
            return BG_MAGENTA;
        case 5:
            return BG_CYAN;
        case 6:
            return BG_WHITE;
        case 7:
            return BG_BLUE;
        case 8:
            return BG_GREEN;
        case 9:
            return BG_RED;
        default:
            return BG_BLUE;
    }
}