#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    while(true) {
        try {
            cout << "Enter numerator: ";
            if(!(cin >> num1)) {
                throw "Invalid input!";
            }

            cout << "Enter denominator: ";
            if(!(cin >> num2)) {
                throw "Invalid input!";
            }

            if(num2 == 0) {
                throw "Division by zero!";
            }

            cout << "Result: " << (num1 / num2) << endl;
            break;

        } catch(const char* msg) {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}
