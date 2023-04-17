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
return 0;
}
