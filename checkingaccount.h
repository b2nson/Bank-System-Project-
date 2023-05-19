//
// Created by Benson Nguyen on 5/2/23.
//

#ifndef FINALPROJECT_CHECKINGACCOUNT_H
#define FINALPROJECT_CHECKINGACCOUNT_H

#include "account.h"


class CheckingAccount : public Account {
private:
    int maxCap;
    bool locked;
public:
    static int checkingAccountAmount;

    CheckingAccount(const int initBal, const int maxCap, const bool locked) {
        setId(6000+checkingAccountAmount);

        initializeBal(initBal);
        this->maxCap = maxCap;
        this->locked = locked;

        checkingAccountAmount++;
    }

    const int getCap() { return maxCap; }

    const bool isLocked() { return locked; }

    const void setLocked(const bool lock) { this->locked = lock; }

    const void setCap(const int cap) { this->maxCap = cap; }
};

#endif
