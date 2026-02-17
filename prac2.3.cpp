#include<iostream>
#include<string>
using namespace std;

class saving_acc {
    int acc_id;
    string name;
    float balance;

public:
    saving_acc() {
        acc_id = 0;
        balance = 0;
    }

    void create_acc(int id) {
        acc_id = id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if(amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!\n";
    }

    void display() {
        cout << "\nAccount ID: " << acc_id
             << "\nName: " << name
             << "\nCurrent Balance: " << balance << "\n";
    }
};

int main() {
    saving_acc s;
    int choice;

    do {
        cout << "\n1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: s.create_acc(1); break;
            case 2: s.deposit(); break;
            case 3: s.withdraw(); break;
            case 4: s.display(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}
