// Screen.h
// Screen class definition . Represents the screen of the ATM.
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
using namespace std;

class Screen
{
public:
    void displayMesseage(string) const; 
    void displayMesseageLine(string) const;
    void displayDollarAmount(double) const;
};

#endif 