/* 
 * File:   Random.cpp
 * Author: Adrian
 * 
 * Created on 17. Dezember 2012, 14:40
 */

#include "Random.h"

Random::Random(){}

Random::~Random(){}

int Random::getRandomNumber(int min, int max)
{
    int randomNum;
    srand( time(NULL) );
    do
    {
        randomNum = rand() % max + 1;
    }while(randomNum < min);
    
    return randomNum;
}