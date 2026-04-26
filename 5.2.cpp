#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");
    if(!file) {
        cout << "File not found!" << endl;
        return 1;
    }

    int chars = 0, words = 0, lines = 0;
    string line;

    while(getline(file, line)) {
        lines++;
        chars += line.length();

        bool inWord = false;
        for(char c : line) {
            if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                if(!inWord) {
                    words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;

    file.close();
    return 0;
}
