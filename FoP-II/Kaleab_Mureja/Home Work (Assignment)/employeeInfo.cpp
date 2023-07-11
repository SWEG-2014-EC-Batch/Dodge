#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Employee {
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;
};

// Comparator function to sort employees by ID in ascending order
bool compareById(const Employee& emp1, const Employee& emp2) {
    return emp1.id < emp2.id;
}

void enterEmployeeInfo(vector<Employee>& employees) {
    cout << "Enter the information for 10 employees:" << endl;

    for (int i = 0; i < 10; i++) {
        Employee emp;

        cout << "Employee #" << (i + 1) << endl;
        cout << "ID No.: ";
        cin >> emp.id;
        cout << "Sex (M/F): ";
        cin >> emp.sex;
        cout << "Hourly Wage: ";
        cin >> emp.hourlyWage;
        cout << "Years with the Company: ";
        cin >> emp.yearsWithCompany;

        employees.push_back(emp);
    }
}

void writeEmployeeInfoToFile(const vector<Employee>& employees) {
    ofstream file("employee_records.txt");
    if (!file) {
        cout << "Failed to create the file." << endl;
        return;
    }

    for (const Employee& emp : employees) {
        file << emp.id << " " << emp.sex << " " << emp.hourlyWage << " " << emp.yearsWithCompany << endl;
    }

    file.close();
    cout << "Employee records have been successfully written to the file." << endl;
}

void calculateEmployeePay() {
    ifstream file("employee_records.txt");
    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    vector<Employee> employees;
    while (!file.eof()) {
        Employee emp;
        file >> emp.id >> emp.sex >> emp.hourlyWage >> emp.yearsWithCompany;

        if (file.fail()) {
            break;
        }

        employees.push_back(emp);
    }

    file.close();

    cout << "Enter the number of hours worked by each employee:" << endl;
    for (Employee& emp : employees) {
        double hoursWorked;
        cout << "Employee ID #" << emp.id << ": ";
        cin >> hoursWorked;

        double totalPay = hoursWorked * emp.hourlyWage;
        cout << "Total pay for the month: $" << totalPay << endl;
    }
}

void updateEmployeeInfo() {
    ifstream file("employee_records.txt");
    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    vector<Employee> employees;
    while (!file.eof()) {
        Employee emp;
        file >> emp.id >> emp.sex >> emp.hourlyWage >> emp.yearsWithCompany;

        if (file.fail()) {
            break;
        }

        employees.push_back(emp);
    }

    file.close();

    for (Employee& emp : employees) {
        cout << "Update information for Employee ID #" << emp.id << ":" << endl;
        cout << "Hourly Wage: ";
        cin >> emp.hourlyWage;
        cout << "Years with the Company: ";
        cin >> emp.yearsWithCompany;
    }

    ofstream updatedFile("updated_employee_records.txt");
    if (!updatedFile) {
        cout << "Failed to create the updated file." << endl;
        return;
    }

    for (const Employee& emp : employees) {
        updatedFile << emp.id << " " << emp.sex << " " << emp.hourlyWage << " " << emp.yearsWithCompany << endl;
    }

    updatedFile.close();
    cout << "Updated employee records have been written to the file." << endl;
}

int main() {
    vector<Employee> employees;

    enterEmployeeInfo(employees);

    // Sort employees by ID in ascending order
    sort(employees.begin(), employees.end(), compareById);

    writeEmployeeInfoToFile(employees);

    calculateEmployeePay();

    updateEmployeeInfo();

    return 0;
}
