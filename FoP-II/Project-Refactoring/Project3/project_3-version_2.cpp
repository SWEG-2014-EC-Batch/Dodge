#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

struct Weather {
    int low;
    int high;
    int avg;
};

int acceptMonth();
int acceptDay();
void generateWeather(Weather weathers[12][31], int month = 0, int day = 0);
void displayDayTemperature(const Weather weathers[12][31]);
void displayMonthTemperature(const Weather weathers[12][31]);
void displayHighestTemperature(const Weather weathers[12][31], int month = 0, int day = 0,
                               int highestDay = 0, int highestMonth = 0, int high = INT_MIN);
void displayLowestTemperature(const Weather weathers[12][31], int month = 0, int day = 0,
                              int lowestDay = 0, int lowestMonth = 0, int low = INT_MAX);
void displayMonthlyAverageTemperature(const Weather weathers[12][31], int month = 0, int day = 0,
                                      int avg = 0);
void saveWeather(const Weather weathers[12][31]);
void editWeather(Weather weathers[12][31], int month, int day);
void loadWeather(Weather weathers[12][31]);

int main() {
    Weather weathers[12][31];
    int operation;
    loadWeather(weathers);

    cout << "Please choose which operation to perform:\n"
         << "\t1. Show me the high and low temperature of a day.\n"
         << "\t2. Show me the high, low, and average temperature of a month.\n"
         << "\t3. Show me the month and day with the highest temperature.\n"
         << "\t4. Show me the month and day with the lowest temperature.\n"
         << "\t5. Show me all month's average temperature in a table.\n"
         << "\t6. Edit weather data of a specific day." << endl;

    cin >> operation;

    switch (operation) {
        case 1:
            displayDayTemperature(weathers);
            break;
        case 2:
            displayMonthTemperature(weathers);
            break;
        case 3:
            displayHighestTemperature(weathers);
            break;
        case 4:
            displayLowestTemperature(weathers);
            break;
        case 5:
            cout << left << setw(10) << "Month" << left << setw(5) << "Average Temperature" << left << endl;
            displayMonthlyAverageTemperature(weathers);
            break;
        case 6:
            {
                int month = acceptMonth();
                int day = acceptDay();
                editWeather(weathers, month - 1, day - 1);
                saveWeather(weathers);
            }
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

void generateWeather(Weather weathers[12][31], int month, int day) {
    if (month == 11 && day == 31) {
        return;
    }

    int low = rand() % 60;
    int high = (low + 1) + (rand() % (100 - (low + 1) + 1));
    int avg = (low + high) / 2;

    weathers[month][day].low = low;
    weathers[month][day].high = high;
    weathers[month][day].avg = avg;

    if (day == 30 && month < 11) {
        day = -1;
        month += 1;
    }
    generateWeather(weathers, month, day + 1);
}

void displayDayTemperature(const Weather weathers[12][31]) {
    int month = acceptMonth();
    int day = acceptDay();

    cout << "Low: " << weathers[month - 1][day - 1].low
         << ", High: " << weathers[month - 1][day - 1].high << endl;
}

void displayMonthTemperature(const Weather weathers[12][31]) {
    int month = acceptMonth();

    int low = INT_MAX, high = INT_MIN, avg = 0;

    for (int j = 0; j < 31; j++) {
        if (weathers[month - 1][j].low < low) {
            low = weathers[month - 1][j].low;
        }
        if (weathers[month - 1][j].high > high) {
            high = weathers[month - 1][j].high;
        }
        avg += weathers[month - 1][j].avg;
    }

    avg /= 31;

    cout << "Low: " << low << ", High: " << high << ", Average: " << avg << endl;
}

void displayHighestTemperature(const Weather weathers[12][31], int month, int day,
                               int highestDay, int highestMonth, int high) {
    if (month == 11 && day == 31) {
        cout << "The day with the highest temperature is, Day: " << highestDay + 1
             << ", Month: " << highestMonth + 1 << ". It had a high temperature of " << high << endl;
        return;
    }

    if (weathers[month][day].high > high) {
        high = weathers[month][day].high;
        highestDay = day;
        highestMonth = month;
    }
    if (day == 30 && month < 11) {
        day = -1;
        month += 1;
    }
    displayHighestTemperature(weathers, month, day + 1, highestDay, highestMonth, high);
}

void displayLowestTemperature(const Weather weathers[12][31], int month, int day,
                              int lowestDay, int lowestMonth, int low) {
    if (month == 11 && day == 31) {
        cout << "The day with the lowest temperature is, Day: " << lowestDay + 1
             << ", Month: " << lowestMonth + 1 << ". It had a low temperature of " << low << endl;
        return;
    }

    if (weathers[month][day].low < low) {
        low = weathers[month][day].low;
        lowestDay = day;
        lowestMonth = month;
    }
    if (day == 30 && month < 11) {
        day = -1;
        month += 1;
    }

    displayLowestTemperature(weathers, month, day + 1, lowestDay, lowestMonth, low);
}

void displayMonthlyAverageTemperature(const Weather weathers[12][31], int month, int day, int avg) {
    if (month == 11 && day == 31) {
        return;
    }
    avg += weathers[month][day].avg;
    if (day == 30) {
        avg /= 31;
        cout << left << setw(10) << month + 1 << left << setw(5) << avg << endl;
        avg = 0;
    }

    if (day == 30 && month < 11) {
        day = -1;
        month += 1;
    }
    displayMonthlyAverageTemperature(weathers, month, day + 1, avg);
}

void editWeather(Weather weathers[12][31], int month, int day) {
    int low, high;
    cout << "Enter the low temperature for Day " << day + 1 << ", Month " << month + 1 << ": ";
    cin >> low;
    cout << "Enter the high temperature for Day " << day + 1 << ", Month " << month + 1 << ": ";
    cin >> high;

    weathers[month][day].low = low;
    weathers[month][day].high = high;
    weathers[month][day].avg = (low + high) / 2;

    cout << "Weather for Day " << day + 1 << ", Month " << month + 1 << " updated successfully." << endl;
}
void saveWeather(const Weather weathers[12][31]) {
    ofstream outputFile("weather_data.txt");
    if (!outputFile) {
        cout << "Failed to open the file" << endl;
        return;
    }

    outputFile << "Month\tDay\t\tLow\t\tHigh\tAverage\n";
    for (int month = 0; month < 12; month++) {
        for (int day = 0; day < 31; day++) {
            outputFile << month + 1 << "\t\t" << day + 1 << "\t\t"
                       << weathers[month][day].low << "\t\t"
                       << weathers[month][day].high << "\t\t"
                       << weathers[month][day].avg << "\n";
        }
    }

    outputFile.close();
    cout << "Weather saved to 'weather_data.txt' file." << endl;
}

void loadWeather(Weather weathers[12][31]) {
    ifstream inputFile("weather_data.txt");
    if (!inputFile || inputFile.peek() == ifstream::traits_type::eof()) {
        cout << "Failed to open the file. Generating new Weather file." << endl;
        generateWeather(weathers);
        saveWeather(weathers);
        return;
    }

    string line;
    getline(inputFile, line);

    int month, day, low, high, avg;
    while (inputFile >> month >> day >> low >> high >> avg) {
        weathers[month - 1][day - 1].low = low;
        weathers[month - 1][day - 1].high = high;
        weathers[month - 1][day - 1].avg = avg;
    }

    inputFile.close();
    cout << "Weather loaded from 'weather_data.txt' file." << endl;
}

