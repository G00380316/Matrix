//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

//Size of the console makes a difference so please run in maximised or fullscreen
//Also let it run for while to correct itself
//The more threads the less time it takes to correct compare 10 generators to 5

#include <iostream>
#include "DigitalRain.h"
#include "ThreadManager.h"

int main() {

    /*
    DigitalRain generator1;
    DigitalRain generator2;
    DigitalRain generator3;
    DigitalRain generator4;
    DigitalRain generator5;

    // Create multiple threads to run each instance of RandomColourGenerator
    std::thread thread1(&DigitalRain::startGenerating, &generator1);
    std::thread thread2(&DigitalRain::startGenerating, &generator2);
    std::thread thread3(&DigitalRain::startGenerating, &generator3);
    std::thread thread4(&DigitalRain::startGenerating, &generator4);
    std::thread thread5(&DigitalRain::startGenerating, &generator5);

    // Start the threads
    thread1.detach(); // Detach the threads so they run independently
    thread2.detach();
    thread3.detach();
    thread4.detach();
    thread5.detach();
    */

    std::vector<DigitalRain> generators(5); // Create 5 instances of RandomColourGenerator (the more instances the fast and more vectors of characters and diferent patterens)

    ThreadManager threadManager(generators);

    threadManager.startAllGenerators();

    // Wait for all threads to finish
    //threadManager.joinAllThreads();
    
    while (true) {
        std::cout << "Press 'q' to quit: "; // You want see this print but you can press q then enter to quit
        char input;
        std::cin >> input;
        if (input == 'q') {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
