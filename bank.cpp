#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Bank {
    string name, address;
    string acc_type;
    float balance;

public:
    //Default Constructor
    Bank(){
        name="";
        address="";
        acc_type="Saving account";
        balance=0.00;
    }  

    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
    void save_account();
    void load_account();

    string get_name() { 
        return name; 
    }
};

//Open Account Function
void Bank::open_account() {
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your address: ";
    
    getline(cin, address);

    
    
    bool flag = false;
    while(!flag){
        cout << "Enter 1 for Saving account or 2 for Current account: ";
        int choice;
        cin>>choice;
        flag=true;
        switch(choice){
            case 1:
                acc_type="Saving account";
                break;
            case 2:
                acc_type="Current account";
                break;
            default:
                cout<<"Invalid choice you should either type value 1 or 2";
                flag = false;
        }
    }
    
    

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
    if (name == "") {
        cout << "No account information found. Please open an account first.\n";
        return;
    }
    cout << "Name: " << name << "\n"
         << "Address: " << address << "\n"
         << "Type: " << acc_type << "\n"
         << "Balance: " << balance << "\n\n";
}


//Save Account
void Bank::save_account() {
    ofstream file("accounts.txt");
    if (file.is_open()) {
        file << "Name: " << name << "\n";
        file << "Address: " << address << "\n";
        file << "Account-Type: " << acc_type << "\n";
        file << "Account Balance: " << balance << "\n";
        file.close();
    } else {
        cout << "Error saving account data.\n";
    }
}

void Bank::load_account() {
    ifstream file("accounts.txt");
    if (file.is_open()) {
        string line, label;
        getline(file, label);
        name = label.substr(label.find(": ") + 2);

        getline(file, label);
        address = label.substr(label.find(": ") + 2);

        getline(file, label);
        acc_type = label.substr(label.find(": ") + 2)[0];

        getline(file, label);
        balance = stof(label.substr(label.find(": ") + 2));

        file.close();
    } else {
        cout << "No account found. You may need to open a new account.\n";
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

    customer.load_account();  // Try to load account data from the file

        while (true) {
            display_menu();
            cin >> choice;

            switch (choice) {
            case 1:{
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
    }
    return 0;
}