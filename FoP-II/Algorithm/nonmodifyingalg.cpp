#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 7, 3, 7};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int target = 7;

    int count = std::count(myArray, myArray + size, target);

    cout << "Number of " << target << "s: " << count << endl;

    return 0;
}
