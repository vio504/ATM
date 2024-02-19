// Withdrawal.h
// Definition of class Withdrawal that represents a withdrawal transaction

#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

// forward declaration 
class Screen;
class keypad;
class CashDispenser;
class BankDatabase;

class Withdrawal
{
public:
    // operations
    void execute(); // perform the transaction
private:
    // attributes
    int accountNumber; // account to withdraw funds from
    double amount; // amount to withdraw

    // references to associated objects
    Screen &screen;
    keypad &keypad;
    CashDispenser &cashdispenser;
    BankDatabase &bankdatabase;
};

#endif // WITHDRAWAL_H
