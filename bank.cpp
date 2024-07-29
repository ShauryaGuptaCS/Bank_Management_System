#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Bank {
    string name, address;
    char acc_type;
    float balance;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
    void save_account();
    void load_account();

    string get_name() { return name; }
};

void Bank::open_account() {
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "What type of account you want to open - saving(S) or current(C): ";
    cin >> acc_type;
    cout << "Enter how much money you want to deposit: ";
    cin >> balance;
    cout << "Account Created Successfully\n";
    save_account();
}

void Bank::deposit_money() {
    float amount;
    cout << "Enter how much money you want to deposit: ";
    cin >> amount;
    balance += amount;
    cout << "You have deposited: " << amount << "\n";
    cout << "Available Balance: " << balance << "\n";
    save_account();
}

void Bank::withdraw_money() {
    float amount;
    cout << "Enter how much money you want to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance\n";
    } else {
        balance -= amount;
        cout << "You have withdrawn: " << amount << "\n";
        cout << "Available Balance: " << balance << "\n";
    }
    save_account();
}

void Bank::display_account() {
    cout << "Name: " << name << "\n"
         << "Address: " << address << "\n"
         << "Type: " << acc_type << "\n"
         << "Balance: " << balance << "\n\n";
}

void Bank::save_account() {
    ofstream file("accounts.txt");
    file << name << "\n" << address << "\n" << acc_type << "\n" << balance << "\n";
    file.close();
}

void Bank::load_account() {
    ifstream file("accounts.txt");
    if (file.is_open()) {
        getline(file, name);
        getline(file, address);
        file >> acc_type;
        file >> balance;
        file.ignore(); // To ignore the newline character after reading balance
        file.close();
    }
}

void display_menu() {
    cout << "Bank Management System\n";
    cout << "1. Open Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Display Account\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Bank customer;
    int choice;

    customer.load_account();

    while (true) {
        display_menu();
        cin >> choice;

        switch (choice) {
        case 1:
            customer.open_account();
            break;
        case 2:
            customer.deposit_money();
            break;
        case 3:
            customer.withdraw_money();
            break;
        case 4:
            customer.display_account();
            break;
        case 5:
            cout << "Thank you for using the Bank Management System.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "-------------------------\n";
    }

    return 0;
}
