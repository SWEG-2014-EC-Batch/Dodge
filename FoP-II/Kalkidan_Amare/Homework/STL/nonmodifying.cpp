#include <iostream>
using namespace std;

int countOccurrences(const int arr[], int size, int target)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 7, 3, 7};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int count = countOccurrences(myArray, size, 7);
    cout << "Number of 7s: " << count << endl;
    return 0;
}
