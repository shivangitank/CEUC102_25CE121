#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double len, wid;
public:
    Rectangle(double l, double w) : len(l), wid(w) {}
    double area() { return len * wid; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() { return 3.14159 * radius * radius; }
};

int main() {
    Shape* shapes[4];

    cout << "Enter rectangle (l w): ";
    double l, w; cin >> l >> w;
    shapes[0] = new Rectangle(l, w);

    cout << "Enter circle radius: ";
    double r; cin >> r;
    shapes[1] = new Circle(r);

    cout << "Enter another rectangle (l w): ";
    cin >> l >> w;
    shapes[2] = new Rectangle(l, w);

    cout << "Enter another circle radius: ";
    cin >> r;
    shapes[3] = new Circle(r);

    cout << "\nAreas:" << endl;
    for(int i = 0; i < 4; i++) {
        cout << "Shape " << i+1 << ": " << shapes[i]->area() << endl;
        delete shapes[i];
    }

    return 0;
}
