#include <iostream>
// #include <array>
using namespace std;

int main()
{

    int arr[2][3] = {{45, 67, 75}, {64, 83, 59}};
    int(*p)[3] = arr;
    for (int i; i = 0; i < 2; i++)
    {
        for (int j; j = 0; j < 3; j++)
        {
            cout << *(*(p + i) + j) << " ";
        }

        cout << endl;
    }
    return 0;
}
