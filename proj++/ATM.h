// ATM.h
// ATM class definition. Represents an automated teller machine.
#ifndef ATM_H
#define ATM_H

#include "Screen.h"
#include "Keybad.h"
#include "CashDispenser.h" // class definition
#include "DepositSlot.h"
#include "BankDatabase.h"
class Transaction;

class ATM
{
public:
    ATM();
    void run(); // start the ATM
private:
    bool userAuthenticated;
    int currentAcountNumber;
    Screen screen;
    Keypad keypad;
    CashDispenser cashDispenser;
    DepositSlot depositSlot;
    BankDatabase bankDatabase;

    // private utility functions
    void authenticateUser();
    void performTransactions();
    int displayMainMenu() const;

    // return object of specified Transaction derived class
    Transaction *createTransaction(int);
};

#endif // ATM_H