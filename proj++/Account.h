// Account.h
// Account class definition. Represents a bank account.
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account(int , int, double, double);
    bool validatePIN(int) const;
    double getAvailableBalance() const;
    double getTotalBalance() const;
    void credit(double);
    void debit(double);
    int getAccountNumber() const;
private:
    int accountNumber;
    int pin;
    double availableBalance;
    double totalBalance;
};

#endif