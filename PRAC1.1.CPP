#include <iostream>
using namespace std;

class bank_account
{
    char account_name[25];
    double accountno;
    double balance;

public:
    void createacc()
    {
        cout << "Enter account holder name: ";
        cin >> account_name;
        cout << "Enter account number: ";
        cin >> accountno;
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void depositmoney(double amount)
    {
        balance = balance + amount;
        cout << "Money deposited successfully.\n";
    }

    void withdrawmoney(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Money withdrawn successfully.\n";
        }
        else
        {
            cout << "Error: Insufficient balance.\n";
        }
    }

    void checkaccbalance()
    {
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    bank_account acc[i];
    int choice;int s;
    int acno;
    double deposite_money, withdraw_money;

    cout << "Welcome to our bank\n";
do{
menu:
    cout << "\nChoose an Operation:\n";
    cout << "1. Create an account\n";
    cout << "2. Deposit money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Check balance\n";
    cout << "5. exit\n";
    cout<<"6.back to menu\n";

    cin >> choice;

    switch (choice)
    {
        case 1:
            acc.createacc();
            goto menu;


        case 2:
            cout<<"enter the bank account no:";
            cin>>acno;
            if(acno==acc[i]accountno)
            {
            cout << "Enter the amount of money you want to deposit: ";
            cin >> deposite_money;
            acc.depositmoney(deposite_money);
            }
            else
            {
                "invalid account no"
            }

        case 3:
            cout<<"enter the bank account no:";
            cin>>acno;
            if(acno==acc[i]accountno)
            {
            cout << "Enter the amount of money you want to withdraw: ";
            cin >> withdraw_money;
            acc.withdrawmoney(withdraw_money);
            }
            else
            {
                "invalid account no"
            }


        case 4:

            cout<<"enter the bank account no:";
            cin>>acno;
            if(acno==acc[i]accountno)
            {
                acc.checkaccbalance();
                }
            else
            {
                "invalid account no"
            }

        case 5:
            break;

        default:
            goto menu;
    }}
    while(choice!=5);

    return 0;
}
