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

std::string get_word(char optional)
{
    if(std::isspace(optional))
        return "";
    std::cout << optional;

    std::string word;
    word += optional;
    char c = _getch();
    while (c == ' ' || !std::isspace(c))
    {
        word.push_back(c);
        std::cout << c;
        c = _getch();
    }
    std::cout << c;
    return word;
}