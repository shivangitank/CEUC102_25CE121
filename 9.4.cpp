#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, vector<string>> directory;

void addFolder() {
    string folder;
    cout << "Enter folder name: ";
    cin >> folder;
    directory[folder];
    cout << "Folder '" << folder << "' added!" << endl;
}

void addFile() {
    string folder, file;
    cout << "Enter folder name: ";
    cin >> folder;
    cout << "Enter file name: ";
    cin >> file;

    if(directory.find(folder) != directory.end()) {
        directory[folder].push_back(file);
        cout << "File '" << file << "' added to '" << folder << "'" << endl;
    } else {
        cout << "Folder not found!" << endl;
    }
}

void displayDirectory() {
    cout << "\nDirectory:" << endl;
    for(auto& pair : directory) {
        cout << pair.first << ": ";
        for(string f : pair.second) {
            cout << f << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;

    while(true) {
        cout << "\n1. Add Folder  2. Add File  3. Display  0. Exit\n";
        cin >> choice;

        if(choice == 1) addFolder();
        else if(choice == 2) addFile();
        else if(choice == 3) displayDirectory();
        else break;
    }

    return 0;
}
