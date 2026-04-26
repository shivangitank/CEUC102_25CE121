#include <iostream>
#include <cstring>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int superDigit(int n) {
    if(n < 10) {
        return n;
    }
    return superDigit(digitSum(n));
}

int superDigitOptimized(string numStr, int k) {
    int len = strlen(numStr.c_str());
    int totalSum = 0;

    for(int i = 0; i < len; i++) {
        totalSum += numStr[i] - '0';
    }

    int fullCopiesSum = totalSum * k;
    return superDigit(fullCopiesSum);
}

int main() {
    int n, k;
    string numStr;

    cout << "Enter number of test cases: ";
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cout << "Test case " << i+1 << ":" << endl;
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter k: ";
        cin >> k;

        numStr = to_string(n);

        int result1 = superDigitOptimized(numStr, k);
        cout << "Super Digit: " << result1 << endl << endl;
    }

    return 0;
}
