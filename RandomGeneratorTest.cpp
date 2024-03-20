//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#include "RandomGenerator.h"
#include <iostream>
#include <random>

RandomGenerator::RandomGenerator() {

    for (char c = 'A'; c <= 'Z'; ++c) {
        characters.push_back(c);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        characters.push_back(c);
    }
    for (char c = '0'; c <= '9'; ++c) {
        characters.push_back(c);
    }
    for (char c = '!'; c <= '/'; ++c) {
        characters.push_back(c);
    }
    for (char c = ':'; c <= '@'; ++c) {
        characters.push_back(c);
    }
    for (char c = '['; c <= '`'; ++c) {
        characters.push_back(c);
    }
    for (char c = '{'; c <= '~'; ++c) {
        characters.push_back(c);
    }
}

std::vector<char> RandomGenerator::generateRandomCharacters(int numCharacters) {
    std::vector<char> randomCharacters;

    // Generate random indices to pick characters from the characters vector
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);

    for (int i = 0; i < numCharacters; ++i) {
        int randomIndex = dis(gen);
        randomCharacters.push_back(characters[randomIndex]);
    }

    return randomCharacters;
}
