#include <iostream>
using namespace std;

int findMin(const int arr[], int size)
{
    int minVal = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

int findMax(const int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int minVal = findMin(myArray, size);
    int maxVal = findMax(myArray, size);
    cout << "Minimum Value: " << minVal << endl;
    cout << "Maximum Value: " << maxVal << endl;
    return 0;
}
