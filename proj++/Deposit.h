// Deposit.h
// Deposit class definition. Represents a deposit transaction.
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h"
class Keypad;
class DepositSlot;

class Deposit : public Transaction
{
public:
    Deposit(int , Screen &, BankDatabase &, Keypad &, DepositSlot &);
    virtual void execute();
private:
    double amount;
    Keypad &keypad;
    DepositSlot &depositSlot;
    double promptForDepositAmount() const; // private utility function
}

#endif