#ifndef PROJECT01_BANKACCOUNT_H
#define PROJECT01_BANKACCOUNT_H

#include "checkingaccount.h"
#include "savingaccount.h"

#include <vector>

class BankAccount : public Id {
private:
    string name;
    string ssn;
    vector<SavingAccount> savingAccs;
    vector<CheckingAccount> checkingAccs;
public:
    static int bankAccountAmount;

    BankAccount(const string firstName, const string lastName, const string ssn) {
        setId(10000+bankAccountAmount);
        name = firstName + " " + lastName;
        this->ssn = ssn;
        bankAccountAmount++;
    }

    const string getName() { return name; }

    const string getSSN() { return ssn; }

    CheckingAccount* createNewCheckingAccount(const int initBal, const int maxCap, const bool locked) {
        checkingAccs.push_back(CheckingAccount(initBal, maxCap, locked));
        return &checkingAccs.at(checkingAccs.size()-1);
    }

    SavingAccount* createNewSavingAccount(const int initBal) {
        if (savingAccs.size() == 0)
            savingAccs.push_back(SavingAccount(initBal+100));
        else
            savingAccs.push_back(SavingAccount(initBal));
        return &savingAccs.at(savingAccs.size()-1);
    }

    const bool getCheckingAccount(const int id, CheckingAccount* &cAcc) {
        for (int x = 0; x < checkingAccs.size(); x++) {
            if (checkingAccs.at(x).getId() == id) { cAcc = &checkingAccs.at(x); return true; }
        }
        return false;
    }

    const bool getSavingAccount(const int id, SavingAccount* &sAcc) {
        for (int x = 0; x < savingAccs.size(); x++) {
            if (savingAccs.at(x).getId() == id) { sAcc = &savingAccs.at(x); return true; }
        }
        return false;
    }

    const bool deleteCheckingAccount(const int id) {
        vector<CheckingAccount>::iterator it;
        for (it = checkingAccs.begin(); it != checkingAccs.end(); ++it) {
            if (it->getId() == id) { checkingAccs.erase(it); return true; }
        }
        return false;
    }

    const bool deleteSavingAccount(const int id) {
        vector<SavingAccount>::iterator it;
        for (it = savingAccs.begin(); it != savingAccs.end(); ++it) {
            if (it->getId() == id) { savingAccs.erase(it); return true; }
        }
        return false;
    }

    const int getAccSize() { return savingAccs.size() + checkingAccs.size(); }

    const int getAggBalance() {
        int aggBal = 0;
        for (SavingAccount a : savingAccs) { aggBal += a.getBalance(); }
        for (CheckingAccount a : checkingAccs) { aggBal += a.getBalance(); }
        return aggBal;
    }

    const void getDetailedPrint(string inputArr[100]) {
        int x = 0;
        for (SavingAccount savAcc : savingAccs) {
            inputArr[x] = "\n";
            x++;
            inputArr[x] = "Sub-Account number: SAV" + to_string(savAcc.getId());
            x++;
            inputArr[x] = "Balance: " + to_string(savAcc.getBalance());
            x++;
            inputArr[x] = "\n";
        }
        for (CheckingAccount cheAcc : checkingAccs) {
            inputArr[x] = "\n";
            x++;
            inputArr[x] = "Sub-Account number: CHK" + to_string(cheAcc.getId());
            x++;
            inputArr[x] = "Balance: " + to_string(cheAcc.getBalance());
            x++;
            inputArr[x] = "\n";
            x++;
            inputArr[x] = "The maximum capacity is: " + to_string(cheAcc.getCap());
            x++;

            string un = "";
            if (!cheAcc.isLocked())
                un = "not ";

            inputArr[x] = "The sub-account is " + un + "locked.";
            x++;
            inputArr[x] = "\n";
        }
    }
};

#endif