#include <iostream>
using namespace std;
int main()
{
    int num, factorial = 1;
    cout << "enter a number to get the factorial: ";
    cin >> num;
    if (num < 0)
    {
        cout << "invalid";
    }

    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    cout << factorial;
}
