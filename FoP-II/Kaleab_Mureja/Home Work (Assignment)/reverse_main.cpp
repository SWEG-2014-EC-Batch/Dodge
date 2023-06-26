#include <iostream>
#include "string_reverse.h"

int main()
{
  char str[] = "Hello, World!";

  // Reverse the string
  reverseString(str);

  // Display the reversed string
  std::cout << "Reversed string: " << str << std::endl;

  return 0;
}
