#include <iostream>
#include "string_functions.h"

int stringLength(const char *str)
{
  int length = 0;
  while (str[length] != '\0')
  {
    length++;
  }
  return length;
}

int countVowels(const char *str)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    char ch = tolower(str[i]);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      count++;
    }
  }
  return count;
}

int countConsonants(const char *str)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    char ch = tolower(str[i]);
    if ((ch >= 'a' && ch <= 'z') && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
    {
      count++;
    }
  }
  return count;
}
what