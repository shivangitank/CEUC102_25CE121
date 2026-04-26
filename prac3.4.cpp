#include <iostream>
using namespace std;

// Display array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Find maximum element
template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Reverse array
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Print leader elements
template <typename T>
void printLeaders(T arr[], int size) {
    T leader = arr[size - 1];

    // Store leaders in temporary array to print in correct order
    T leaders[100];
    int count = 0;

    leaders[count++] = leader;

    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            leaders[count++] = leader;
        }
    }

    for (int i = count - 1; i >= 0; i--) {
        cout << leaders[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArr[] = {16, 17, 4, 3, 5, 2};
    float floatArr[] = {1.1, 3.5, 2.2, 5.6, 4.0};
    char charArr[] = {'a', 'z', 'c', 'b', 'y'};

    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    int charSize = sizeof(charArr) / sizeof(charArr[0]);

    // Integer array
    cout << "Integer Array: ";
    displayArray(intArr, intSize);
    cout << "Maximum: " << findMax(intArr, intSize) << endl;
    cout << "Leader Elements: ";
    printLeaders(intArr, intSize);
    reverseArray(intArr, intSize);
    cout << "Reversed Array: ";
    displayArray(intArr, intSize);

    cout << endl;

    // Float array
    cout << "Float Array: ";
    displayArray(floatArr, floatSize);
    cout << "Maximum: " << findMax(floatArr, floatSize) << endl;
    cout << "Leader Elements: ";
    printLeaders(floatArr, floatSize);
    reverseArray(floatArr, floatSize);
    cout << "Reversed Array: ";
    displayArray(floatArr, floatSize);

    cout << endl;

    // Character array
    cout << "Character Array: ";
    displayArray(charArr, charSize);
    cout << "Maximum: " << findMax(charArr, charSize) << endl;
    cout << "Leader Elements: ";
    printLeaders(charArr, charSize);
    reverseArray(charArr, charSize);
    cout << "Reversed Array: ";
    displayArray(charArr, charSize);

    return 0;
}
