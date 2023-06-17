#include <iostream>
using namespace std;

int input();

void FeetToMeters()
{
    double feet;
    cout << "enter feet length: ";
    cin >> feet;
    cout << "length in meters= " << feet * 0.3048 << "\nlength in centimeters= " << feet * 30.48 << endl;
    input();
}

void MetersToFeet()
{
    double meters;
    cout << "enter meters length: ";
    cin >> meters;
    cout << "length in feet= " << meters / 0.3048 << "\nlength in inch= " << meters * 39.37 << endl;
    input();
}
void InchesToCm()
{
    double inches;
    cout << "Enter length in inches: ";
    cin >> inches;
    cout << "Length in centimeters: " << inches * 2.54 << "\n";
    input();
}

void CmToInches()
{
    double centimeters;
    cout << "Enter length in centimeters: ";
    cin >> centimeters;
    cout << "Length in inches: " << centimeters / 2.54 << " inches\n";
    input();
}

int main()
{
    input();
}

int input()
{
    int choice;
    cout << "\nSelect conversion type:\n";
    cout << "1. Feet to meters and centimeters\n";
    cout << "2. Meters to feet and inches\n";
    cout << "3. Inches to centimeters\n";
    cout << "4. Centimeters to inches\n";
    cout << "0. Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        FeetToMeters();
        break;
    case 2:
        MetersToFeet();
        break;
    case 3:
        InchesToCm();
        break;
    case 4:
        CmToInches();
        break;
    case 0:
        cout << "Exiting the program.\n";
        return 0;
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
}
