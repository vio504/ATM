// Transaction.cpp
// member-function definitions for class Transaction.
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"


Transaction::Transaction(int userAccountNumber, Screen &atmScreen,
 BankDatabase &atmBankDatabase)
 : accountNumber(userAccountNumber),
   screen(atmScreen),
   bankDatabase(atmBankDatabase)
{
        // ᶻ 𝗓 𐰁
}


int Transaction::getAccountNumber() const
{
    return accountNumber;
}

// returun reference to screen
Screen &Transaction::getScreen() const
{
    return screen;
}

// return reference to bank database
BankDatabase &Transaction::getBankDatabase() const
{
    return bankDatabase;
}