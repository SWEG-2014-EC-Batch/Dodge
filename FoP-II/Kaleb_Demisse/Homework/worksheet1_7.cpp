#include <iostream>
#include <cstdarg>

// Function to calculate the product of integers
int product(int count, ...);

int main() {
    int numValues;
    std::cout << "Enter the number of values(below or equal to 10): ";
    std::cin >> numValues;

    int values[10];

    std::cout << "Enter the values: ";
    for (int i = 0; i < numValues; i++) {
        std::cin >> values[i];
    }

    int result = product(numValues, values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9]);
    std::cout << "Product: " << result << std::endl;

    return 0;
}

int product(int count, ...) {
    int result = 1;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        result *= num;
    }

    va_end(args);
    return result;
}

