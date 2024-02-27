// Keypad.cpp
// Member-function definition for class keypad (the ATM's keypad). 
#include <iostream>
using namespace std;

#include "Keypad.h"

int Keypad::getInput() const
{
    int input;
    cin >> input; // assume that the user enters an integer
    return input;
}