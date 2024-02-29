// DepositSlot.cpp
// Member-function definiton or class DepositSlot.
#include "DepositSlot.h"

// indicates whether enelope was received (always returns true,
// because this is only a software simulation of a real deposit slot)
bool DepositSlot::isEnvelopeReceived() const
{
    return true;
}