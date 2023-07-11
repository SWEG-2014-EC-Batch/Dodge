#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num);

int main()
{
    int num1 = 7;
    bool result1 = isPrime(num1);
    cout << num1 << " is prime: " << result1 << endl;
    int num2 = 20;
    bool result2 = isPrime(num2);
    cout << num2 << " is prime: " << result2 << endl;
    int num3 = 997;
    bool result3 = isPrime(num3);
    cout << num3 << " is prime: " << result3 << endl;
    int num4 = 1;
    bool result4 = isPrime(num4);
    cout << num4 << " is prime: " << result4 << endl;
    return 0;
}

bool isPrime(int num)
{
    if (num < 2 || num > 1000)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}