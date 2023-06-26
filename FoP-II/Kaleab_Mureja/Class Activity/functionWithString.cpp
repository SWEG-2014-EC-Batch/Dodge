#include <iostream>
#include <string>
using namespace std;

void printVowels(const string& str);

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    printVowels(input);

    return 0;
}

void printVowels(const string& str) {
    cout << "Vowel letters: ";
    for (char character : str) {
        // Convert the character to lowercase for easier comparison
        char lowercaseChar = tolower(character);

        // Check if the character is a vowel
        if (lowercaseChar == 'a' || lowercaseChar == 'e' ||
            lowercaseChar == 'i' || lowercaseChar == 'o' ||
            lowercaseChar == 'u') {
            cout << character << " ";
        }
    }
    cout << endl;
}