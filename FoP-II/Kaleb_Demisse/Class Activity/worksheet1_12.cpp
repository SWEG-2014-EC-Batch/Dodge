#include <iostream>

using namespace std;

void calcQuotient(double n1, double n2, double& answer);

int main() {
    double num1, num2, quotient;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;
    if (num2==0){
        cout << "Can't divide by zero" <<endl;
        return 0;
    }

    calcQuotient(num1, num2, quotient);

    cout << "The quotient is: "<< quotient << endl;

    return 0;
}
void calcQuotient(double n1, double n2, double& answer) {
    answer = n1 / n2;
}