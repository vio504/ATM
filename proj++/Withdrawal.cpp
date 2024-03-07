// Withdrawal.cpp
// Member-function definitions for class Withdrawal.
#include "Withdrawal.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"

// global constant that corresponds to menu option to cancel
static const int CANCELED = 6;

// Withdrawal constructor initialize class's data members
Withdrawal::Withdrawal(int userAccountNumber, Screen &atmScreen,
    BankDatabase &atmBankDataBase, Keypad &atmKeypad,
    CashDispenser &atmCashDispenser)
    : Transaction(userAccountNumber, atmScreen, atmBankDataBase),
      keypad(atmKeypad), cashDispenser(atmCashDispenser) // member initializers
{

}

// overrides Transaction's pure virtual function
void Withdrawal::execute()
{
    bool cashDispensed = false;
    bool transactionCanceled = false;

    // references
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();

    // loop until cash is dispensed or the user cancels
    do
    {
        // obtain the chosen withdrawal amount from the user
        int selection = displayMenuOfAmounts();

        // amount || canceled ?
        if (selection != CANCELED)
        {
            amount = selection; // dollar amount

            double availableBalance =
               bankDatabase.getAvailableBalance(getAccountNumber());

            if (amount <= availableBalance)
            {
                if (cashDispenser.isSufficientCashAvailable(amount))
                {
                    // update the account involved to reflect withdrawal
                    bankDatabase.debit(getAccountNumber(), amount);

                    cashDispenser.dispenseCash(amount);
                    cashDispensed = true;

                    // instruction
                    screen.displayMessageLine(
                        "\nPlease take your cash from the cash dispenser.");
                }
                else
                    // cash dispenser does not have enough cash
                    screen.displayMessageLine(
                        "\nInsufficient cash available in the ATM."
                        "\n\nPlease choose a smaller amount."); // string literals adjacent to each other.
                
            }
            else
            {
                screen.displayMessageLine(
                   "\nInsufficient funds in your account."
                   "\n\nPlease choose a smaller account.");    
                
            }

        }
        else
        {
            screen.displayMesseageLine("\nCanceling transaction...");
            transactionCanceled = true;
        }
    } while (!cashDispensed && !transactionCanceled);
} //

// display a menu of withdrawal amounts and the option to cancel;
// return the chosen amount or 0 if the user chooses to cancel
int withdrawal::dispalyMenuOfAmounts() const
{
    int userChoice = 0;

    Screen &screen = getScreen();

    int amounts[] = { 0, 20, 40, 60, 100, 200 };

    //loop while no valid choice has been made
    while(userChoice == 0)
    {
        // dispaly the menu
        screen.displayMessageLine("\nWithdrawal options:");
        screen.displayMessageLine("1 - $20");
        screen.displayMessageLine("2 - $40");
        screen.displayMessageLine("3 - $60");
        screen.displayMessageLine("4 - $100");
        screen.displayMessageLine("5 - $200");
        screen.displayMessageLine("6 - Cancel transaction");
        screen.displayMessageLine("\nChoose a withdrawal option (1-6): ");

        int input = keypad.getInput();

        // determine how to proceed based on the input value
        switch (input)
        {
            case 1: // corresponding amount from amounts array
            case 2:
            case 3:
            case 4:
            case 5:
               userChoice = amounts[ input ];
               break;
            case CANCELED:
               userChoice = CANCELED;
               break;
            default:
               screen.displayMessageLine(
                  "\nInvalid selection. try again.");     
        }
    }

    return userChoice; // return withdrawal amount or CANCELED
}