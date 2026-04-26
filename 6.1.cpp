#include <iostream>
using namespace std;

class Shape {
protected:
    double radius;
public:
    Shape(double r) : radius(r) {}
    double getRadius() { return radius; }
};

class Circle : public Shape {
public:
    Circle(double r) : Shape(r) {}
    double area() { return 3.14159 * radius * radius; }
};

int main() {
    Circle circles[5] = {
        Circle(5), Circle(3), Circle(8), Circle(2), Circle(7)
    };

    cout << "Circle Areas:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Circle " << i+1 << ": " << circles[i].area() << endl;
    }

    return 0;
}
