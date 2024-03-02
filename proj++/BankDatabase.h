// BankDatabase.h
// BankDatabase class definition. Represents the bank's database.
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <vector> // class uses vector to store Account objects
using namespace std;

#include "Account.h"

class BankDatabase
{
public:
    BankDatabase(); // constructor initializes accounts

    // determine whether account number and PIN match thoss of an Account
    bool authenticateUser(int, int);

    double getAvailableBalance(int);
    double getTotalBalance(int);
    void credit(int, double);
    void debit(int, double);
private:
    vector< Account > accounts; // vector of the bank's Accounts

    // private utility function
    Account * getAccount(int); // get pointer to Account object
}

#endif
