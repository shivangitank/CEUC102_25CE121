#include <iostream>
using namespace std;

class Grading {
protected:
    double marks;
public:
    Grading(double m) : marks(m) {}
    virtual char getGrade() = 0;
    double getMarks() { return marks; }
    virtual ~Grading() {}
};

class Undergraduate : public Grading {
public:
    Undergraduate(double m) : Grading(m) {}
    char getGrade() {
        if(marks >= 90) return 'A';
        if(marks >= 80) return 'B';
        if(marks >= 70) return 'C';
        return 'F';
    }
};

class Postgraduate : public Grading {
public:
    Postgraduate(double m) : Grading(m) {}
    char getGrade() {
        if(marks >= 85) return 'A';
        if(marks >= 75) return 'B';
        if(marks >= 65) return 'C';
        return 'F';
    }
};

int main() {
    cout << "Enter UG marks: ";
    double m1; cin >> m1;
    Undergraduate ug(m1);

    cout << "Enter PG marks: ";
    double m2; cin >> m2;
    Postgraduate pg(m2);

    Grading* students[] = {&ug, &pg};

    for(int i = 0; i < 2; i++) {
        cout << "Student " << i+1 << " (marks=" << students[i]->getMarks()
             << "): Grade = " << students[i]->getGrade() << endl;
    }

    return 0;
}
