#include <iostream>
#include "case_converter.h"

int main() {
    char str[100];
    std::cout << "Enter a string: ";
    std::cin.getline(str, 100);

    convertToLowercase(str);
    std::cout << "Lowercase: " << str << std::endl;

    convertToUppercase(str);
    std::cout << "Uppercase: " << str << std::endl;

    return 0;
}