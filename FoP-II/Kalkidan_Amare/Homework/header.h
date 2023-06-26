#ifndef HEADER
#define HEADER

#include <iostream>
using namespace std;

void lenvowcon(string &str, int &length, int &vowel, int &consonant)
{
    length = 0;
    vowel = 0;
    consonant = 0;

    for (char &ch : str)
    {
        length++;

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowel++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            consonant++;
        }
    }
}

string reverse(string &str, int length)
{
    string rev;
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        rev += str[i];
    }
    return rev;
}

int compare(string &str1, string &str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else if (str1[i] == '\0')
        return -1;
    else
        return 1;
}

string tolower(string &str)
{
    for (char &ch : str)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
        }
    }
    return str;
}

string toupper(string &str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    return str;
}

#endif