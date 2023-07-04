#include <iostream>
using namespace std;

int factorial(int n);
int main()
{
  int n;
  cout << "Enter any positive number and i'll tell you there factorial result: " ;
  cin >> n;
  int result = factorial(n);
  cout << "Result: " << result << endl;
  return 0;
}
int factorial(int n)
{
    if (n > 1)
  {
    int total = n * factorial(n - 1);
    return total;
  }
  else
  {
   return 1;
  }
}
