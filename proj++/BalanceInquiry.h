// BalanceInquiry.h
// BalanceInquiry class definition. Represents a balance inquiry.
#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H

#include "Transaction.h"

class BalanceInquiry : public Transaction
{
public:
    BalanceInquiry(int, Screen &, BankDatabase &);
    virtual void execute();
};

#endif