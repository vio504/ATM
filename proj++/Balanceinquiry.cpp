// BalanceInquiry.cpp
// Member-function definitions for class BalanceInquiry.
#include "BalanceInquiry.h"
#include "Screen.h"
#include "BankDatabase.h"

// base-class initializer syntax
BalanceInquiry::BalanceInquiry(int userAccountNumber, Screen &atmScreen,
  BankDatabase &atmBankDatabase)
  : Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{

}

// performs transaction; overrides Transaction's pure virtual function
void BalanceInquiry::execute()
{
    
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();

    // get the available balance for the current user's Account
    double availableBalance =
       bankDatabase.getAvailableBalance(getAccountNumber());
    
    // get the total balance for the current user's Account
    double totalBalance =
       bankDatabase.getTotalBalance(getAccountNumber());

    // display the balance information on the screen
    screen.displayMesseageLine("\nBalance Information:");
    screen.displayMesseage(" - Available balance: ");
    screen.displayDollarAmount(availableBalance);
    screen.displayMesseage("\n - Total balance:    ");
    screen.displayMesseageLine("");
}
