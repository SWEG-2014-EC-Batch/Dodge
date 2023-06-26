#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 5;

// Function to accept user input for current values
void acceptUserInput(double current[]);

// Function to compute power values based on resistance and current
void computePower(const double resistance[], const double current[], double power[]);

// Function to display the resistance, current, and power values in a table
void displayOutput(const double resistance[], const double current[], const double power[]);

// Function to calculate the total value of an array
double calculateTotal(const double array[], int size);

int main() {
    double resistance[] = {16, 27, 39, 56, 81};
    double current[ARRAY_SIZE];
    double power[ARRAY_SIZE];

    // Accept user input for current values
    acceptUserInput(current);

    // Compute power values
    computePower(resistance, current, power);

    // Display the output table
    displayOutput(resistance, current, power);

    return 0;
}

void acceptUserInput(double current[]) {
    cout << "Enter five current values: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cin >> current[i];
    }
}

void computePower(const double resistance[], const double current[], double power[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        power[i] = resistance[i] * pow(current[i], 2);
    }
}

void displayOutput(const double resistance[], const double current[], const double power[]) {
    // Print the table header
    cout << "  Resistance   \t\tCurrent\t\t\tPower" << endl;
    cout << setprecision(2) << fixed;
    
    // Print the values in a table format
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << setw(12) << resistance[i] << "\t\t" << setw(10) << current[i] << "\t\t" << setw(10) << power[i] << endl;
    }

    cout << "--------------------------------------" << endl;

    // Calculate and print the total values
    double totalResistance = calculateTotal(resistance, ARRAY_SIZE);
    double totalCurrent = calculateTotal(current, ARRAY_SIZE);
    double totalPower = calculateTotal(power, ARRAY_SIZE);

    cout << "Total " << setw(10) << totalResistance << "\t\t" << setw(10) << totalCurrent << "\t\t" << setw(10) << totalPower << endl;
}

double calculateTotal(const double array[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += array[i];
    }
    return total;
}