#include <iostream>
#include <array>
using namespace std;
int main()
{
    char testans = {'a', 'b', 'c', 'b', 'a'};
    // string test[5] = {};
    char ans;
    int result = 0;
    cout << "enter ur answer: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> ans;
        if (testans[i] == ans)
        {
            result++;
        }
    }
    cout << "your result is: " << result << endl;
}
