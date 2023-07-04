#include <iostream>
using namespace std;

double calc(double, double, double, double &, double &);

int main()
{
  double num1, num2, num3, sum, product;
  cout << "Enter num1,num2 and num3 respectively: ";
  cin >> num1 >> num2 >> num3;
  calc(num1, num2, num3, sum, product);
  cout << endl
       << "The sum of the number : " << sum << endl;
  cout << "The product of the number: " << product << endl;
  return 0;
}

double calc(double num1, double num2, double num3, double &total, double &product)
{
  total = num1 + num2 + num3;
  product = num1 * num2 * num3;
  return 0;
}