#include <iostream>
using namespace std;

int main()
{
    int letters[26][2];

    for (int i = 0; i < 26; i++)
    {
        letters[i][0] = 65 + i;
        letters[i][1] = 97 + i;
    }

    for (int i = 0; i < 26; i++)
    {
        if ((i) % 5 == 0)
        {
            cout << endl;
        }
        cout << (char)letters[i][0] << (char)letters[i][1] << " ";
    }
    return 0;
}
