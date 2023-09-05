#include <iostream>
using namespace std;

int linearSearch(const int arr[], int size, int target)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int result = linearSearch(myArray, size, 7);
    cout << "Index of 7: " << result << endl;
    return 0;
}
