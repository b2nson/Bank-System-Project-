//
// Created by Benson Nguyen on 5/2/23.
//

#ifndef FINALPROJECT_ACCOUNT_H
#define FINALPROJECT_ACCOUNT_H

#include <string>
#include "id.h"

using namespace std;

class Account : public Id {
private:
    int balance;
public:

    const void initializeBal(const int initAmount) { this-> balance = initAmount; }

    const void deposit(const int depositAmount) { this->balance += depositAmount; }

    const void withdraw(const int withdrawAmount) { this->balance -= withdrawAmount; }

    const int getBalance() { return balance; }
};

#endif //FINALPROJECT_ACCOUNT_H
