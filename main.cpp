#include <iostream>
#include "modules/colors/colors.hpp"

using namespace std;

int main()
{       
    cout << BG_GREEN COLOR_RED "xd" STYLE_RESET << endl;
    enableTerminalVirtualProcessing();
    return 0;
}