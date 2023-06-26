#include "header.h"

int main()
{
    string str = "Kal Amare", str1 = "kalkidan", str2 = "kalk";
    int length, vowel, consonant;

    // length, vowel, consonant
    lenvowcon(str, length, vowel, consonant);
    cout << "Length of string: " << length << endl;
    cout << "Number of vowels: " << vowel << endl;
    cout << "Number of consonants: " << consonant << endl;

    // Reverse the string
    cout << "Reversed string: " << reverse(str, length) << endl;

    // compare strings
    int result = compare(str1, str2);
    if (result == 0)
        cout << "Strings are equal." << endl;
    else if (result == 1)
        cout << "First string is greater." << endl;
    else
        cout << "Second string is greater." << endl;

    // Convert to lowercase
    cout << "Strings are lowercased: " << tolower(str) << endl;

    // Convert to uppercase
    cout << "Strings are uppercased: " << toupper(str) << endl;

    return 0;
}