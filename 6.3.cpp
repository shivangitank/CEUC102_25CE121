#include <iostream>
#include <string>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string f) : fuelType(f) {}
};

class Brand {
protected:
    string brandName;
public:
    Brand(string b) : brandName(b) {}
};

class Car : public Fuel, public Brand {
public:
    Car(string f, string b) : Fuel(f), Brand(b) {}
    void display() {
        cout << "Car: " << brandName << " (" << fuelType << ")" << endl;
    }
};

int main() {
    Car cars[3] = {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Ford"),
        Car("Electric", "Tesla")
    };

    for(int i = 0; i < 3; i++) {
        cars[i].display();
    }

    return 0;
}
