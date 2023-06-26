#include <iostream>
using namespace std;

void calcQuotient(double n1, double n2, double &answer);

int main()
{
  double num1, num2, quotient;

  cout << "Enter num1: ";
  cin >> num1;

  cout << "Enter num2: ";
  cin >> num2;

  calcQuotient(num1, num2, quotient);
    cout << "Quotient: " << quotient<< endl;


  return 0;
}

void calcQuotient(double n1, double n2, double &answer)
{

  if (n2 != 0)
  {
    answer = n1 / n2;
    cout << "Quotient: " << answer << endl;

  }
  else
  {
    cout << "Error: Division by zero!" << endl;
  }
}