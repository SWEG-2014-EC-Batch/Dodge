#include "string_comparison.h"

int compareStrings(const char* str1, const char* str2) {
  int i = 0;
  
  while (str1[i] == str2[i]) {
    if (str1[i] == '\0')
      return 0;  // Strings are equal
    i++;
  }

  if (str1[i] > str2[i])
    return 1;  // First string is greater
  else
    return -1; // Second string is greater
}
