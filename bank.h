//
// Created by Benson Nguyen on 5/2/23.
//

#ifndef FINALPROJECT_BANK_H
#define FINALPROJECT_BANK_H

#include "account.h"
#include <vector>

class Bank {
protected:
    string name;
    string address;
    string workingHours;


    vector<BankAccount> bankAccounts;

public:

    Bank(const string name, const string address, const string workingHours) {
        this->name = name;
        this->address = address;
        this->workingHours = workingHours;
    }

    const string getName() { return name; }

    const string getAddress() { return address; }

    const string getHours() { return workingHours; }

    BankAccount* createNewBankAccount(const string firstName, const string lastName, const string ssn) {
        bankAccounts.push_back(BankAccount(firstName, lastName, ssn));
        return &bankAccounts.at(bankAccounts.size()-1);
    }

    const vector<BankAccount> getBankAccounts() { return bankAccounts; }

    const int getAggBalance() {
        int aggBal = 0;
        for (BankAccount bA : bankAccounts) { aggBal += bA.getAggBalance(); }
        return aggBal;
    }

    const bool getAccount(const int id, BankAccount* &bAcc) {
        for (int x = 0; x < bankAccounts.size(); x++) {
            if (bankAccounts.at(x).getId() == id) { bAcc = &bankAccounts.at(x); return true; }
        }
        return false;
    }

    const bool deleteAccount(const int id) {
        for (vector<BankAccount>::iterator it = bankAccounts.begin(); it != bankAccounts.end(); ++it) {
            if (it->getId() == id) { bankAccounts.erase(it); return true; }
        }
        return false;
    }
};

#endif //FINALPROJECT_BANK_H
