#ifndef FINANCE_H
#define FINANCE_H

#include <string>
#include <vector>

struct Transaction {
    std::string category;
    double amount;
};

struct Wallet {
    std::string name;
    double balance;
    std::vector<Transaction> transactions;
};

extern std::vector<Wallet> wallets;

void addWallet(std::string name, double initialBalance);
void addTransaction(int walletIndex, std::string category, double amount);
void generateReport(int walletIndex, std::string period);
void saveToFile();

#endif // FINANCE_H