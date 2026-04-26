#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[50];
    float basicSalary;
    float bonus;

public:

    Employee(char* n, float basic) {
        strcpy(name, n);
        basicSalary = basic;
        bonus = basic * 0.1;}

    Employee(char* n, float basic, float b) {
        strcpy(name, n);
        basicSalary = basic;
        bonus = b;
    }


    inline float getTotalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << getTotalSalary() << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Employee* employees[5];


    employees[0] = new Employee("John", 50000);
    employees[1] = new Employee("Alice", 60000, 8000);
    employees[2] = new Employee("Bob", 45000);
    employees[3] = new Employee("Carol", 70000, 12000);
    employees[4] = new Employee("David", 55000);

    cout << "PAYROLL REPORT" << endl;
    cout << "==============" << endl;
    for(int i = 0; i < 5; i++) {
        employees[i]->display();
    }

    for(int i = 0; i < 5; i++) {
        delete employees[i];
    }

    return 0;
}
