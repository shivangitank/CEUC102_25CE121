#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    // ~Base() {}  // First test WITHOUT virtual
    virtual ~Base() { cout << "Base virtual destructor" << endl; }  // Then WITH virtual
};

class Derived : public Base {
    int* resource;
public:
    Derived() {
        resource = new int[1000];
        cout << "Derived constructor - allocated resource" << endl;
    }

    ~Derived() {
        delete[] resource;
        cout << "Derived destructor - freed resource" << endl;
    }
};

int main() {
    cout << "\n=== Test 1: Base* pointing to Derived ===" << endl;
    Base* ptr = new Derived();
    delete ptr;  // Check if Derived destructor is called!

    cout << "\nPress Enter to test with virtual destructor...";
    cin.get();

    return 0;
}
