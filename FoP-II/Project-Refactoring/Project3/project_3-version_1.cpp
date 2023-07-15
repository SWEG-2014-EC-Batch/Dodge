#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

struct dates {
    int day;
    int month;
    int year;
};

void acceptInput(dates& check);
void extractDate(int date, dates& check);
void checkValidity(int date, dates check);
bool isLeapYear(int year);
void printOutput(dates check);
void nextTwenty(int year, int i = 20);
void saveCheckedDate(const dates& check);

int main() {
    dates check = {0, 0, 0};
    acceptInput(check);
    printOutput(check);
    saveCheckedDate(check);
}

void acceptInput(dates& check) {
    int date;
    cout << "Please enter a date (dd mm yyyy): ";
    cin >> date;
    extractDate(date, check);
}

void extractDate(int date, dates& check) {
    for (int i = 0; i < 4; i++) {
        check.year += (date % 10) * pow(10, i);
        date /= 10;
    }

    for (int i = 0; i < 2; i++) {
        check.month += (date % 10) * pow(10, i);
        date /= 10;
    }

    for (int i = 0; i < 2; i++) {
        check.day += (date % 10) * pow(10, i);
        date /= 10;
    }
    checkValidity(date, check);
}

void checkValidity(int date, dates check) {
    int dayMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date > 0) {
        cout << "\tYou entered an invalid date!" << endl;
        exit(-1);
    }
    if (check.month < 1 || check.month > 12) {
        cout << "\tInvalid month: " << check.month << endl;
        exit(-1);
    }
    // special case for February in leap years
    if (isLeapYear(check.year) && check.month == 2 && (check.day > 0 && check.day < 30)) {
        return;
    }

    if (check.day < 1 || check.day > dayMonth[check.month - 1]) {
        cout << "\tInvalid day of month " << check.day << endl;
        exit(-1);
    }
}

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void printOutput(dates check) {
    if (isLeapYear(check.year)) {
        cout << '\t' << check.day << "/" << check.month << "/" << check.year
             << " is a valid date and also a Leap Year" << endl;
        cout << "Here is below the next twenty Leap years are:\n\t";
        nextTwenty(check.year);
        cout << endl;
    } else {
        cout << '\t' << check.day << "/" << check.month << "/" << check.year
             << " is a valid date but not a Leap Year" << endl;
    }
}

void nextTwenty(int year, int i) {
    if (i == 0) {
        return;
    }
    cout << year + 4 << ",";
    nextTwenty(year + 4, i - 1);
}

void saveCheckedDate(const dates& check) {
    ofstream outputFile("checked_dates.txt", ios::app);
    if (!outputFile) {
        cout << "Failed to open the file" << endl;
        return;
    }

    outputFile << check.day << "/" << check.month << "/" << check.year << endl;

    outputFile.close();
    cout << "Date saved to 'checked_dates.txt' file." << endl;
}

