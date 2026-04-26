#include <iostream>
using namespace std;

class Celsius {
    double c;
public:
    Celsius(double temp) : c(temp) {}

    operator Fahrenheit() {
        return Fahrenheit((c * 9/5) + 32);
    }
};

class Fahrenheit {
    double f;
public:
    Fahrenheit(double temp) : f(temp) {}

    operator Celsius() {
        return Celsius((f - 32) * 5/9);
    }

    bool operator==(const Fahrenheit& other) {
        return f == other.f;
    }

    void display() {
        cout << f << "°F" << endl;
    }
};

int main() {
    cout << "Enter Celsius: ";
    double c; cin >> c;
    Celsius cel(c);

    cout << "Enter Fahrenheit: ";
    double f; cin >> f;
    Fahrenheit fah(f);

    Fahrenheit f_from_c = cel;
    cout << "Celsius to F: "; f_from_c.display();

    Celsius c_from_f = fah;
    cout << "Fahrenheit to C: " << c_from_f.c << "°C" << endl;

    cout << "Enter another F to compare: ";
    double f2; cin >> f2;
    Fahrenheit fah2(f2);
    cout << "Equal: " << (fah == fah2) << endl;

    return 0;
}
