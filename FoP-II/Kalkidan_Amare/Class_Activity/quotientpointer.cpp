#include <iostream>

void calcQuotient(double n1, double n2, double *answer);

int main()
{
    double num1, num2, quotient;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    calcQuotient(num1, num2, &quotient);

    std::cout << "The quotient is: " << quotient << std::endl;

    return 0;
}

void calcQuotient(double n1, double n2, double *answer)
{
    *answer = n1 / n2;
}
