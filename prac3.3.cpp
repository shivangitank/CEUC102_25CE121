#include <iostream>
#include <string>
using namespace std;

class community_bank {
    int acc_no;
    string holder_name;
    double curr_balance;
    double transfermoney;
    int nacc_no;

    static int total;
    static int next_acc_no;

public:
    community_bank() {
        acc_no = next_acc_no++;
        holder_name = "";
        curr_balance = 0.0;
        transfermoney = 0.0;
        nacc_no = 0;
        total++;
    }

    void getdata() {
        cout << "Enter your name: ";
        cin >> holder_name;

        cout << "Enter initial balance: ";
        cin >> curr_balance;
    }

    void transfer() {
        cout << "Your account number is: " << acc_no << endl;
        cout << "To which account do you want to transfer the money? ";
        cin >> nacc_no;

        if (acc_no == nacc_no) {
            cout << "This is your own account number. Enter someone else's account number.\n";
            cin >> nacc_no;
        }

        cout << "How much money do you want to transfer? ";
        cin >> transfermoney;

        if (curr_balance < transfermoney) {
            cout << "Not possible! Balance too low.\n";
        }
        else if (curr_balance <= 500) {
            cout << "Money can't be transferred as balance is low.\n";
        }
        else {
            curr_balance -= transfermoney;
            cout << "Money transferred successfully.\n";
            cout << "Now your balance is: " << curr_balance << endl;
        }
    }

    void display() {
        cout << "Account No: " << acc_no << endl;
        cout << "Holder Name: " << holder_name << endl;
        cout << "Current Balance: " << curr_balance << endl;
    }

    static void displayTotal() {
        cout << "Total accounts created today: " << total << endl;
    }
};

int community_bank::total = 0;
int community_bank::next_acc_no = 1001;

int main() {
    int n;
    char yes;

    cout << "How many accounts do you want to add today?\n";
    cin >> n;

    community_bank s1[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEntering details for account " << i + 1 << endl;
        s1[i].getdata();
    }

    cout << "Do you want to transfer money? (y/n)\n";
    cin >> yes;

    if (yes == 'y' || yes == 'Y') {
        int x;
        cout << "Which account holder wants to transfer money? Enter account index (1 to " << n << "): ";
        cin >> x;
        s1[x - 1].transfer();
    }

    cout << "\nAccount details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nDetails of account " << i + 1 << ":\n";
        s1[i].display();
    }

    community_bank::displayTotal();

    return 0;
}
