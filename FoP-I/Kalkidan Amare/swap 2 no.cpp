// swap 2 numbers with out using 3rd variable

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "eenter 2 no ";
    cin >> x >> y;
    x = x + y;
    y = x - y;
    x = x - y;
    cout << x << endl;
    cout << y;
}
