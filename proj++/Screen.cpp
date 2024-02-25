// Screen.cpp
// Member-function definitions of class Screen.
#include <iostream>
#include <iomanip> // manage input and output formatting.
#include "Screen.h"

using namespace std;


void Screen::displayMesseage(string message) const
{
    cout << message;
}

void Screen::displayMesseageLine(string message) const
{
    cout << message << endl;
}

void Screen::displayDollarAmount(double amount) const
{
    cout << fixed << setprecision(2) << "$" << amount; // <iomanip>
}
