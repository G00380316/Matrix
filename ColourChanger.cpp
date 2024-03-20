//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#include "ColourChanger.h"

ColourChanger::ColourChanger() : isRunning(false) {}

// ANSI escape code for colorchange
void ColourChanger::startChangingColours() {
    if (isRunning) {
        return;
    }
    isRunning = true;
    while (isRunning) {
        changeColour("\033[32m"); //green
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        changeColour("\033[36m"); //cyan
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        changeColour("\033[33m"); //yellow
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        changeColour("\033[35m"); //Magenta
        //std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

void ColourChanger::changeColour(const std::string& colorCode) {
    std::cout << colorCode;
}

void ColourChanger::changeBackgroundColour(const std::string& colorCode) {
    std::cout << colorCode;
}

/*
foreground Colors:

\033[30m: Black
\033[31m: Red
\033[32m: Green
\033[33m: Yellow
\033[34m: Blue
\033[35m: Magenta
\033[36m: Cyan
\033[37m: White
Background Colors:

\033[40m: Black
\033[41m: Red
\033[42m: Green
\033[43m: Yellow
\033[44m: Blue
\033[45m: Magenta
\033[46m: Cyan
\033[47m: White
*/
