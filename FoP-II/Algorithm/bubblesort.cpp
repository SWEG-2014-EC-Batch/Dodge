#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    sort(myArray, myArray + size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}
