#include <iostream>
#include <cassert>
using namespace std;

void scale(double scaleFactor, double& value1, double& value2); 

int main() {
    double value1 = 10.5;
    double value2 = 7.2;
    double scaleFactor = 2.0;

    scale(scaleFactor, value1, value2);

    return 0;
}

void scale(double scaleFactor, double& value1, double& value2) {
    assert(scaleFactor != 0); // Precondition: Scale factor should not be zero

    cout << "Before scaling: ";
    cout << "Value 1 = " << value1 << ", Value 2 = " << value2 << endl;

    value1 *= scaleFactor;
    value2 *= scaleFactor;

    cout << "After scaling: ";
    cout << "Value 1 = " << value1 << ", Value 2 = " << value2 << endl;
}