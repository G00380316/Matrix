//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#ifndef COLOURCHANGER_H
#define COLOURCHANGER_H

#include <iostream>
#include <chrono>
#include <thread>

class ColourChanger {
public:
    ColourChanger();
    void startChangingColours();
private:
    void changeColour(const std::string& colorCode);
    void changeBackgroundColour(const std::string& colorCode);
    bool isRunning;
};

#endif
