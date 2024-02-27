// CashDispenser.cpp
// Member-function definitions for class CashDispenser.

#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
    count = INITIAL_COUNT; // set count attribute to default
}

// simulates dispensing of specified amount of cash; assumes enough cash
// is available (previous call to isSufficientCashAvailable returned true)
void CashDispenser::dispenseCash(int amount)
{
    int billsRequired = amount / ONEBILL; // number of $20 bills required
    count -= billsRequired; // update the count of bills
}

// indicates whether cash dispenser can dispense desired amount
bool CashDispenser::isSufficientCashAvailable(int amount) const
{
    int billsRequired = amount / ONEBILL;

    if (count >= billsRequired)
        return true; // enough bills are available
    else
        return false;// not enough bills are available
}