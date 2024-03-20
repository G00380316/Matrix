//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#include "DigitalRain.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

DigitalRain::DigitalRain() {}

void DigitalRain::startGenerating() {
    std::thread colourThread(&ColourChanger::startChangingColours, &colourChanger); // Starts a separate thread for changing colours
    std::vector<char> randomCharacters;
    std::vector<char> charactersBuffer;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    while (true) {
        randomCharacters = randomGenerator.generateRandomCharacters(10);
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int numSpaces = rand() % csbi.dwSize.X;

        for (int i = 0; i < numSpaces; ++i) {
            std::cout << ' ';
        }

        for (const auto& character : randomCharacters) {
            charactersBuffer.push_back(character);
        }
        if (charactersBuffer.size() == 10) {
            for (const auto& character : charactersBuffer) {
                mtx.lock();
                SetCursorPosition();
                std::cout << character;
                std::cout.flush();
                //csbi.dwCursorPosition.X - 1;
                mtx.unlock();
            }

            // Check if the console window has reached the bottom
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            if (csbi.dwCursorPosition.Y >= csbi.dwSize.Y - 1) {
                mtx.lock();
                COORD coord = { 0, 0 };
                DWORD written;
                FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                mtx.unlock();
            }
            charactersBuffer.clear();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(750)); // Sleep for 1 second normally but to see different patterns change to you liking
    }

    colourThread.join(); // Wait for the colour changing thread to finish
}

void DigitalRain::SetCursorPosition() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD cursorPosition;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cursorPosition.Y = csbi.dwCursorPosition.Y + 1; // Move to the line below
    cursorPosition.X = csbi.dwCursorPosition.X - 1; // Move one space back
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
