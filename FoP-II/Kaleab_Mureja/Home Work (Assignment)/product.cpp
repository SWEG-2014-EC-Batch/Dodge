#include <iostream>
#include <cstdarg>

using namespace std;

int product(int count, ...);

int main()
{
  int result1 = product(3, 2, 3, 4);
  cout << "The product of 2, 3, and 4 is: " << result1 << endl;
  int result2 = product(4, 5, 6, 7, 8);
  cout << "The product of 5, 6, 7, and 8 is: " << result2 << endl;
  int result3 = product(2, 10, 20);
  cout << "The product of 10 and 20 is: " << result3 << endl;
  0;
}
int product(int count, ...)
{
  int result = 1;
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++)
  {
    int num = va_arg(args, int);
    result *= num;
  }
  va_end(args);
  return result;
}