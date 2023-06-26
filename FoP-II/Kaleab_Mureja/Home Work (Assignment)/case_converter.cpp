#include "case_converter.h"

void convertToLowercase(char* str) {
    if (str == nullptr) {
        return;
    }
    
    int index = 0;
    while (str[index] != '\0') {
        if (str[index] >= 'A' && str[index] <= 'Z') {
            str[index] += 32;  // Convert uppercase to lowercase by adding 32
        }
        index++;
    }
}

void convertToUppercase(char* str) {
    if (str == nullptr) {
        return;
    }
    
    int index = 0;
    while (str[index] != '\0') {
        if (str[index] >= 'a' && str[index] <= 'z') {
            str[index] -= 32;  // Convert lowercase to uppercase by subtracting 32
        }
        index++;
    }
}
