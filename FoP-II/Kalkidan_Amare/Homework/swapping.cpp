#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void print(int &a, int &b, int &c)
{
    cout << "before swapping:\na= " << a << "\tb= " << b << "\tc= " << c << endl;

    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (b < c)
        swap(b, c);

    cout << "after swapping:\na= " << a << "\tb= " << b << "\tc= " << c << endl;
}
int main()
{
    int a, b, c;
    cout << "enter 3 integers ";
    cin >> a >> b >> c;
    print(a, b, c);
}