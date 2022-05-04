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
void startAnim();

int processOffset = 0;
int frameActual = 3000;
int maxFrame = 0;
int frameSpeed = 5;

struct process {
    int init;
    int end;
    int current;
    int color;
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

        if(word == "4"){
            startAnim();
        }
    }

    return;
}

void startAnim(){
    frameActual = 0;

    while(frameActual < maxFrame){
        if(GetKeyState(VK_UP) & 0x8000)
        {
            processOffset--;
            if (processOffset < 0)
                processOffset = 0;
            renderProcess();
            cout << "\b \b";
        }
        else if(GetKeyState(VK_DOWN) & 0x8000)
        {
            processOffset++;
            if (processOffset > processes.size() - 1)
                processOffset = processes.size() - 1;
            cout << "\b \b";
            renderProcess();
        }

        frameActual += frameSpeed;
        // wait 200 ms
        Sleep(200);
        // render the process
        renderProcess();
    }
    fflush(stdin);
    return;
}

void addRandomProcess(){
    int init = rand() % 150;
    int end = init + rand() % 150;
    int current = 0;
    int color = rand()%10;

    process p;
    p.init = init;
    p.end = end;
    p.current = current;
    p.color = color;

    if(p.end > maxFrame)
        maxFrame = p.end;

    processes.push_back(p);

    renderProcess();
}

void renderProcess(){
    // clear process first

    string ca;
    for(int i = 0; i < getWPos(23)-1; i ++ )
        ca += " ";

    string cf;
    for(int i = 0; i < getWPos(98)-getWPos(30); i ++ )
        cf += " ";

    for(int i = 3; i < 70; i++){
        setCursorPosition(0, getHPos(i)+2);
        cout << ca;
        setCursorPosition(getWPos(30), getHPos(i)+2);
        cout << cf;
    }

    int percentageStart = 19;
    // 20-80

    string ce;
    for(int i = 0; i < getWPos(98)-getWPos(30); i ++ )
        ce += " ";

    // iterate processes
    int p = getHPos(percentageStart);
    for(int i = processOffset; i < processes.size(); i++){
        if(percentageStart > 75)
            break;

        setCursorPosition(getWPos(3), p);
        cout << "Proceso " << i;
        percentageStart+=6;

        // render process

        int rangeOffset = getWPos(98) - getWPos(30);
        // convert processes[i].init to rangeOffset
        int init = getWPos(30) + (processes[i].init * rangeOffset / maxFrame);
        int end = getWPos(30) + (processes[i].end * rangeOffset / maxFrame);

        setCursorPosition(init, p);

        if(frameActual >= processes[i].end){
            cout << getIColor(processes[i].color);
            if(end-init == 0) 
                cout << "~";
            for(int i = 0; i < end-init; i++)
                cout << "~";

            cout << STYLE_RESET;        
        }
        else if (frameActual >= processes[i].init){

        int OldRange = (processes[i].end - processes[i].init);  
        int NewRange = (end - init);
        int fsize = (((frameActual - processes[i].init) * NewRange) / OldRange) + init;
        cout << getIColor(processes[i].color);
        for(int i = 0; i < fsize-init; i++)
            cout << "-";
        }
        cout << STYLE_RESET;        

        p+=1;
    }

    setCursorPosition(0, getWindowHeight()-3);
    cout << "Frame actual: " << frameActual << " de " << maxFrame;

    // percentage
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

    cout << STYLE_RESET;
    resetCursorPosition();


    return;
}