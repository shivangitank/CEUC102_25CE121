#include <iostream>
#include <cstring>
using namespace std;

void toLower(char* str) {
    for(int i = 0; str[i]; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    char paragraph[1000];
    cout << "Enter paragraph: ";
    cin.getline(paragraph, 1000);

    char words[50][50];
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.?!");
    while(token) {
        toLower(token);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ,.?!");
    }

    int freq[50] = {0};
    cout << "\nWord Frequencies:" << endl;
    for(int i = 0; i < wordCount; i++) {
        bool found = false;
        for(int j = 0; j < i; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                found = true;
                break;
            }
        }
        if(!found) {
            int count = 0;
            for(int k = 0; k < wordCount; k++) {
                if(strcmp(words[i], words[k]) == 0) count++;
            }
            cout << words[i] << ": " << count << endl;
        }
    }

    return 0;
}
