#include <iostream>
using namespace std;

int main()
{
    int i,n;
    cout<<"for how many times do you want to calculate: ";
    cin>>n;
    i=0;
    while(i<n){
        i++;
    char symbol;
    cout << "Enter a character: ";
    cin >> symbol;
    if (symbol >= 'a' && symbol <= 'z')
    {
        if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u')
        {
            cout << "It is a lower case vowel" << endl;
        }
        else
        {
            cout << "It is a lower case consonant" << endl;
        }
    }
    else if (symbol >= 'A' && symbol <= 'Z')
    {
        if (symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U')
        {
            cout << "It is a upper case vowel" << endl;
        }
        else
        {
            cout << "It is a upper case consonant" << endl;
        }
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
 }
    return 0;
}