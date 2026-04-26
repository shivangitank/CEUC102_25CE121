#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void addItem() {
    ofstream file("inventory.txt", ios::app);
    char name[50];
    int qty, price;

    cout << "Enter item name: ";
    cin.getline(name, 50);
    cin.ignore();
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    file << name << "," << qty << "," << price << endl;
    file.close();
    cout << "Item added!" << endl;
}

void viewItems() {
    ifstream file("inventory.txt");
    string line;
    cout << "\nAll Items:" << endl;
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchItem() {
    char search[50];
    cout << "Enter item name to search: ";
    cin.getline(search, 50);

    ifstream file("inventory.txt");
    string line;
    bool found = false;
    while(getline(file, line)) {
        if(line.find(search) == 0) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }
    if(!found) cout << "Item not found!" << endl;
    file.close();
}

int main() {
    int choice;
    while(true) {
        cout << "\n1. Add Item  2. View Items  3. Search Item  0. Exit\n";
        cin >> choice;
        cin.ignore();

        if(choice == 1) addItem();
        else if(choice == 2) viewItems();
        else if(choice == 3) searchItem();
        else break;
    }
    return 0;
}
