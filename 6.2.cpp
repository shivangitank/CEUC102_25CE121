#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void display() { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Employee : public Person {
protected:
    int empId;
public:
    Employee(string n, int a, int id) : Person(n, a), empId(id) {}
    void display() {
        Person::display();
        cout << "Emp ID: " << empId << endl;
    }
};

class Manager : public Employee {
    string dept;
public:
    Manager(string n, int a, int id, string d) : Employee(n, a, id), dept(d) {}
    void display() {
        Employee::display();
        cout << "Department: " << dept << endl;
    }
};

int main() {
    Manager mgr("John", 35, 101, "IT");
    mgr.display();
    return 0;
}
