// Withdrawal.h
// Definition of class Withdrawal that represents a withdrawal transaction

#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h" // Transaction class definition

// forward declaration 

class keypad;
class CashDispenser;

// class Withdrawal derives from base class Transaction
class Withdrawal : public Transaction
{
public:
    // operations
    // member function overriding 'execute' in base class Transaction
    virtual void execute(); // perform the transaction
private:
    // attributes
    double amount; // amount to withdraw

    // references to associated objects
    keypad &keypad;
    CashDispenser &cashdispenser;
};

#endif // WITHDRAWAL_H
