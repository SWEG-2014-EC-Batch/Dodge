#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int *begin = myArray;
    int *end = myArray + sizeof(myArray) / sizeof(myArray[0]);
    int target = 7;

    int *result = find(begin, end, target);

    if (result != end)
    {
        // Calculate the index
        int index = distance(begin, result);
        cout << "Index of " << target << ": " << index << endl;
    }
    else
    {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
