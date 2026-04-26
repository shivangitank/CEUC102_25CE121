#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec;
    int n, num;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }

    cout << "Original: ";
    for(int x : vec) cout << x << " ";
    cout << endl;

    vector<int> vec1 = vec;
    reverse(vec1.begin(), vec1.end());
    cout << "STL reverse: ";
    for(int x : vec1) cout << x << " ";
    cout << endl;

    vector<int> vec2 = vec;
    auto start = vec2.begin();
    auto end = vec2.end();
    while(start < end) {
        swap(*start, *(--end));
        start++;
    }
    cout << "Manual reverse: ";
    for(int x : vec2) cout << x << " ";
    cout << endl;

    return 0;
}
