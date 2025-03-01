#include <string>
#include <ctime>
#include <vector>
#include <iostream>

struct Transaction{
    std::string category;
    double amount;
    std::string description;
    std::string date;
};

class FinanceManager{
    private:
        std::vector<Transaction> transactions;
    public:
        void AddTransaction(const Transaction& transaction);
        void ShowBalance();
        void ShowTransactions();
};

void ShowMenu(){
    std::cout << "1. Add transaction\n";
    std::cout << "2. Show balance\n";
    std::cout << "3. Show all transactions\n";
    std::cout << "4. Quit\n";
    std::cout << "\n";
}

int main(){
    FinanceManager manager;
    int choice;
    do{
        ShowMenu();
        std::cin >> choice;
        std::cout << "\n";
        std::cin.ignore();
        switch (choice) {
            case 1:{
                Transaction transaction;
                std::time_t now = std::time(nullptr);
                std::tm* local_time = std::localtime(&now);
                transaction.date = std::asctime(local_time);
                transaction.date.pop_back();
                std::cout << "Type a category: ";
                std::getline(std::cin, transaction.category);
                std::cout << "Type a amount: ";
                std::cin >> transaction.amount;
                std::cin.ignore();
                std::cout << "Type a description: ";
                std::getline(std::cin, transaction.description);
                std::cout << "\n";
                manager.AddTransaction(transaction);
                break;
            }
            case 2:
                manager.ShowBalance();
                std::cout << "\n";
                break;
            case 3:
                manager.ShowTransactions();
                break;
            case 4:
                break;
            default:
                std::cout << "Invalid choice!"<< std::endl;
        }
    }while(choice != 4);
    

}

void FinanceManager::AddTransaction(const Transaction& transaction){
    transactions.push_back(transaction);
}

void FinanceManager::ShowBalance(){
    double balance = 0;
    for (const Transaction& transaction:transactions){
        balance += transaction.amount;
    }
    std::cout << "Your balance: " << balance;
}

void FinanceManager::ShowTransactions(){
    for (const Transaction& transaction:transactions){
        std::cout << "Category: " << transaction.category << std::endl;
        std::cout << "Date: " << transaction.date << std::endl;
        std::cout << "Amount " << transaction.amount << std::endl;
        std::cout << "Description: " << transaction.description << std::endl;
        std::cout << "\n";
    }
}
