#include <iostream>
using namespace std;

int sumNumDigit(int x);

int main()
{
  int num;
  cout << "Enter any number: ";
  cin >> num;
  cout<< "Result: " << sumNumDigit(num);
}

int sumNumDigit(int num)
{
  if (num <= 0)
  {
    return 0;
  }
  else
  {
    return (num % 10) + (sumNumDigit(num / 10));
  }
}