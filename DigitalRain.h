//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#ifndef DIGITALRAIN_H
#define DIGITALRAIN_H

#include "RandomGenerator.h"
#include "ColourChanger.h"
#include <cstdlib>
#include <mutex>

class DigitalRain {
public:
    DigitalRain();
    void startGenerating();
    void SetCursorPosition();
private:
    RandomGenerator randomGenerator;
    ColourChanger colourChanger;
    std::mutex mtx;
    int row;
    int col;
};

#endif
