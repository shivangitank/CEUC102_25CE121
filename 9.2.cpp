#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter sentence: ";
    getline(cin, sentence);

    map<string, int> wordCount;
    stringstream ss(sentence);
    string word;

    while(ss >> word) {
        wordCount[word]++;
    }

    cout << "\nWord frequencies:" << endl;
    for(auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
