#include <iostream>
#include <cmath>
using namespace std;

double hypotenuse(double side1, double side2);

int main()
{
    double side1, side2;

    cout << "Enter the length of side 1 and side 2: ";
    cin >> side1 >> side2;

    cout << "Hypotenuse length: " << hypotenuse(side1, side2) << endl;

    return 0;
}

double hypotenuse(double side1, double side2)
{
    return sqrt(pow(side1, 2) + pow(side2, 2));
}
