#include <iostream>
using namespace std;

class InsufficientFundsException {
    double attempted;
public:
    InsufficientFundsException(double amt) : attempted(amt) {}
    void showError() {
        cout << "Error: Insufficient funds! Attempted: $" << attempted << endl;
    }
};

class BankAccount {
    double balance;
    static int logIndex;
    static string logs[20];

public:
    BankAccount(double b = 0) : balance(b) {
        logEvent("BankAccount constructor");
    }

    ~BankAccount() {
        logEvent("BankAccount destructor");
    }

    void deposit(double amt) {
        logEvent("deposit() entry");
        if(amt <= 0) {
            throw "Invalid deposit amount!";
        }
        balance += amt;
        cout << "Deposited: $" << amt << " New balance: $" << balance << endl;
        logEvent("deposit() exit");
    }

    void withdraw(double amt) {
        logEvent("withdraw() entry");
        if(amt <= 0) {
            throw "Invalid withdrawal amount!";
        }
        if(amt > balance) {
            throw InsufficientFundsException(amt);
        }
        balance -= amt;
        cout << "Withdrew: $" << amt << " New balance: $" << balance << endl;
        logEvent("withdraw() exit");
    }

    static void logEvent(string msg) {
        logs[logIndex++] = msg;
    }

    static void showLogs() {
        cout << "\nTransaction Logs:" << endl;
        for(int i = 0; i < logIndex; i++) {
            cout << i+1 << ". " << logs[i] << endl;
        }
    }
};

int BankAccount::logIndex = 0;
string BankAccount::logs[20];

int main() {
    BankAccount acc(1000);

    try {
        acc.deposit(500);
        acc.withdraw(200);
        acc.withdraw(1500);
    } catch(...) {
        cout << "Transaction failed!" << endl;
    }

    BankAccount::showLogs();
    return 0;
}
