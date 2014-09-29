
#include "Random.hpp"

Random::Random() {
}

Random::~Random() {
}

int Random::getRandomNumber(int min, int max) {
    int randomNum;
    srand(time(NULL));
    do {
        randomNum = rand() % max + 1;
    } while (randomNum < min);

    return randomNum;
}