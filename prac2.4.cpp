#include <iostream>
#include <string>
using namespace std;

class store {
private:
    int itemid;
    string itemname;
    double price;
    int quantity;

public:
    store() {
        itemid = 0;
        itemname = "unknown";
        price = 0.0;
        quantity = 0;
    }

    store(int id, string n, double p, int qty) {
        itemid = id;
        itemname = n;
        price = p;
        quantity = qty;
    }

    void increasestock(int nqty) {
        quantity += nqty;
    }

    void sellitem(int nqty) {
        if (nqty <= quantity) {
            quantity -= nqty;
            cout << "Item sold successfully!\n";
        } else {
            cout << "Insufficient stock!\n";
        }
    }

    void display() {
        cout << "\nItem ID: " << itemid
             << "\nItem Name: " << itemname
             << "\nPrice: " << price
             << "\nQuantity: " << quantity << endl;
    }
};

int main() {
    int id, qty, choice;
    string name;
    double price;

    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> qty;

    store s(id, name, price, qty);

    do {
        cout << "\nRetail Store Menu\n";
        cout << "1. Add Stock\n";
        cout << "2. Sell Item\n";
        cout << "3. Display Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter quantity to add: ";
            cin >> qty;
            s.increasestock(qty);
            break;

        case 2:
            cout << "Enter quantity to sell: ";
            cin >> qty;
            s.sellitem(qty);
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
