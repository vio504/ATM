// Deposit.cpp
// member-function definitions for class Deposit.
#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

static const int CANCELED = 0; // cancel option

// Deposit constructor initializes class's data members
Deposit::Deposit(int userAccountNumber, Screen &atmScreen,
   BankDatabase &atmBankDataBase, Keypad &atmKeypad,
   DepositSlot &atmDepositSlot)
   : Transaction(userAccountNumber, atmScreen, atmBankDataBase),
   keypad(atmKeypad), depositSlot(atmDepositSlot)
{

}

// performs transaction; overrides Transaction's pure virtual function
void Deposit::execute()
{
   BankDatabase &bankDatabase = getBankDatabase();
   Screen &screen = getScreen();

   amount = promptForDepositAmount(); // get deposit amount from user

   // amount || canceled ? 
   if (amount != CANCELED)
   {
      // request deposit envelope.
      screen.displayMessage(
      "\nPlease insert a deposit envelope containing ");
      screen.displayDollarAmount(amount);
      screen.displayMessageLine(" in the deposit slot.");

      // receive deposit envelope
      bool envelopeReceived = depositSlot.isEnvelopeReceived();

      // check whether deposit envelope was received
      if (envelopeReceived)
      {
         screen.displayMessageLine("\nYour envelope has been received."
         "\nNOTE: The money deposited will not be available until we"
         "\nverify the amount of any enclosed cash, and any enclosed "
         "checks clear.");

         // credit account to reflect the deposit
         bankDatabase.credit(getAccountNumber(), amount);
      }
      else
      {
         screen.displayMessageLine("\nYou did not insert an "
         "envelope, so the ATM has canceled your transaction.");
      }
   }
   else
   {
         screen.displayMessageLine("\nCanceling transaction.. .");
   }
}

// prompt user to enter a deposit amount in cents
double Deposit::promptForDepositAmount() const
{
   Screen &screen = getScreen();

   screen.displayMessage("\nPlease enter a deposit amount in "
   "CENTS (or 0 to cancel): ");
   int input = keypad.getInput();

   if (input == CANCELED)
      return CANCELED;
   else
   {
       // return dollar amount
   }
}


  