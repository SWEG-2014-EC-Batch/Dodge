
#include <iostream>
using namespace std;

int main()
{
    int size, array[10], x = 0, y = 0, i = 0;
    cout << "enter size ";
    cin >> size;
    cout << "enter each " << size << " elements";
    for (i = 0; i < size; i++)
        cin >> array[i];

    for (i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            x += 1;
        }
        else
        {
            y += 1;
        }
    }
    cout << "no of even " << x << "\n";
    cout << "no of odd " << y;

    return 0;
}
