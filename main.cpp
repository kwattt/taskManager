#include <iostream>
#include "modules/ansi/ansi.hpp"
#include "modules/utils/utils.hpp"
#include <vector>

using namespace std;

void idleScreen();
void renderIdleScreen();

struct process {
    int init;
    int end;
    int current;
};
vector<process> processes;

int main()
{       
    enableTerminalVirtualProcessing();
    idleScreen();
}

void idleScreen(){
    renderIdleScreen();

    while(true){
        string input;
        resetCursorPosition();
        cout << STYLE_REMOVE_LINE;
        char c = _getch();
        input = get_word(c);
        if(input == "0"){
            break;
        }
    }

    return;
}

void renderIdleScreen(){
    cout << STYLE_CLEAR;
    setCursorPosition(0, getWindowHeight()-1);

    for(int i = 0; i < getWindowHeight()-1; i++)
        for(int j = 0; j < getWindowWidth(); j++)
            cout << " ";
        cout << endl;

    cout << BG_CYAN;
    for(int i = 1; i < getWindowHeight()-1; i++)
    {
        setCursorPosition(getWPos(23), i);
        cout << " ";
    }

    for(int j = 0; j < getWindowWidth(); j++){
        setCursorPosition(j, getWindowHeight()-2);
        cout << " ";
    }

    setCursorPosition(0, getHPos(0));
        cout << BG_RED;
        cout << "Procesos";

    setCursorPosition(0, getWindowHeight()-1);
    cout << BG_RESET COLOR_CYAN "0: Salir 1: Agregar 2: Aleatorio 3: Eliminar 4: Iniciar";

    resetCursorPosition();

    cout << STYLE_RESET;
    return;
}