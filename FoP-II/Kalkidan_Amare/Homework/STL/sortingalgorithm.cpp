#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    selectionSort(myArray, size);
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;
    return 0;
}
