#include <iostream>
using namespace std;


void inputTime(int& hours, int& minutes);

void convertTime(int hours, int minutes, int& convertedHours, char& amPm); 

void outputTime(int hours, int minutes, char amPm); 


int main() {
    char repeat;

    do {
        int hours, minutes;
        int convertedHours;
        char amPm;

        inputTime(hours, minutes);
        convertTime(hours, minutes, convertedHours, amPm);
        outputTime(convertedHours, minutes, amPm);

        cout << "Do you want to convert another time? (y/n): ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'y' || repeat == 'Y');

    cout << "Program ended. Goodbye!" << endl;

    return 0;
}

void inputTime(int& hours, int& minutes) {
    cout << "Enter time in 24-hour notation (hh:mm): ";
    cin >> hours >> minutes;
}

void convertTime(int hours, int minutes, int& convertedHours, char& amPm) {
    if (hours >= 0 && hours <= 11) {
        amPm = 'A';
        if (hours == 0)
            convertedHours = 12;
        else
            convertedHours = hours;
    } else if (hours >= 12 && hours <= 23) {
        amPm = 'P';
        if (hours == 12)
            convertedHours = 12;
        else
            convertedHours = hours - 12;
    }
}

void outputTime(int hours, int minutes, char amPm) {
    cout << "Converted time: " << hours << ":";

    if (minutes < 10)
        cout << "0";
    cout << minutes;

    if (amPm == 'A')
        cout << " AM";
    else if (amPm == 'P')
        cout << " PM";

    cout << endl;
}