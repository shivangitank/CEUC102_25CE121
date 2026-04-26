#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
    }

    void updateByPointer(Point* p) {
        p->x = 0;
        p->y = 0;
    }

    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(1, 2);
    p.display();

    p.move(2, 3).move(-1, 4).move(5, -2);
    p.display();

    Point* ptr = &p;
    ptr->updateByPointer(ptr);
    p.display();

    return 0;
}
