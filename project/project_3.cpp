#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int weather[12][31][3];
  int operation;

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 31; j++) {
      int low = rand() % 60;
      int high = (low + 1) + (rand() % (100 - (low + 1) + 1));
      int avg = (low + high) / 2;
      weather[i][j][0] = low;
      weather[i][j][1] = high;
      weather[i][j][2] = avg;
    }
  }

  cout << "Please choose which operation to perform:\n\t1.Show me the high and "
          "low temperature of a day.\n\t2.Show me the high, low, and average "
          "temperature of a month\n\t";
  cout << "3.Show me the month and day with the highest temperature\n\t4.Show "
          "me the month and day with the lowest temperature\n\t5.Show me all "
          "month's average temperature in a table"
       << endl;

  cin >> operation;
  int day, month;
  switch (operation) {
  case 1: {
  month1:
    cout << "Please enter the month(1 - 12): ";
    cin >> month;
    if (month < 1 || month > 12) {
      cout << "You entered an invalid month" << endl;
      goto month1;
    }
  day1:
    cout << "Please enter the day of the month (1 - 31): ";
    cin >> day;
    if (day < 1 || day > 31) {
      cout << "You entered an invalid day of the month" << endl;
      goto day1;
    }
    cout << "Low: " << weather[month - 1][day - 1][0]
         << ", High: " << weather[month - 1][day - 1][1] << endl;
    break;
  }

  return 0;
}
