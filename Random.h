/* 
 * File:   Random.h
 * Author: Adrian
 *
 * Created on 17. Dezember 2012, 14:40
 */

#ifndef RANDOM_H
#define	RANDOM_H

#include <cstdlib>
#include <iostream>
#include <time.h>

class Random 
{
    public:
        Random();
        ~Random();
        int getRandomNumber(int min, int max);
        
    private:
    //    int randomNum;

};

#endif	/* RANDOM_H */
