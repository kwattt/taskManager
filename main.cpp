#include <iostream>
#include "modules/ansi/ansi.hpp"
#include "modules/utils/utils.hpp"
#include <time.h>
#include <vector>

using namespace std;

void idleScreen();
void renderIdleScreen();
void addRandomProcess();
void renderProcess();

int processOffset = 0;

struct process {
    int init;
    int end;
    int current;
};
vector<process> processes;

int main()
{       
    srand(time(NULL));
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

        if(input == "2"){
            addRandomProcess();
        }
    }

    return;
}

void addRandomProcess(){
    int init = 1 + rand() % 150;
    int end =  rand() % 150;
    int current = 0;

    process p;
    p.init = init;
    p.end = end;
    p.current = current;

    processes.push_back(p);

    renderProcess();
}

void renderProcess(){
    // clear process first
    for(int i = 3; i < 80; i++){
        setCursorPosition(0, getHPos(i));
        cout << STYLE_REMOVE_LINE;
    }
    renderIdleScreen();

    int percentageStart = 19;
    // 20-80

    // iterate processes
    for(int i = 0; i < processes.size(); i++){
        if(percentageStart > 80)
            break;

        setCursorPosition(getWPos(3), getHPos(percentageStart));
        cout << "Proceso " << i;
        percentageStart+=6;

    }

    resetCursorPosition();
    cout << STYLE_RESET;
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