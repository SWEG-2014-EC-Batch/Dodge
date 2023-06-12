#include <iostream>
using namespace std;

int main() {
  float incomeTaxRate, overtimeRate, workedHours, grossSalary;
  cout << "Enter your gross salary: ";
  cin >> grossSalary;

  cout << "Enter your worked hours: ";
  cin >> workedHours;

  cout << "Enter your income tax in percentage: ";
  cin >> incomeTaxRate;

	int difference = grossSalary * (incomeTaxRate / 100);
	difference += grossSalary * 0.07;
	grossSalary -= difference;

  if (workedHours > 40) {
    cout << "Enter over time bonus rate per hour: ";
    cin >> overtimeRate;
		int bonus = (workedHours - 40) * overtimeRate;
    grossSalary += bonus;
  }

  cout << "You net salary is: " << grossSalary << endl;
  return 0;
}
