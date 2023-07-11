#include <iostream>
#include <assert.h>

using namespace std;

void input(double& scale_factor, double& value1, double& value2);
void scale(double scale_factor, double& value1, double& value2);
void output(double value1, double value2);

int main() {
    double scale_factor;
    double value1;
    double value2;

    input(scale_factor, value1, value2);
    scale(scale_factor, value1, value2);
    output(value1, value2);

    return 0;
}

void input(double& scale_factor, double& value1, double& value2) {

    cout << "Enter the scale factor: ";
    cin >> scale_factor;

    cout << "Enter the first value: ";
    cin >> value1;

    cout << "Enter the second value: ";
    cin >> value2;
}

void scale(double scale_factor, double& value1, double& value2) {

    assert(scale_factor != 0);

    cout << "The values before scaling: " << endl;
    cout << "value1 = " << value1 << endl;
    cout << "value2 = " << value2 << endl;

    value1 *= scale_factor;
    value2 *= scale_factor;
}

void output(double value1, double value2) {
    cout << "The values after scaling: " << endl;
    cout << "value1 = " << value1 << endl;
    cout << "value2 = " << value2 << endl;
}
