#include <cmath>
#include <iostream>
using namespace std;

void acceptInput(int &day, int &month, int &year);
void extractDate(int date, int &day, int &month, int &year);
void checkValidity(int date, int day, int month, int year);
bool isLeapYear(int year);
void printOutput(int day, int month, int year);
void nextTwenty(int year, int i = 20);

int main()
{
  int year = 0, month = 0, day = 0;
  acceptInput(day, month, year);
  printOutput(day, month, year);
}

void acceptInput(int &day, int &month, int &year)
{
  int date;
  cout << "Please enter a date (dd mm yyyy): ";
  cin >> date;
  extractDate(date, day, month, year);
}
void extractDate(int date, int &day, int &month, int &year)
{
  for (int i = 0; i < 4; i++)
  {
    year += (date % 10) * pow(10, i);
    date /= 10;
  }

  for (int i = 0; i < 2; i++)
  {
    month += (date % 10) * pow(10, i);
    date /= 10;
  }

  for (int i = 0; i < 2; i++)
  {
    day += (date % 10) * pow(10, i);
    date /= 10;
  }
  checkValidity(date, day, month, year);
}
void checkValidity(int date, int day, int month, int year)
{
  int dayMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (date > 0)
  {
    cout << "\tYou entered an invalid date!" << endl;
    exit(-1);
  }
  if (month < 1 || month > 12)
  {
    cout << "\tInvalid month: " << month << endl;
    exit(-1);
  }
  // special case for february in leap years
  if (isLeapYear(year) && month == 2 && (day > 0 && day < 30))
  {
    return;
  }

  if (day < 1 || day > dayMonth[month - 1])
  {
    cout << "\tInvalid day of month " << day << endl;
    exit(-1);
  }
}
bool isLeapYear(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
void printOutput(int day, int month, int year)
{
  if (isLeapYear(year))
  {
    cout << '\t' << day << "/" << month << "/" << year
         << " is a valid date and also a Leap Year" << endl;
    cout << "Here is below the next twenty Leap years are:\n\t";
    nextTwenty(year);
    cout << endl;
  }
  else
  {
    cout << '\t' << day << "/" << month << "/" << year
         << " is a valid date but not a Leap Year" << endl;
  }
}
void nextTwenty(int year, int i)
{
  if (i == 0)
  {
    return;
  }
  cout << year + 4 << ",";
  nextTwenty(year + 4, i - 1);
}