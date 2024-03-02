// Bankdatabase.cpp
// Member-function definitions for class BankDatabase.
#include "BankDatabase.h"
#include <cstddef>

 BankDatabase::BankDatabase()
 {
    // create two Account objects for testing
    Account account1(12345, 54321, 1000.0, 1200.0);
    Account account2(98765, 56789, 200.0, 200.0);

    // add account1, account2 to the end of the vector
    accounts.push_back(account1);
    accounts.push_back(account2);
 }

 // retrieve Account object containing specified account number
 Account * BankDatabase::getAccount(int accountNumber)
 {
    // loop through accounts searching for matching account number
    for (size_t i = 0; i < accounts.size(); i++)
    {
        // return current account if match found
        if(accounts[ i ].getAccountNumber() == accountNumber)
            return &accounts[ i ];
    }

    return NULL; //if no matching was found
 }

 // determine whether user-specified account number and PIN match
 // those of an account in the database
 bool BankDatabase::authenticateUser(int userAccountNumber, int userPIN)
 {
    
    //attempt to retrieve the account with the account number
    Account * const userAccountPtr = getAccount(userAccountNumber);

    // if account exists, return result of Account function validatePIN
    if(userAccountPtr != NULL)
        return userAccountPtr->validatePIN(userPIN);
    else
        return false;
 }

 // return available balance of Account with specified account number
 double BankDatabase::getAvailableBalance(int userAccountNumber)
 {
    Account * const userAccountPtr = getAccount(userAccountNumber);
    return userAccountPtr->getAvailableBalance();
 }

 // return total balance of Account with specified account number
 double BankDatabase::getTotalBalance(int userAccountNumber)
 {
    Account * const userAccountPtr = getAccount(userAccountNumber);
    return userAccountPtr->getTotalBalance();
 }

 // credit an amount to Account with specified account number
 void BankDatabase::credit(int userAccountNumber, double amount)
 {
    Account * const userAccountPtr = getAccount(userAccountNumber);
    userAccountPtr->credit(amount);
 }

// debit an amount from Account with specified account number
void BankDatabase::debit(int userAccountNumber, double amount)
{
    Account * const userAccountPtr = getAccount(userAccountNumber);
    userAccountPtr->debit(amount);
}
