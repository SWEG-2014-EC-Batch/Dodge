#include <iostream>
using namespace std;

void calcQuotient(double n1, double &n2, double &answer);

int main()
{
    double num1, num2, quotient;

    cout << "Enter the first number and the second number: ";
    cin >> num1 >> num2;

    calcQuotient(num1, num2, quotient);

    cout << "The quotient is: " << quotient << endl;

    return 0;
}

void calcQuotient(double n1, double &n2, double &answer)
{
    answer = n1 / n2;
}
