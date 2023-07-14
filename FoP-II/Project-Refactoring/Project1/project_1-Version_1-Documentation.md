=====================================
Code Refactoring Documentation
=====================================

Refactored Code:
----------------
Project_1.cpp

Introduction:
--------------
This documentation explains the refactoring performed on the given code, which involved improving code structure, readability, and maintainability by splitting the code into functions and enhancing error handling.

Refactoring Steps:
------------------
1. Introduced separate functions to improve code organization and readability:
   - `acceptInput`: Prompts the user to input a date and calls `extractDate` with the entered date.
   - `extractDate`: Extracts the day, month, and year from the input date.
   - `checkValidity`: Validates the date, checking for invalid input or an out-of-range date.
   - `isLeapYear`: Determines if a year is a leap year.
   - `printOutput`: Prints the output based on the validity of the entered date and whether it is a leap year.
   - `nextTwenty`: Prints the next twenty leap years.

2. Improved error handling:
   - The `checkValidity` function handles error conditions such as an invalid date or month, terminating the program if an error is encountered.

Usage Instructions:
-------------------
1. Compile and run the refactored code.
2. When prompted, enter a date in the format "dd mm yyyy" and press Enter.
3. The program will validate the date and output whether it is a valid date and if it is also a leap year.
4. If the entered date is valid and a leap year, the program will additionally print the next twenty leap years.

Example Output:
---------------
Please enter a date (dd mm yyyy): 29 02 2024
        29/02/2024 is a valid date and also a Leap Year
Here are the next twenty Leap years:
        2028,2032,2036,2040,2044,2048,2052,2056,2060,2064,2068,2072,2076,2080,2084,2088,2092,2096,2100,2104

Explanation:
------------
In this example, the user enters the date "29 02 2024". The program validates that it is a valid date and a leap year since February 29, 2024, is a valid date in a leap year. The program then prints the next twenty leap years starting from 2028.

The refactored code provides improved code organization, error handling, and readability, making it easier to understand and maintain.

=====================================
