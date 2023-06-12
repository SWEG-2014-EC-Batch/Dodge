#include <iostream>
#include <cstdarg>
using namespace std;

int product(int count, ...);

int main()
{
    int product1 = product(2, 5, 4);
    cout << "Product 1: " << product1 << endl;

    int product2 = product(4, 1, 3, 6, 5);
    cout << "Product 2: " << product2 << endl;

    return 0;
}

int product(int count, ...)
{
    int result = 1;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i)
    {
        result *= va_arg(args, int);
    }

    va_end(args);

    return result;
}
