//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include "DigitalRain.h"
#include <vector>

class ThreadManager {
public:
    ThreadManager(std::vector<DigitalRain>& generators);
    ~ThreadManager();

    void startAllGenerators();
    void joinAllThreads();

private:
    std::vector<DigitalRain>& generators;
    std::vector<std::thread> threads;
};

#endif // THREADMANAGER_H
