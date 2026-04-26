#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int cap = 4) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void insert(int value) {
        if(size == capacity) {
            int* newArr = new int[capacity * 2];
            for(int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[size++] = value;
    }

    void remove(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        for(int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        cout << "Array [size=" << size << "]: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray da;

    da.insert(10); da.display();
    da.insert(20); da.display();
    da.insert(30); da.display();
    da.insert(40); da.display();
    da.insert(50); da.display();

    da.remove(1); da.display();
    da.remove(2); da.display();

    return 0;
}
