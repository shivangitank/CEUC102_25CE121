#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {
    double value;
public:
    NegativeNumberException(double v) : value(v) {}
    void showError() {
        cout << "Error: Cannot compute square root of negative number: " << value << endl;
    }
};

double safeSqrt(double num) {
    if(num < 0) {
        throw NegativeNumberException(num);
    }
    return sqrt(num);
}

int main() {
    double num;

    while(true) {
        try {
            cout << "Enter number: ";
            cin >> num;

            double result = safeSqrt(num);
            cout << "Square root: " << result << endl;
            break;

        } catch(NegativeNumberException& e) {
            e.showError();
            cout << "Enter valid number: ";
        }
    }

    return 0;
}
