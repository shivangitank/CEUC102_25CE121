#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& os) {
    return os << "$";
}

int main() {
    cout << fixed << setprecision(2);

    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(12) << "Fees" << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    string names[] = {"Alice", "Bob", "Carol", "David", "Eve"};
    float marks[] = {85.5, 92.3, 78.9, 88.7, 95.2};
    float fees[] = {5000, 5200, 4800, 5100, 5300};

    for(int i = 0; i < 5; i++) {
        cout << left << setw(15) << names[i]
             << setw(10) << marks[i]
             << currency << setw(10) << fees[i] << endl;
    }

    return 0;
}
