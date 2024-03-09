// Withdrawal.h
// Definition of class Withdrawal that represents a withdrawal transaction.
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h" // Transaction class definition
class Keypad;// forward declaration
class CashDispenser;

// class Withdrawal derives from base class Transaction
class Withdrawal : public Transaction
{
public:
    Withdrawal(int , Screen &, BankDatabase &, Keypad &, CashDispenser &);
    // operations
    // member function overriding 'execute' in base class Transaction
    virtual void execute(); // perform the transaction
private:
    // attributes
    int amount; // amount to withdraw
    // references to associated objects
    Keypad &keypad;
    CashDispenser &cashDispenser;
    // display the withdrawal menu
    int displayMenuOfAmounts() const;
};

#endif // WITHDRAWAL_H

