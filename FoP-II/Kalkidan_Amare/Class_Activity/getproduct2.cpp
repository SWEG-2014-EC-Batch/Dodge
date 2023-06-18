#include <iostream>
#include "getprod.h"
#include "try.h"

using namespace std;

// function declaration
// double getProduct(int num1, double num2);

int main()
{
    int firstNum;
    double secondNum;
    cout << "enter an integer and then a double number" << endl;
    cin >> firstNum >> secondNum;

    // Function call
    double product = getProduct(firstNum, secondNum);

    cout << "Product: " << product << endl;
    out();

    return 0;
}
