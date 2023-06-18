#include <iostream>
using namespace std;

double feetToMeters(double feet) {
    return feet * 0.3048;
}

double inchesToCentimeters(double inches) {
    return inches * 2.54;
}

double metersToFeet(double meters) {
    return meters / 0.3048;
}

double centimetersToInches(double centimeters) {
    return centimeters / 2.54;
}

void convertLengths() {
    int choice;
    double length;

    cout << "Choose conversion type:" << endl;
    cout << "1. Feet and Inches to Meters and Centimeters" << endl;
    cout << "2. Meters and Centimeters to Feet and Inches" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        double feet, inches;

        cout << "Enter length in feet: ";
        cin >> feet;
        cout << "Enter length in inches: ";
        cin >> inches;

        double meters = feetToMeters(feet);
        double centimeters = inchesToCentimeters(inches);

        cout << "Length in meters: " << meters << " m" << endl;
        cout << "Length in centimeters: " << centimeters << " cm" << endl;
    } else if (choice == 2) {
        double meters, centimeters;

        cout << "Enter length in meters: ";
        cin >> meters;
        cout << "Enter length in centimeters: ";
        cin >> centimeters;

        double feet = metersToFeet(meters);
        double inches = centimetersToInches(centimeters);

        cout << "Length in feet: " << feet << " ft" << endl;
        cout << "Length in inches: " << inches << " in" << endl;
    } else {
        cout << "Invalid choice. Please try again." << endl;
        return;
    }
}

int main() {
    char repeat;

    do {
        convertLengths();

        cout << "Do you want to convert another length? (y/n): ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'y' || repeat == 'Y');

    cout << "Program ended. Goodbye!" << endl;

    return 0;
}