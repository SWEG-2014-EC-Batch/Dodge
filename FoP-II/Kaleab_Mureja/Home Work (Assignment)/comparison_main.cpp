#include <iostream>
#include "string_comparison.h"

int main() {
  const char* str1 = "Hello";
  const char* str2 = "World";

  int result = compareStrings(str1, str2);

  std::cout << "Comparison result: " << result << std::endl;

  return 0;
}
