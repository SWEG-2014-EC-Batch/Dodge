#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int myArray[] = {2, 4, 1, 6, 7, 9, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    int minVal = *min_element(myArray, myArray + size);
    int maxVal = *max_element(myArray, myArray + size);

    cout << "Minimum Value: " << minVal << endl;
    cout << "Maximum Value: " << maxVal << endl;

    return 0;
}
