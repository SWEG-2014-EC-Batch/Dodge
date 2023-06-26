#include <iostream>
using namespace std;

int addFirstAndLastElement(int firstElement, int lastElement);

int main()
{
  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  if (size == 0)
  {
    cout << "Error: Empty array." << endl;
    return 0; // Return a default value or handle the error case as needed.
  }

  int firstElement = numbers[0];
  int lastElement = numbers[size - 1];

  int result = addFirstAndLastElement(firstElement, lastElement);
  cout << "Sum: " << result << endl;

  return 0;
}

int addFirstAndLastElement(int firstElement, int lastElement)
{
  int sum = firstElement + lastElement;
  return sum;
}