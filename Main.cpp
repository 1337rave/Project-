#include "finance.h"
#include <iostream>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void displayMenu() {
    std::cout << BLUE << "\n==========================================\n";
    std::cout << "           Personal Finance Manager       \n";
    std::cout << "==========================================\n";
    std::cout << YELLOW << "1. Add Wallet\n";
    std::cout << "2. Add Transaction\n";
    std::cout << "3. Generate Report\n";
    std::cout << "4. Save to File\n";
    std::cout << "5. View All Wallets\n";
    std::cout << "6. View Last Transactions\n";
    std::cout << "7. Add Balance\n";
    std::cout << RED << "7. Exit\n";
    std::cout << BLUE << "==========================================\n";
    std::cout << "Enter your choice: " << RESET;
}

void viewAllWallets() {
    std::cout << "\n" << BLUE << "List of all wallets:\n" << RESET;
    for (size_t i = 0; i < wallets.size(); ++i) {
        std::cout << GREEN << "Wallet " << i + 1 << ": " << RESET << wallets[i].name << " (Balance: " << wallets[i].balance << ")\n";
    }
}

void viewLastTransactions() {
    std::cout << "\n" << BLUE << "Last transactions:\n" << RESET;
    for (const auto& wallet : wallets) {
        std::cout << GREEN << "Wallet: " << RESET << wallet.name << "\n";
        for (size_t i = 0; i < wallet.transactions.size() && i < 5; ++i) {
            std::cout << YELLOW << "Category: " << RESET << wallet.transactions[i].category << ", " << YELLOW << "Amount: " << RESET << wallet.transactions[i].amount << "\n";
        }
    }
}

int main() {
    int choice;
    bool exit = false;
    std::string name, category;
    double amount;

    while (!exit) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << GREEN << "\nEnter wallet name: ";
            std::cin >> name;
            std::cout << "Enter initial balance: ";
            std::cin >> amount;
            addWallet(name, amount);
            std::cout << "\n" << GREEN << "Wallet added successfully!\n";
            break;
        case 2:
            int walletIndex;
            std::cout << GREEN << "\nEnter wallet index: ";
            std::cin >> walletIndex;

            while (std::cin.fail()) {
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                std::cout << RED << "Invalid input. Please enter a valid number: " << RESET;
                std::cin >> walletIndex;  
            }

            std::cin.ignore();  
            std::cout << "Enter transaction category: ";
            std::getline(std::cin, category); 

            std::cout << "Enter transaction amount: ";
            std::cin >> amount;
            while (std::cin.fail()) {
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                std::cout << RED << "Invalid input. Please enter a valid number: " << RESET;
                std::cin >> amount; 
            }

            addTransaction(walletIndex, category, amount);
            std::cout << "\n" << GREEN << "Transaction added successfully!\n";
            break;

        case 3:
            int reportIndex;
            std::cout << GREEN << "\nEnter wallet index for report: ";
            std::cin >> reportIndex;
            std::cout << "Enter period (day/week/month): ";
            std::cin >> category;
            generateReport(reportIndex, category);
            break;
        case 4:
            saveToFile();
            std::cout << "\n" << GREEN << "Data saved to file.\n";
            break;
        case 5:
            viewAllWallets();
            break;
        case 6:
            viewLastTransactions();
            break;
        case 7:
             exit = true;
             std::cout << "\n" << RED << "Exiting program.\n";
             break;
        default:
             std::cout << "\n" << RED << "Invalid choice. Please enter a number between 1 and 7.\n";
             break;
            }
        }

        return 0;
        }

