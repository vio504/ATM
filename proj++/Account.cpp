// Account.cpp
// Member-function definitions for class Account.
#include "Account.h"

// Account constructor initializes attributes
Account::Account(int theAccountNumber, int thePIN,
   double theAvailableBalance, double theTotalBalance) 
   : accountNumber(theAccountNumber), 
     pin(thePIN), 
     availableBalance(theAvailableBalance), 
     totalBalance(theTotalBalance)
{
    // empty body
}

// determines whether a user-specified PIN matches PIN in Account
bool Account::validatePIN(int userPIN) const
{
    if (userPIN == pin)
        return true;
    else
        return false;
}

// returns available balance
double Account::getAvailableBalance() const
{
    return availableBalance;
}

// return the total balance
double Account::getTotalBalance() const
{
    return totalBalance;
}

// credits an amount to the account
void Account::credit(double amount)
{
    totalBalance += amount;
}

// debits an amount from the account
void Account::debit(double amount)
{
    availableBalance -= amount;
    totalBalance -= amount;
}

// returns account number
int Account::getAccountNumber() const
{
    return accountNumber;
}