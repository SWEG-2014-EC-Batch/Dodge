#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int date, day, month, year;
  int dayMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  cout << "Please enter a date (dd mm yyyy): ";
  cin >> date;

  // extract out the year
  for (int i = 0; i < 4; i++) {
    year += (date % 10) * pow(10, i);
    date /= 10;
  }

    // extract out the month
  for (int i = 0; i < 2; i++) {
    month += (date % 10) * pow(10, i);
    date /= 10;
  }

  // extract out the day
  for (int i = 0; i < 2; i++) {
    day += (date % 10) * pow(10, i);
    date /= 10;
  }
   if (date > 0) {
    cout << "\tYou entered an invalid date!" << endl;
    return -1;
  }

  if (month < 1 || month > 12) {
    cout << "\tInvalid month: " << month << endl;
    return -1;
  }
  // check if year is a leap year
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    // special case for february in leap years
    if (day < 1 || month == 2 && day > 29) {
      cout << "\tInvalid day of month " << day << endl;
      return -1;
    }
     if (month != 2 && day > dayMonth[month - 1]) {
      cout << "\tInvalid day of month " << day << endl;
      return -1;
    }

    cout << '\t' << day << "/" << month << "/" << year
         << " is a valid date and also a Leap Year" << endl;
    cout << "Here is below the next twenty Leap years are:\n\t";
    for (int i = 0; i < 19; i++) {
      year += 4;
      cout << year << ",";
    }
    cout << year << endl;
  } else {
    if (day > dayMonth[month - 1]) {
      cout << "\tInvalid day of month " << day << endl;
    }
    cout << '\t' << day << "/" << month << "/" << year
         << " is a valid date but not a Leap Year" << endl;
  }

return 0;
}
