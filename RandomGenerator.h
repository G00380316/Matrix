//Name: Enoch Abiodun
//Date: 19/03/2024
//Project: Digital Rain

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <vector>

class RandomGenerator {
public:
    RandomGenerator();
    std::vector<char> generateRandomCharacters(int numCharacters);
private:
    std::vector<char> characters;
};

#endif
