#include "finance.h"
#include <iostream>
#include <fstream>

std::vector<Wallet> wallets;

void addWallet(std::string name, double initialBalance) {
    wallets.push_back({ name, initialBalance, {} });
}

void addTransaction(int walletIndex, std::string category, double amount) {
    wallets[walletIndex].transactions.push_back({ category, amount });
    wallets[walletIndex].balance -= amount;
}

void generateReport(int walletIndex, std::string period) {
    std::cout << "Report for wallet: " << wallets[walletIndex].name << std::endl;

    if (period == "day") {
    }
    else if (period == "week") {
    }
    else if (period == "month") {
    }
    else {
        std::cout << "Invalid period specified!\n";
    }
}


void saveToFile() {
    std::ofstream file("financial_report.txt");
    if (file.is_open()) {
        for (const auto& wallet : wallets) {
            file << "Wallet: " << wallet.name << ", Balance: " << wallet.balance << std::endl;
            for (const auto& transaction : wallet.transactions) {
                file << "Category: " << transaction.category << ", Amount: " << transaction.amount << std::endl;
            }
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}
