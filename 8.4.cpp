#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    double total = 0;
    int validLines = 0, errorLines = 0;

    while(true) {
        cout << "Enter filename: ";
        cin >> filename;

        ifstream file(filename);
        if(!file.is_open()) {
            cout << "File not found! Try again or 'quit' to exit: ";
            string choice;
            cin >> choice;
            if(choice == "quit") return 0;
            continue;
        }

        string line;
        int lineNum = 0;

        while(getline(file, line)) {
            lineNum++;
            stringstream ss(line);
            double num;

            try {
                if(!(ss >> num)) {
                    throw "Non-numeric data";
                }
                total += num;
                validLines++;
            } catch(...) {
                cout << "Line " << lineNum << " corrupted: " << line << endl;
                errorLines++;
            }
        }

        file.close();
        cout << "Valid lines: " << validLines << ", Errors: " << errorLines << endl;
        cout << "Sum of valid numbers: " << total << endl;
        break;
    }

    return 0;
}
