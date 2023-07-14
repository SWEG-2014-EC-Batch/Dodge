=====================================
Code Refactoring Documentation
=====================================

Refactored Code:
----------------
Project_2.cpp

Introduction:
--------------
This documentation explains the refactoring performed on the given code, which involved splitting the code into functions, improving variable names, and enhancing code readability.

Refactoring Steps:
------------------
1. Introduced separate functions to improve code organization and readability:
   - `acceptInput`: Prompts the user to input a positive number and returns it.
   - `countDigits`: Calculates the number of digits in the input number.
   - `printRow`: Prints each row of the pattern based on the input number, row index, and column index.
   - `printPattern`: Prints the entire pattern by calling `printRow` for each row.

2. Improved variable names:
   - Renamed `n` to `input` in the `main` function to provide a clearer indication of its purpose.
   - Renamed `i` and `j` in the nested loops to `row` and `column`, respectively, in the `printRow` and `printPattern` functions to enhance readability.

3. Used the `<iomanip>` library to format the output and align numbers correctly.

Usage Instructions:
-------------------
1. Compile and run the refactored code.
2. When prompted, enter a positive integer.
3. The program will print a pattern based on the input number.

Example Output:
---------------
Enter a positive number: 2
0       0
1 0   0 1
2 1 0 1 2
1 0   0 1
0       0

Explanation:
------------
In this example, the user enters the number 2. The program prints a pattern consisting of numbers up to 2. The numbers are aligned and indented appropriately to form a butterfly shape.

The refactored code provides improved code structure, readability, and maintainability, making it easier to understand and modify.

=====================================
