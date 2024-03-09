// ATM.cpp
// Member-function definitions for class ATM.
#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Deposit.h"

// enumeration constants represent main menu options
enum MenuOption {BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT };

ATM::ATM()
   : userAuthenticated(false), // user is not authenticated to start
     currentAcountNumber(0) // no current account number to start
{

}

// start ATM
void ATM::run()
{
    while(true)
    {
        // loop while user is not yet authenticated
        while(!userAuthenticated)
        {
            screen.displayMessageLine("\nWelcome !");
            authenticateUser();
        }

        performTransactions(); // authenticated->true;
        userAuthenticated = false; // reset before next ATM session
        currentAcountNumber = 0; 
        screen.displayMessageLine("\nThank you! Goodbye ^_^");
    }
}

// attempt to authenticate user against database 
void ATM::authenticateUser()
{
    screen.displayMessage("\nPlease enter your account number: ");
    int accountNumber = keypad.getInput();
    screen.displayMessage("\nEnter your PIN: ");
    int pin = keypad.getInput();

    userAuthenticated = 
       bankDatabase.authenticateUser(accountNumber, pin);

    if(userAuthenticated)
    {
        currentAcountNumber = accountNumber;
    }
    else
        screen.displayMessageLine(
            "Invalid account number or PIN. Please try again.");     
}


// perform transactions
void ATM::performTransactions()
{
    // local pointer to store transaction cuurently being processed
    Transaction *currentTransactionPtr;

    bool userExited = false;

    while(!userExited)
    {
        // main menu
        int mainMenuSeletion = displayMainMenu();

        switch(mainMenuSeletion)
        {
            case BALANCE_INQUIRY:
            case WITHDRAWAL:
            case DEPOSIT:
                // initialize as new object of chosen type
                currentTransactionPtr =
                    createTransaction(mainMenuSeletion); 
                
                currentTransactionPtr->execute(); // execute transaction

                // free
                delete currentTransactionPtr;
                break;
            case EXIT: 
                screen.displayMessageLine("\nExiting the system.. .");
                userExited = true;    
                break;
            default:
                screen.displayMessageLine(
                    "\nYou did not enter a valid selection. Try again.");
        }
    }
}


// Main Menu
int ATM::displayMainMenu() const
{
    screen.displayMessageLine("\nMain menu:");
    screen.displayMessageLine("1 - View my balance");
    screen.displayMessageLine("2 - Withdraw cash");
    screen.displayMessageLine("3 - Deposit funds");
    screen.displayMessageLine("4 - Exit\n");
    screen.displayMessage("Enter a choice: ");
    return keypad.getInput(); // return user's selection
}

// return object of specified Transaction derived class
Transaction *ATM::createTransaction(int type)
{
    Transaction *tempPtr;

    switch(type)
    {
        case BALANCE_INQUIRY: // create a new BalanceInquiry transaction
            tempPtr = new BalanceInquiry(
                currentAcountNumber, screen, bankDatabase);
            break;
        case WITHDRAWAL: // create a new Withdrawal transaction
            tempPtr = new Withdrawal(currentAcountNumber, screen,
             bankDatabase, keypad, cashDispenser);
             break;
        case DEPOSIT: // create a new Deposit transaction
        tempPtr = new Deposit(currentAcountNumber, screen,
        bankDatabase, keypad, depositSlot);
    }

    return tempPtr; // return the newly created object
}
