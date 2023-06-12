#include <iostream>
using namespace std;

double getProduct(int num1, double num2);
int main()
{
  int firstNum;
  double secondNum;
  cout << "Enter the first number: ";
  cin >> firstNum;
  cout << "Enter the second number: ";
  cin >> secondNum;
  double product = getProduct(firstNum, secondNum);
  cout << "Product: " << product << endl;
}
double getProduct(int num1, double num2)
{
  double result = num1 * num2;
  return result;
}