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

void ShowMenu();

void ShowMenuCategory();

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
                int category_choice;
                do{
                    ShowMenuCategory();
                    while (true) {
                        std::cout << "Choose a category: ";
                        if (std::cin >> category_choice) {
                            // Ввод корректен, проверяем допустимость значения
                            if (category_choice >= 1 && category_choice <= 5) {
                                break; // Выход из цикла, если значение допустимо
                            } else {
                                std::cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                            }
                        } else {
                            // Ввод некорректен, очищаем поток и игнорируем ошибочные данные
                            std::cin.clear(); // Сбрасываем флаг ошибки
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем всё до конца строки
                            std::cout << "Invalid input! Please enter a number.\n";
                        }
                    }
                    switch (category_choice) {
                        case 1:
                            transaction.category = "Shop";
                            break;
                        case 2:
                            transaction.category = "Food";
                            break;
                        case 3:
                            transaction.category = "Transactions";
                            break;
                        case 4:
                            transaction.category = "Withdrawal";
                            break;
                        case 5:
                            transaction.category = "Other";
                            break;
                        /*case 6:
                             <#statements#>
                             break;
                        case 7:
                             <#statements#>
                             break;*/
                        default:
                            std::cout << "Invalid choice!"<< std::endl;
                            break;
                    }
                }while((category_choice != 1) && (category_choice != 2) && (category_choice != 3) && (category_choice != 4) && (category_choice != 5));
                int add_amount;
                while (true) {
                    std::cout << "Type an amount: ";
                    if (std::cin >> add_amount) {
                        transaction.amount = add_amount;
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                        std::cout << "Invalid input! Please enter a number.\n";
                    }
                }
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

void ShowMenu(){
    std::cout << "1. Add transaction\n";
    std::cout << "2. Show balance\n";
    std::cout << "3. Show all transactions\n";
    std::cout << "4. Quit\n";
    std::cout << "\n";
}

void ShowMenuCategory(){
    std::cout << "1. Shop\n";
    std::cout << "2. Food\n";
    std::cout << "3. Transactions\n";
    std::cout << "4. Withdrawal\n";
    std::cout << "5. Other\n";
    //std::cout << "6. Back\n";
    //std::cout << "7. Quit\n";
    std::cout << "\n";
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
    std::cout << "\n";
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
