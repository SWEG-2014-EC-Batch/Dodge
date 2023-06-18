#include <iostream>
#include "file.h"
#include "headerFile.h"
using namespace std;

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
  display();
}