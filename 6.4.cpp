#include <iostream>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;
public:
    Account(int no, double bal) : accNo(no), balance(bal) {}
    void deposit(double amt) { balance += amt; }
    bool withdraw(double amt) {
        if(balance >= amt) {
            balance -= amt;
            return true;
        }
        return false;
    }
    void display() {
        cout << "Acc: " << accNo << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(int no, double bal, double rate)
        : Account(no, bal), interestRate(rate) {}
    void addInterest() { balance += balance * interestRate; }
};

class CurrentAccount : public Account {
    double overdraftLimit;
public:
    CurrentAccount(int no, double bal, double limit)
        : Account(no, bal), overdraftLimit(limit) {}
    bool withdraw(double amt) {
        if(balance + overdraftLimit >= amt) {
            balance -= amt;
            return true;
        }
        return false;
    }
};

int main() {
    SavingsAccount sav(101, 10000, 0.05);
    CurrentAccount cur(102, 5000, 2000);

    sav.deposit(1000);
    sav.addInterest();
    sav.display();

    cur.withdraw(6000);
    cur.display();

    return 0;
}
