#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<int> input;
    set<int> unique;
    int n, num;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> num;
        input.push_back(num);
        unique.insert(num);
    }

    cout << "Original: ";
    for(int x : input) cout << x << " ";
    cout << endl;

    cout << "Unique (sorted): ";
    for(int x : unique) cout << x << " ";
    cout << endl;

    cout << "Duplicates removed: " << (n - unique.size()) << endl;

    return 0;
}
