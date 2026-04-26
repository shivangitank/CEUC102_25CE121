#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }

    double add(double a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    cout << "Enter 2 integers: ";
    int a, b; cin >> a >> b;
    cout << "Sum: " << calc.add(a, b) << endl;

    cout << "Enter 2 floats: ";
    double x, y; cin >> x >> y;
    cout << "Sum: " << calc.add(x, y) << endl;

    cout << "Enter int and float: ";
    int p; double q; cin >> p >> q;
    cout << "Sum: " << calc.add(p, q) << endl;

    cout << "Enter 3 integers: ";
    int r, s, t; cin >> r >> s >> t;
    cout << "Sum: " << calc.add(r, s, t) << endl;

    return 0;
}
