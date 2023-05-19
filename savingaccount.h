//
// Created by Benson Nguyen on 5/2/23.
//

#ifndef FINALPROJECT_SAVINGACCOUNT_H
#define FINALPROJECT_SAVINGACCOUNT_H

#include "account.h"

class SavingAccount : public Account {
public:
    static int savingAccountAmount;

    SavingAccount(const int initBal) {
        setId(1000+savingAccountAmount);
        initializeBal(initBal);
        savingAccountAmount++;
    }
};

#endif
