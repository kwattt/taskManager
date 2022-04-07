#include <iostream>
#include "modules/ansi/ansi.hpp"
#include "modules/utils/utils.hpp"

using namespace std;

int main()
{       
    enableTerminalVirtualProcessing();
    cout << STYLE_CLEAR;

    cout << BG_MAGENTA;
    for(int i = 0; i < getWindowHeight()-1; i++)
        for(int j = 0; j < getWindowWidth(); j++)
            cout << " ";
        cout << endl;

    cout << BG_CYAN;
    for(int i = 0; i < getWindowHeight()-1; i++)
    {
        setCursorPosition(getWPos(23), i);
        cout << " ";
    }

    setCursorPosition(getWPos(2), getHPos(0));
        cout << BG_RED;
        cout << "Procesos";

    setCursorPosition(getWPos(0), getHPos(100)-1);
    cout << BG_GREEN "0: Salir. 1: Proceso aleatorio. 2: Agregar proceso. 3: Eliminar proceso. 4: Iniciar";

    resetCursorPosition();

    cout << STYLE_RESET;
    return 0;
}