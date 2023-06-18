#include <iostream>
using namespace std;

int main()
{
    int n, rev = 0, rem, temp;
    //
    cout << "Enter a number: ";
    cin >> n;
    temp = n;
    while (temp != 0)
    {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }
    if (n == rev)
    {
        cout << n << " is a palindrome" << endl;
    }
    else
    {
        cout << n << " is not a palindrome" << endl;
    }
    cout << "the riverse pattern of the number is: " << rev;
    return 0;
}