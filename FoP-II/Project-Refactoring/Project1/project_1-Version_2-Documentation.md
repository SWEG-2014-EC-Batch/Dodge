### Updated Leap Year Functions

1. `acceptInput(dates& check)`

   - Input: `check` - Reference to a `dates` struct to store the input date
   - Output: None
   - Description: Prompts the user to enter a date in the format (dd mm yyyy) and calls `extractDate` to extract the day, month, and year.

2. `extractDate(int date, dates& check)`

   - Input: `date` - Input date as an integer, `check` - Reference to a `dates` struct to store the extracted date components
   - Output: None
   - Description: Extracts the day, month, and year from the input date integer by performing modulo and division operations. Calls `checkValidity` to validate the extracted date.

3. `checkValidity(int date, dates check)`

   - Input: `date` - Input date as an integer, `check` - `dates` struct containing the extracted date components
   - Output: None
   - Description: Checks the validity of the extracted date by validating the day, month, and year. Prints error messages and exits the program if the date is invalid.

4. `printOutput(dates check)`

   - Input: `check` - `dates` struct containing the extracted date components
   - Output: None
   - Description: Prints the validity of the input date and whether it is a leap year. Calls `nextTwenty` to print the next twenty leap years if the input date is a leap year.

5. `nextTwenty(int year, int i = 20)`

   - Input: `year` - Starting year, `i` - Number of leap years to print (default: 20)
   - Output: None
   - Description: Recursively prints the next `i` leap years starting from the given `year`.

6. `saveCheckedDate(const dates& check)`
   - Input: `check` - `dates` struct containing the extracted date components
   - Output: None
   - Description: Saves the checked date (dd/mm/yyyy format) to a file named "checked_dates.txt" by appending it to the existing file.

### File Handling

1. `saveCheckedDate` function was added to enable saving the checked date to a file named "checked_dates.txt". The date is appended to the file in the format dd/mm/yyyy.

These updates enhance the code by adding file handling capabilities to save the checked dates for future reference. The existing functions have been modified to use the `dates` struct and to update variable names for improved clarity and readability.
