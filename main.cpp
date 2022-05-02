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
        resetCursorPosition();
        cout << STYLE_REMOVE_LINE;

        std::string word;
        char c = _getch();

        while (1)
        {
            // if arrow up or down
            if (c == -32)
            {
                c = _getch();
                if (c == 72)
                {
                    processOffset--;
                    if (processOffset < 0)
                        processOffset = 0;
                    renderProcess();
                    cout << "\b \b";
                    break;
                }
                else if (c == 80)
                {
                    processOffset++;
                    if (processOffset > processes.size() - 1)
                        processOffset = processes.size() - 1;
                    cout << "\b \b";
                    renderProcess();
                    break;
                }
            }

            // if enter is pressed then break
            if (c == 13)
                break;
        
            // if backspace is pressed and there is a word in the buffer
            if (c == 8 && word.size() > 0)
            {
                // remove the last character
                word.pop_back();
                // move the cursor back
                cout << "\b \b";
            }
            else {
                word.push_back(c);
                std::cout << c;
            }
            c = _getch();
        }

        if(word == "0"){
            break;
        }

        if(word == "2"){
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

    string ca;
    for(int i = 0; i < getWPos(23)-1; i ++ )
        ca += " ";

    for(int i = 3; i < 70; i++){
        setCursorPosition(0, getHPos(i)+2);
        cout << ca;
    }

    int percentageStart = 19;
    // 20-80

    // iterate processes
    int p = getHPos(percentageStart);
    for(int i = processOffset; i < processes.size(); i++){
        if(percentageStart > 75)
            break;

        setCursorPosition(getWPos(3), p);
        cout << "Proceso " << i;
        percentageStart+=6;
        p+=1;
    }

    cout << STYLE_RESET;
    resetCursorPosition();
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