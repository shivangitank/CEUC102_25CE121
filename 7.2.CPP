#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    cout << "Enter complex1 (real imag): ";
    double r1, i1; cin >> r1 >> i1;
    Complex c1(r1, i1);

    cout << "Enter complex2 (real imag): ";
    double r2, i2; cin >> r2 >> i2;
    Complex c2(r2, i2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "Sum: "; sum.display();
    cout << "Difference: "; diff.display();

    return 0;
}
