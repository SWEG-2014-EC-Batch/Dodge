#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("Sheet5Ex5.cpp");
    if (!file) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    char ch;
    int count[26] = {0}; // Array to store the count of each character

    while (file.get(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++; // Increment the count for the corresponding character
        }
    }

    file.close();

    cout << "Character  Occurrences" << endl;

    for (int i = 0; i < 26; i++) {
        cout << static_cast<char>('a' + i) << "          " << count[i] << endl;
    }

    return 0;
}
