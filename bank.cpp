// Simple Bank Account Project
// By: Areesh Nadeem

#include <iostream>
using namespace std;

class Account {
    private:
        string name;
        string account_num;
        double balance;
    public:
        Account(string name, string account_num, double balance) {
            this->name = name;
            this->account_num = account_num;
            this->balance = balance;
        }

        // method for depositing money
        void deposit(double amount) {
            balance = balance + amount;
            cout << "$" << amount << " Successfully deposited. New balance is $" << balance;
        }

        // method for withdrawing money
        void withdraw(double amount) {
            if (balance >= amount) {
                balance = balance - amount;
                cout << "$" << amount << " Successfully withdrawn. New balance is $" << balance;
            } else {
                cout << "Insufficient funds.\n";
            }
        }

        // method to get account information
        void display() {
            cout << "Account information for " << name << ":" << endl;
            cout << "Account number: " << account_num << endl;
            cout << "Balance: $" << balance << endl;
        }
};


int main() {
    string name, account_num;
    double balance;

    // prompt the user for their account information
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account number: ";
    cin >> account_num;
    cout << "Enter your initial balance: ";
    cin >> balance;

    // create an Account object with the user's information
    Account myAccount(name, account_num, balance);

    int choice = 0;

    while (choice != 4) {
        // displays list of choices user can make
        cout << "\n1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View account information\n";
        cout << "4. Quit\n";
        cout << "How can we help you today?:\n";
        cin >> choice;

        // depending on what the user picks, it will perform corresponding action
        if (choice == 1) {
            double deposit_amount;
            cout << "Enter the amount you would like to deposit: ";
            cin >> deposit_amount;
            myAccount.deposit(deposit_amount);
        } else if (choice == 2) {
            double withdraw_amount;
            cout << "Enter the amount you would like to withdraw: ";
            cin >> withdraw_amount;
            myAccount.withdraw(withdraw_amount);
        } else if (choice == 3) {
            myAccount.display();
        } else if (choice == 4) {
            cout << "Thank you, have a nice day!\n";
        } else {
            cout << "Invalid choice, inputs 1 - 4 are accepted.\n";
        }
    }

    return 0;
}


