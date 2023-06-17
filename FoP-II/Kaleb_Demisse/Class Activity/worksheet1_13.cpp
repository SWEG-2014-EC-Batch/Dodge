#include <iostream>

using namespace std;

double max(double a, double b);
double max(double a, double b, double c);

int main() {
    double num1, num2, num3;
    
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;
    
    cout << "Enter the third number: ";
    cin >> num3;
    
    cout << "The maximum of " << num1 << " and " << num2 << " is: " << max(num1, num2)<< endl;
    
    cout << "The maximum of " << num1 << ", " << num2 << " and " << num3 << " is: " << max(num1, num2, num3) << endl;
    
    return 0;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

double max(double a, double b, double c) {
    return max(max(a, b), c);
}