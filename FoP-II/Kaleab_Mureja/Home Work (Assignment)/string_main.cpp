#include <iostream>
#include "string_functions.h"

int main() {
  const char* str = "Hello, World!";
  
  int length = stringLength(str);
  int vowelCount = countVowels(str);
  int consonantCount = countConsonants(str);
  
  std::cout << "Length of the string: " << length << std::endl;
  std::cout << "Number of vowels: " << vowelCount << std::endl;
  std::cout << "Number of consonants: " << consonantCount << std::endl;
  
  return 0;
}
