// checks if a number is arm strong.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, n = 0, result = 0;
    cout << "Enter an integer: ";
    cin >> num;
    int original = num;

    while (original != 0)
    {
        n++;
        original /= 10;
    }
    original = num;
    while (original != 0)
    {
        int remainder = original % 10;
        result += pow(remainder, n);
        original /= 10;
    }
    if (num == result)
    {
        cout << num << " is arm strong.";
    }
    else
    {
        cout << num << " is not arm strong.";
    }
    return 0;
}
