#include <iostream>
#include <cmath>
using namespace std;

double calculateExpression(double num1, double num2);

int main()
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Answer: " << calculateExpression(num1, num2) << endl;

    return 0;
}

double calculateExpression(double num1, double num2)
{
    return pow(num1, 3) + sqrt(num2);
}
