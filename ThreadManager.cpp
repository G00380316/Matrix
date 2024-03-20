//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#include "ThreadManager.h"

ThreadManager::ThreadManager(std::vector<DigitalRain>& generators) : generators(generators) {}

ThreadManager::~ThreadManager() {
    joinAllThreads();
}

void ThreadManager::startAllGenerators() {
    for (auto& generator : generators) {
        threads.emplace_back(&DigitalRain::startGenerating, &generator);
        threads.back().detach();
    }
}

void ThreadManager::joinAllThreads() {
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}
