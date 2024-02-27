// CashDispenser.h
// CashDispenser class definition. Represents the ATM's cash dispenser.
#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

// * the ATM allows the user to choose only withdrawal amounts that are multiples of $20, 
// so we divide amount by 20 to obtain number of billsRequired.
#define ONEBILL 20

class CashDispenser
{
public:
    CashDispenser(); // constructor initializes bill count to 500

    // simulates dispensing of specified amount of cash
    void dispenseCash(int);

    // indicates whether cash dispenser candispense desired amount
    bool isSufficientCashAvailable(int) const;
private:
    static const int INITIAL_COUNT = 500; // initial count of bills in the cash dispenser when the ATM starts 
    int count; // number of $20 bills remaining
};

#endif
