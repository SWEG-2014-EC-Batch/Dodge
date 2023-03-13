#include <iostream>
using namespace std;

int main()
{
    char symbol;
    cout << "Enter a character: ";
    cin >> symbol;

    if (symbol >= 'a' && symbol <= 'z')
    {
        cout << "It is a lowercase character" << endl;
        if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u')
        {
            cout << "It is a vowel" << endl;
        }
        else
        {
            cout << "It is a consonant" << endl;
        }
    }
    else if (symbol >= 'A' && symbol <= 'Z')
    {
        if (symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U')
        {
            cout << "It is a vowel" << endl;
        }
        else
        {
            cout << "It is a consonant" << endl;
        }
        cout << "It is an uppercase character" << endl;
    }
    else if (symbol >= '0' && symbol <= '9' && symbol % 2 == 0)
    {
        cout << "It is an even digit" << endl;
    }
    else if (symbol >= '0' && symbol <= '9')
    {
        cout << "It is an odd digit" << endl;
    }
    else
    {
        cout << "You entered a special character" << endl;
    }

    return 0;
}