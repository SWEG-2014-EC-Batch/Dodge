#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const double REGULAR_HOURS = 40;
const double OVERTIME_MULTIPLIER = 1.5;

struct Employee {
    string name;
    double payRate;
    double hoursWorked;
};

void calculatePay(Employee& employee) {
    double regularPay = min(employee.hoursWorked, REGULAR_HOURS) * employee.payRate;
    double overtimePay = max(employee.hoursWorked - REGULAR_HOURS, 0.0) * OVERTIME_MULTIPLIER * employee.payRate;
    double grossPay = regularPay + overtimePay;

    cout << setw(15) << employee.name << setw(10) << employee.payRate << setw(8) << employee.hoursWorked
         << setw(13) << regularPay << setw(14) << overtimePay << setw(13) << grossPay << endl;
}

int main() {
    ifstream inputFile("employees.txt");
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    double totalRegularPay = 0;
    double totalOvertimePay = 0;
    double totalGrossPay = 0;

    cout << setw(15) << "Name" << setw(10) << "Pay Rate" << setw(8) << "Hours"
         << setw(13) << "Regular Pay" << setw(14) << "Overtime Pay" << setw(13) << "Gross Pay" << endl;

    while (!inputFile.eof()) {
        Employee employee;
        inputFile >> employee.name >> employee.payRate >> employee.hoursWorked;

        if (inputFile.fail()) {
            break;
        }

        calculatePay(employee);

        totalRegularPay += min(employee.hoursWorked, REGULAR_HOURS) * employee.payRate;
        totalOvertimePay += max(employee.hoursWorked - REGULAR_HOURS, 0.0) * OVERTIME_MULTIPLIER * employee.payRate;
        totalGrossPay += employee.payRate * employee.hoursWorked;
    }

    cout << endl;
    cout << "Total Regular Pay: $" << totalRegularPay << endl;
    cout << "Total Overtime Pay: $" << totalOvertimePay << endl;
    cout << "Total Gross Pay: $" << totalGrossPay << endl;

    inputFile.close();
    return 0;
}
