// Transaction.h
// Transaction abstract base class definition.
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Screen; // forward declaration
class BankDatabase;

class Transaction
{
public:
    // initializes common features of all Transactions
    Transaction(int , Screen &, BankDatabase &); 
    // virtual destructor
    virtual ~Transaction() { }

    int getAccountNumber() const; // return account number
    Screen &getScreen() const; // return reference to screen
    BankDatabase &getBankDatabase() const;// return reference to database

    // pure virtual function
    virtual void execute() = 0; // overridden in derived classes
private:
    int accountNumber; // indicates account involved
    Screen &screen;
    BankDatabase &bankDatabase;
};

#endif