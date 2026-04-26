#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class loan
{
    int loanid;
    string name;
    double totalloanamount;
    float annualintrate;
    int loantenure;

public:

    loan()
    {
        loanid = 0;
        name = "unknown";
        totalloanamount = 0;
        annualintrate = 0;
        loantenure = 0;
    }

    loan(int id,string n,double t,double intrate,int lt)
    {
        loanid = id;
        name = n;
        totalloanamount = t;
        annualintrate = intrate;
        loantenure = lt;
    }

    void getdata()
    {
        cout<<"Enter loan id:\n";
        cin>>loanid;

        cout<<"Enter your name:\n";
        cin>>name;

        cout<<"Enter total loan amount:\n";
        cin>>totalloanamount;

        cout<<"Enter annual interest rate:\n";
        cin>>annualintrate;

        cout<<"Enter loan tenure (years):\n";
        cin>>loantenure;
    }

    void calculateemi()
    {
        double R = annualintrate / (12 * 100);
        int N = loantenure * 12;

        double emi = (totalloanamount * R * pow(1 + R, N)) / (pow(1 + R, N) - 1);

        cout<<"Your monthly EMI is: "<<emi<<endl;
    }

    void display()
    {
        cout<<"Loan ID: "<<loanid<<endl;
        cout<<"Applicant Name: "<<name<<endl;
        cout<<"Total Loan Amount: "<<totalloanamount<<endl;
        cout<<"Annual Interest Rate: "<<annualintrate<<endl;
        cout<<"Loan Tenure (years): "<<loantenure<<endl;
    }
};

int main()
{
    int n;
    loan obj;

    cout<<"How many loan applicants today?\n";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        obj.getdata();
        obj.calculateemi();
        obj.display();
    }

    return 0;
}
