#include <iostream>
using namespace std;

int iterativeSum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
int recursiveSum(int arr[], int index, int size) {

    if(index >= size) {
        return 0;
    }

    return arr[index] + recursiveSum(arr, index + 1, size);
}

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int iterSum = iterativeSum(arr, size);
    int recurSum = recursiveSum(arr, 0, size);


    cout << "\nRESULTS:" << endl;
    cout << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Iterative Sum: " << iterSum << endl;
    cout << "Recursive Sum: " << recurSum << endl;
    cout << "Match: " << (iterSum == recurSum ? "YES" : "NO") << endl;


    delete[] arr;

    return 0;
}
