#include<iostream>
#include<string>
using namespace std;

class student{
    string name;
    double marks1,marks2,marks3;
    double average;

public:
    student()
    {
        name="unknown";
        marks1=0;
        marks2=0;
        marks3=0;
        average=0;
    }

    void input()
    {
        cout<<"Enter student name: ";
        cin>>name;

        cout<<"Marks of subject 1: ";
        cin>>marks1;

        cout<<"Marks of subject 2: ";
        cin>>marks2;

        cout<<"Marks of subject 3: ";
        cin>>marks3;
    }

    double calcavg()
    {
        average=(marks1+marks2+marks3)/3;
        return average;
    }

    void display()
    {
        cout<<"Average marks: "<<average<<endl;
    }
};

int main()
{
    int n;
    cout<<"No. of total students: ";
    cin>>n;

    student s[n];

    for(int i=0;i<n;i++)
    {
        cout<<"\nStudent "<<i+1<<endl;
        s[i].input();
        s[i].calcavg();
        s[i].display();
    }

    return 0;
}
