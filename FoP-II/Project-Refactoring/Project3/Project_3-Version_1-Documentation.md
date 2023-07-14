## Weather Data Analysis Documentation

This documentation provides an overview of the refactored code for weather data analysis. The code allows users to perform various operations on a simulated weather dataset, including retrieving temperature information for specific days or months, finding the highest and lowest temperatures, and displaying average temperatures for each month.

### Functions

1. `acceptMonth()`

   - Input: None
   - Output: Integer (valid month value)
   - Description: Prompts the user to enter a month value (1 - 12) and validates the input. Recursively prompts the user until a valid month value is entered.

2. `acceptDay()`

   - Input: None
   - Output: Integer (valid day value)
   - Description: Prompts the user to enter a day value (1 - 31) and validates the input. Recursively prompts the user until a valid day value is entered.

3. `generateWeather(int weather[12][31][3], int month = 0, int day = 0)`

   - Input: `weather` - 3D array to store weather data, `month` - current month (default: 0), `day` - current day (default: 0)
   - Output: None
   - Description: Generates weather data for each day of the year. Initializes the `weather` array with random low, high, and average temperatures for each day. Uses recursion to iterate over all months and days.

4. `displayDayTemperature(const int weather[12][31][3])`

   - Input: `weather` - 3D array containing weather data
   - Output: None
   - Description: Prompts the user for a specific month and day and displays the low and high temperatures for that day using the `weather` array.

5. `displayMonthTemperature(const int weather[12][31][3])`

   - Input: `weather` - 3D array containing weather data
   - Output: None
   - Description: Prompts the user for a specific month and displays the low, high, and average temperatures for that month using the `weather` array.

6. `displayHighestTemperature(const int weather[12][31][3], int month = 0, int day = 0, int highestDay = 0, int highestMonth = 0, int high = INT_MIN)`

   - Input: `weather` - 3D array containing weather data, `month` - current month (default: 0), `day` - current day (default: 0), `highestDay` - day with the highest temperature (default: 0), `highestMonth` - month with the highest temperature (default: 0), `high` - highest temperature (default: INT_MIN)
   - Output: None
   - Description: Finds and displays the day with the highest temperature across all months. Uses recursion to iterate over the `weather` array, comparing temperatures and keeping track of the day and month with the highest temperature.

7. `displayLowestTemperature(const int weather[12][31][3], int month = 0, int day = 0, int lowestDay = 0, int lowestMonth = 0, int low = INT_MAX)`

   - Input: `weather` - 3D array containing weather data, `month` - current month (default: 0), `day` - current day (default: 0), `lowestDay` - day with the lowest temperature (default: 0), `lowestMonth` - month with the lowest temperature (default: 0), `low` - lowest temperature (default: INT_MAX)
   - Output: None
   - Description: Finds and displays the day with the lowest temperature across all months. Uses recursion to iterate over the `weather` array, comparing temperatures and keeping track of the day and month with the lowest temperature.

8. `displayMonthlyAverageTemperature(const int weather[12][31][3], int month = 0, int day = 0, int avg = 0)`
   - Input: `weather` - 3D array containing weather data, `month` - current month (default: 0), `day` - current day (default: 0), `avg` - accumulated average temperature (default: 0)
   - Output: None
   - Description: Displays a table of average temperatures for each month. Uses recursion to iterate over the `weather` array, calculates the average temperature for each month, and prints it in a formatted table.

### Main Function

The main function initializes the `weather` array using the `generateWeather()` function. It prompts the user to choose an operation and performs the corresponding action by invoking the appropriate function based on the user's choice. The available operations include retrieving temperature information for a specific day or month, finding the highest and lowest temperatures, and displaying average temperatures for each month.

### Improvements

1. Modular Design: The code has been refactored into separate functions, making it more modular and easier to understand. Each function has a specific purpose and can be modified independently.

2. Input Validation: The refactored code includes input validation for month and day inputs. The `acceptMonth()` and `acceptDay()` functions ensure that valid values are entered by the user.

3. Recursion and Iteration: Recursive function calls and loops have been used to replace the use of `goto` statements. This improves code readability and maintainability.

4. Improved Readability: Variable names have been made more descriptive, and the code has been formatted and indented consistently for improved readability.

By refactoring the code, it has become more organized, modular, and easier to maintain. The functions have clear responsibilities, and the main code structure is cleaner and easier to follow.
