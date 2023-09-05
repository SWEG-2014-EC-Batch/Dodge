#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    bubbleSort(myArray, size);
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;
    return 0;
}
