#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number);

int main()
{
    int input;

    cout << "Enter a number: ";
    cin >> input;

    if (isPrime(input))
        cout << input << " is a prime number." << endl;

    else
        cout << input << " is not a prime number." << endl;

    return 0;
}

bool isPrime(int number)
{
    if (number < 2 || number > 1000)
        return false;

    for (int i = 2; i <= sqrt(number); ++i)
        if (number % i == 0)
            return false;

    return true;
}
