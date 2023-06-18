#include <iostream>
using namespace std;
int main()
{
    int alpha[58];
    for (int i = 0; i <= 58; i++)
    {
        if (i >= 26 && i <= 31)
        {
            continue;
        }
        alpha[i] = 65 + i;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << char(alpha[i]) << char(alpha[i + 32]) << " ";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
}
