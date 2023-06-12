#include <iostream>
using namespace std;
int main()
{
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;

    // upper
    for (int i = 1; i <= row; i++)
    {
        int temp = i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp - 1;
            temp--;
        }
        for (int k = 2 * row; k > 2 * i; k--)
        {
            cout << " ";
        }
        temp = i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp - i;
            temp++;
        }
        cout << endl;
    }

    // lower
    for (int i = row - 1; i >= 1; i--)
    {
        int temp = i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp - 1;
            temp--;
        }
        for (int k = 2 * row; k > 2 * i; k--)
        {
            cout << " ";
        }
        temp = i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp - i;
            temp++;
        }
        cout << endl;
    }
}
