#include <iostream>
#include <cassert>
using namespace std;

void scale(double scale1, double &val1, double &val2)
{
    assert(scale1 != 0.0);

    cout << "Before scaling: value1 = " << val1 << ", value2 = " << val2 << endl;

    val1 *= scale1;
    val2 *= scale1;

    std::cout << "After scaling: value1 = " << val1 << ", value2 = " << val2 << endl;
}

int main()
{
    double scale1;
    double val1, val2;

    cout << "Enter the scale factor: ";
    cin >> scale1;
    cout << "Enter the values to scale: ";
    cin >> val1 >> val2;

    scale(scale1, val1, val2);

    return 0;
}
