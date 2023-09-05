#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int acceptMonth();
int acceptDay();
void generateWeather(int weather[12][31][3], int month = 0, int day = 0);
void displayDayTemperature(const int weather[12][31][3]);
void displayMonthTemperature(const int weather[12][31][3]);
void displayHighestTemperature(const int weather[12][31][3], int month = 0, int day = 0,
                               int highestDay = 0, int highestMonth = 0, int high = INT_MIN);
void displayLowestTemperature(const int weather[12][31][3], int month = 0, int day = 0,
                              int lowestDay = 0, int lowestMonth = 0, int low = INT_MAX);
void displayMonthlyAverageTemperature(const int weather[12][31][3], int month = 0, int day = 0,
                                      int avg = 0);

int main() {
    int weather[12][31][3];
    int operation;
    generateWeather(weather);

    cout << "Please choose which operation to perform:\n"
         << "\t1. Show me the high and low temperature of a day.\n"
         << "\t2. Show me the high, low, and average temperature of a month.\n"
         << "\t3. Show me the month and day with the highest temperature.\n"
         << "\t4. Show me the month and day with the lowest temperature.\n"
         << "\t5. Show me all month's average temperature in a table." << endl;

    cin >> operation;

    switch (operation) {
        case 1:
            displayDayTemperature(weather);
            break;
        case 2:
            displayMonthTemperature(weather);
            break;
        case 3:
            displayHighestTemperature(weather);
            break;
        case 4:
            displayLowestTemperature(weather);
            break;
        case 5:
            cout << left << setw(10) << "Month" << left << setw(5)<< "Average Temperature" << left << endl;
            displayMonthlyAverageTemperature(weather);
            break;
        default:
            cout << "You chose an invalid option! Exiting the program" << endl;
            return -1;
    }

    return 0;
}
int acceptMonth() {
    int month;
    cout << "Please enter the month (1 - 12): ";
    cin >> month;
    if (month < 1 || month > 12) {
        cout << "Invalid month entered!" << endl;
        return acceptMonth();
    }
    return month;
}

int acceptDay() {
    int day;
    cout << "Please enter the day of the month (1 - 31): ";
    cin >> day;
    if (day < 1 || day > 31) {
        cout << "Invalid day entered!" << endl;
        return acceptDay();
    }
    return day;
}

void generateWeather(int weather[12][31][3], int month, int day) {
    if (month == 11 && day == 31) {
        return;
    }

    int low = rand() % 60;
    int high = (low + 1) + (rand() % (100 - (low + 1) + 1));
    int avg = (low + high) / 2;

    weather[month][day][0] = low;
    weather[month][day][1] = high;
    weather[month][day][2] = avg;

    if (day == 30 && month <11) {
        day = -1;
        month += 1;
    }
    generateWeather(weather, month, day+1);
}

void displayDayTemperature(const int weather[12][31][3]) {
    int month = acceptMonth();
    int day = acceptDay();

    cout << "Low: " << weather[month - 1][day - 1][0]
         << ", High: " << weather[month - 1][day - 1][1] << endl;
}

void displayMonthTemperature(const int weather[12][31][3]) {
    int month = acceptMonth();

    int low = INT_MAX, high = INT_MIN, avg = 0;

    for (int j = 0; j < 31; j++) {
        if (weather[month - 1][j][0] < low) {
            low = weather[month - 1][j][0];
        }
        if (weather[month - 1][j][1] > high) {
            high = weather[month - 1][j][1];
        }
        avg += weather[month - 1][j][2];
    }

    avg /= 31;

    cout << "Low: " << low << ", High: " << high << ", Average: " << avg << endl;
}

void displayHighestTemperature(const int weather[12][31][3], int month, int day,
                               int highestDay, int highestMonth, int high) {
    if (month == 11 && day == 31) {
        cout << "The day with the highest temperature is, Day: " << highestDay + 1
             << ", Month: " << highestMonth + 1 << ". It had a high temperature of " << high << endl;
        return;
    }

    if (weather[month][day][1] > high) {
        high = weather[month][day][1];
        highestDay = day;
        highestMonth = month;
    }
    if (day == 30 && month <11) {
        day = -1;
        month += 1;
    }
    displayHighestTemperature(weather, month, day + 1, highestDay, highestMonth, high);
}

void displayLowestTemperature(const int weather[12][31][3], int month, int day,
                              int lowestDay, int lowestMonth, int low) {
    if (month == 11 && day == 31) {
        cout << "The day with the lowest temperature is, Day: " << lowestDay + 1
             << ", Month: " << lowestMonth + 1 << ". It had a low temperature of " << low << endl;
        return;
    }

    if (weather[month][day][0] < low) {
        low = weather[month][day][0];
        lowestDay = day;
        lowestMonth = month;
    }
    if (day == 30 && month <11) {
        day = -1;
        month += 1;
    }

    displayLowestTemperature(weather, month, day + 1, lowestDay, lowestMonth, low);
}

void displayMonthlyAverageTemperature(const int weather[12][31][3], int month, int day, int avg) {
    if (month == 11 && day == 31){
        return;
    }
    avg += weather[month][day][2];
    if (day == 30) {
        avg /= 31;
        cout << left << setw(10) << month + 1 << left << setw(5) << avg << endl;
        avg=0;
        
    }

    if (day == 30 && month <11) {
        day = -1;
        month += 1;
    }
    displayMonthlyAverageTemperature(weather, month, day + 1, avg);
}
