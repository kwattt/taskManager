#include <iostream>
#include "modules/colors/colors.hpp"
#include "modules/utils/utils.hpp"

using namespace std;

int main()
{       
    enableTerminalVirtualProcessing();
    cout << BG_GREEN COLOR_RED "Width de la terminal:" BG_RESET " " << getWindowWidth() << STYLE_RESET << endl;
    cout << BG_GREEN COLOR_BLUE "Height de la terminal:" BG_RESET " " << getWindowHeight() << STYLE_RESET << endl;
    return 0;
}